/*
** EPITECH PROJECT, 2018
** Plazza
** File description:
** Plazza
*/

#include "Plazza.hpp"

Plazza::Plazza(int threadMax)
{
	_continu = true;
	this->_threadMax = threadMax;
	_tv.tv_sec = 10;
	_tv.tv_usec = 0;
	_regexList.insert({"IP", "(\\d{1,3}(\\.\\d{1,3}){3})"});
	_regexList.insert({"EMAIL", "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"});
	_regexList.insert({"PHONE", "0[0-9]( ?[0-9]{2}){4}"});
}

void	Plazza::start()
{
	std::string txt;

	while(_continu)
	{
		std::getline(std::cin, txt);
		manageQueu(txt);
		manageFork();
	}
}

void	Plazza::manageFork()
{
	std::string cmd;
	while (_queu.size() > 0)
	{
		if (_queu.size() > 0)
		{
			cmd = _queu[0];
			_queu.erase(_queu.begin());
			lunchFork(cmd);
		}
	}
}

std::pair<std::string, std::string> cutString(std::string cmd)
{
	int x = 0;
	std::pair<std::string, std::string> tmp;
	for (auto el: cmd)
	{
		if (el == ' ')
			break;
		x++;
		tmp.first += el;
	}
	cmd.erase(cmd.begin(), cmd.begin() + (x +1));
	for(auto el: cmd)
	{
		tmp.second += el;
	}
	return tmp;
}

void	Plazza::runThreadPool(std::string cmd)
{
	auto data = cutString(cmd);
	Threadpool pool(data.first, _regexList[data.second], _threadMax);
	auto tmp = pool.getResult();
	for (auto el: tmp)
		std::cout << el << std::endl;
}

void	Plazza::lunchFork(std::string cmd)
{
	if (fork() == 0)
	{
		runThreadPool(cmd);
		exit(0);
	}
}

void	Plazza::printResult()
{
	while(_resultList.size() > 0)
	{
		std::cout << _resultList[0] << std::endl;
		_queu.erase(_resultList.begin());
	}	
}

void	Plazza::setFd(fd_set *rfds)
{
	FD_SET(0, rfds);
	for(auto el : _fdList)
	{
		FD_SET(el, rfds);
	}
}

std::vector<std::string>	Plazza::cutSemiColon(std::string cmd)
{
	std::string txt;
	std::vector<std::string> tmp;
	for(auto el: cmd)
	{
		if (el == ';')
		{
			tmp.push_back(txt);
			txt.clear();
		}
		else
			txt += el;
	}
	tmp.push_back(txt);
	return tmp;
}

void	Plazza::manageQueu(std::string cmd)
{
	_queu.push_back(cmd);
}