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
	std::cerr<< "process\tbuild\t" << socketName << "\t" << std::endl;
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
	std::cerr<< "process\t" << _sockerName << "\t" << "send info\t"<< nb << std::endl;
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
		std::cout << "ce truc c'est le read du process" << std::endl;
		tmp << _input;
		std::cout << "la on est apres le read" << std::endl;
		auto tab = cutString(tmp);
		std::cout << tab[0] + "|"+tab[1] + "|"+tab[2] + "|" << std::endl;
		if (tab[0] == "update")
		{
			std::cout << 4 << std::endl;
			sendInformation();

		}
		if (tab[0] == "queu")
		{
			std::cerr<< "process\t" << _sockerName << "\t" << "queu recive\t"<< tmp << std::endl;
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