/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** process
*/

#include "process.hpp"

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
		Transport _output(socketName);
		Transport _input(socketName + "1", 2);
		start();
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

std::vector<std::string>	Process::cutString(std::string str)
{
	std::vector<std::string> tmp;
	std::string line = "";
	size_t nb = 0;
	for(nb = 0; str[nb] != ':' && nb < str.size(); nb++)
		line += str[nb];
	tmp.push_back(line);
	line.clear();
	nb++;
	for (; str[nb] != ',' && nb < str.size(); nb++)
		line += str[nb];
	tmp.push_back(line);
	line.clear();
	nb++;
	for (; str[nb] != '\n' && nb < str.size(); nb++)
		line += str[nb];
	tmp.push_back(line);
	return tmp;
}

void	Process::updateQueu()
{
	std::string	tmp = "C";
	do {
		tmp << _input;
		auto tab = cutString(tmp);
		if (tab[0] == "update")
		{
			sendInformation();

		}
		if (tab[0] == "queu")
		{
			_queu.push_back({tab[1], tab[2]});
		}
	} while (tmp != "");
}

void	Process::start()
{
	_start = clock();
	_end = _start + (CLOCKS_PER_SEC * 5);

	while(clock() <= _end)
	{
		updateQueu();
		for (auto el: _queu)
		{
			_pool.addCommande(el);
		}
		_queu.clear();
		sendResult();
	}
	exit(0);
}