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
	_regexList.insert({"IP_ADDRESS", "(\\d{1,3}(\\.\\d{1,3}){3})"});
	_regexList.insert({"EMAIL_ADDRESS", "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"});
	_regexList.insert({"PHONE_NUMBER", "0[0-9]( ?[0-9]{2}){4}"});
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

std::string	Plazza::clearLine(std::string line)
{
	while(line[0] == ' ')
		line.erase(line.begin());
	return line;
}

std::vector<std::string> Plazza::split_commands(std::string command)
{
	std::vector<std::string> ne;
	std::string line;

	for (int i = 0; command[i]; i++) {
		if (command[i] == ';') {
			line = clearLine(line);
			ne.push_back(line);
			line.clear();
		}
		else
			line.push_back(command[i]);
	}
	line = clearLine(line);
	ne.push_back(line);
	return ne;
}

void	Plazza::manageQueu(std::string cmd)
{
	auto tmp = split_commands(cmd);
	for (auto el : tmp)
		_queu.push_back(el);
}