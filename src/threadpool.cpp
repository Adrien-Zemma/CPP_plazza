/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** threadpool
*/

#include "threadpool.hpp"
#include <regex>
#include <fstream>


Threadpool::Threadpool(size_t nb)
{
	_threadMax = nb;
	for (size_t i; i < nb; i++)
		_threadStatus.push_back(true);
	for (size_t i; i < nb; i++)
		_threads.push_back(std::thread([this](size_t i){couille(i);}, i));
}

Threadpool::~Threadpool()
{
	_exit = true;
	for (size_t i; i < _threadMax; i++)
		_threads[i].join();
}

void	Threadpool::addCommande(std::pair<std::string, std::string> order)
{
	_lockQueu.lock();
	_queu.push_back(order);
	_lockQueu.unlock();
}

std::vector <std::string> Threadpool::getResult()
{
	std::vector <std::string> tmp;
	_lockResult.lock();
	tmp = _result;
	_lockResult.unlock();
	return tmp;
}

size_t	Threadpool::getInfo()
{
	int nb = 0;
	_lockInfo.lock();
	for (auto el: _threadStatus)
		if (el == true)
			nb++;
	_lockInfo.unlock();
	return nb;
}

std::string	Threadpool::getRegex(size_t id)
{
	setID(id, false);
	std::regex	toFind(_queu.begin()->second);
	std::string	file = _queu.begin()->first;
	_queu.erase(_queu.begin());
	_lockQueu.unlock();
	std::string	returnValue;
	std::string	lines;
	std::string	tmp;
	std::smatch	m;
	std::ifstream myfile	(file);
	if (!myfile)
		return "";
	while (getline(myfile, tmp))
		lines += tmp;
	myfile.close();
	while (std::regex_search (lines, m, toFind)) {
		returnValue += ( file + "," + std::string(m[0]));
        	lines = m.suffix().str();
	}
	return returnValue;
}

void	Threadpool::setID(size_t id, bool data)
{
	_lockInfo.lock();
	_threadStatus[id] = data;
	_lockInfo.unlock();
}

void	Threadpool::couille(size_t nb)
{
	size_t	id = nb;
	bool	exitStatus = false;
	while(1)
	{
		setID(id, true);
		_lockExit.lock();
		exitStatus = _exit;
		_lockExit.unlock();
		if (_lockQueu.try_lock())
		{
			auto tmp = getRegex(id);
			_lockResult.lock();
			_result.push_back(tmp);
			_lockResult.unlock();
		}
		if (exitStatus)
			return ;
	}
}