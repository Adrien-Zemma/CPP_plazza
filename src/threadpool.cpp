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
	_exit = false;
	for (size_t i = 0; i < nb; i++)
		_threadStatus.push_back(true);
	for (size_t i = 0; i < nb; i++)
		_threads.push_back(std::thread([this](size_t i){threadWork(i);}, i));
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
	auto test = getFirstQueu();
	setID(id, false);
	std::regex	toFind(test.first);
	std::string	file = test.second;
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

void	Threadpool::pushResult(std::string tmp)
{
	_lockResult.lock();
	_result.push_back(tmp);
	_lockResult.unlock();
}

std::pair<std::string, std::string>	Threadpool::getFirstQueu()
{
	std::pair<std::string, std::string>tmp = *_queu.begin();
	_queu.erase(_queu.begin());
	_lockQueu.unlock();
	return tmp;
}

bool	Threadpool::getExit()
{
	_lockExit.lock();
	auto exitStatus = _exit;
	_lockExit.unlock();
	return exitStatus;
}

void	Threadpool::threadWork(size_t nb)
{
	size_t	id = nb;
	bool	exitStatus = false;
	while(1)
	{
		setID(id, true);
		exitStatus = getExit();
		if (_lockQueu.try_lock())
		{
			if (_queu.size() > 0)
			{
				pushResult(getRegex(id));
			}
			else
			{
				_lockQueu.unlock();
			}
		}
		if (exitStatus)
			return ;
	}
}