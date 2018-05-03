/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** process
*/

#include "../inc/process.hpp"

Process::Process(std::string socketName, size_t threadMax)
	:_pool(threadMax)
{
	_threadMax = threadMax;
	_pid = 0;
	_exit_status = false;
	_sockerName = socketName;
	_pid = fork();
	if (_pid == 0)
	{
		Transport _input("." + socketName);
		Transport _output("." + socketName + "R");
	}
}

Process::~Process()
{}

size_t	Process::getPid()
{
	return _pid;
}

void	Process::sendResult()
{
	auto tab = _pool.getResult();
	if (tab.size() > 0)
	{
		_start = clock();
		_end = _start + (CLOCKS_PER_SEC * 5);
		std::string tmp;
		tmp = "result:";
		for (auto el: tab)
			tmp += el + "\n";
		_output << tmp;

	}
}

void	Process::sendInformation()
{
	auto nb = _pool.getInfo();
	std::string tmp = "info:";
	tmp += _sockerName + "," + std::to_string(nb) + "\n";
	_output << tmp;
}

void	Process::start()
{
	_start = clock();
	_end = _start + (CLOCKS_PER_SEC * 5);

	while(clock() <= _end)
	{
		for (auto el: _queu)
		{
			_pool.addCommande(el);
		}
		_queu.clear();
		sendResult();
		sendInformation();
	}
	exit(0);
}