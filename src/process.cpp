/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** process
*/

#include "../inc/process.hpp"

Process::Process(std::string socketName)
{
	_pid = 0;
	_exit_status = false;
	_queu = std::make_shared<std::vector<std::pair<std::string, std::string>>>();
	_pid = fork();
	if (_pid == 0)
	{
		Transport _input("." + socketName);
		Transport _output("." + socketName + "R");
		_pool.setQueu(_queu);
	}
}

Process::Process(const Process &other)
{
	*this = other;
}

Process	&Process::operator=(const Process &other)
{
	_end = other._end;
	_pid = other._pid;
	_start = other._start;
	_threadMax = other._threadMax;
	_exit_status = other._exit_status;
	_input = other._input;
	_output = other._output;
	_pool = other._pool;
	_queu = other._queu;
	return *this;
}

Process::~Process()
{}

Process::toTransfert::toTransfert()
{
	result = std::make_shared<std::vector<std::string>>();
}

Process::toTransfert::~toTransfert()
{}

size_t	Process::getPid()
{
	return _pid;
}

void	Process::communication_support()
{
	std::map<std::string, std::string> map;
	_input >> map;
	auto tmp = map["queu"];
	std::string key;
	std::string value;
	for(size_t i = 0; i < tmp.size(); i++)
	{
		for (; tmp[i] != '|'; i++)
			key.push_back(tmp[i]);
		i++;
		for (; tmp[i] != ',' && tmp[i] != '\n'; i++)
			value.push_back(tmp[i]);
		_queu.get()->push_back({key, value});	
	}
}

void	Process::createNewTask()
{
	_start = clock();
	_end = _start + (CLOCKS_PER_SEC * 5);
}

void	Process::order_support()
{}

void	Process::start()
{
	_start = clock();
	_end = _start + (CLOCKS_PER_SEC * 5);

	while(clock() <= _end)
	{
		communication_support();
		if (_queu.get()->size() > 0)
		{
			_pool.work();
		}
	}
	exit(0);
}