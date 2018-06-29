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
	_tv.tv_sec = 1;
	_tv.tv_usec = 0;
	_regexList.insert({"EMAIL", "([a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+)"});
}

void	Plazza::start()
{
	int retval;
	fd_set rfds;

	while(_continu)
	{
		FD_ZERO(&rfds);
		setFd(&rfds);
		retval = select(1, &rfds, NULL, NULL, &_tv);
		if (retval == -1)
			_continu = false;
		manageFd(&rfds);
		printResult();
		manageFork();
	}
	printResult();
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
	cmd.erase(cmd.begin(), cmd.begin() + x);
	for(auto el: cmd)
	{
		tmp.second += el;
	}
	return tmp;
}

void	Plazza::runThreadPool(std::string cmd)
{
	auto data = cutString(cmd);
	data.second = _regexList[data.second];
	Threadpool pool(data.first, data.second, _threadMax);
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

void	Plazza::manageFd(fd_set *rfds)
{
	std::string txt;

	if (FD_ISSET(0, rfds))
	{
		std::getline(std::cin, txt);
		manageQueu(txt);
	}
	else
	{
		checkInMessage(rfds);
	}
}

void	Plazza::readInMessage(int fd)
{
	int ret;
	char buff[2];
	std::string txt;

	do{
		ret = read(fd, buff, 1);
		if (buff[0] == '\n')
		{
			_resultList.push_back(txt);
			txt.clear();
		}
		else
			txt += buff[0];
	}while(ret != 0);
}

void	Plazza::checkInMessage(fd_set *rfds)
{
	for(auto el : _fdList)
	{
		if (FD_ISSET(el, rfds))
		{
			readInMessage(el);
		}
	}
}

void	Plazza::manageQueu(std::string cmd)
{
	_queu.push_back(cmd);

}