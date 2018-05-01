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
	_pid = fork();
	Transport _input(socketName);
	Transport _output(socketName + "R");
}

Process::~Process()
{}

Process::toTransfert::toTransfert()
{
	ptr = std::make_shared<bool>(false);
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
		_queu.push_back({key, value});	
	}
}

void	Process::createNewTask()
{
	_start = clock();
	_end = _start + (CLOCKS_PER_SEC * 5);

	if (_threads.size() < _threadMax)
	{
		_threads.end()->second = toTransfert();
		auto tmp = _threads.end()->second;
		_threads.end()->first = std::thread(&Process::getRegex, std::ref(_threads.end()->second));
	}
}

void	Process::checkThread()
{
	for (size_t i = 0; i < _threads.size(); i++){
		if (*_threads.at(i).second.ptr.get() == true)
		{
			_threads.erase(_threads.begin() + i);
			checkThread();
		}
	}
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
		if (_queu.size() > 0)
			createNewTask();
		checkThread();
	}
}

void	Process::newTask(std::pair<std::string, std::string> order)
{
	order = order;
}

void    Process::getRegex(toTransfert &data)
{
	std::regex	toFind(data.request);
	std::string	lines;
	std::string	tmp;
	std::smatch	m;
	std::ifstream myfile	(data.file);
	if (!myfile)
		return ;
	while (getline(myfile, tmp))
		lines += tmp;
	myfile.close();
	while (std::regex_search (lines, m, toFind)) {
		data.flux << m[0];
        	lines = m.suffix().str();
	}
	std::this_thread::yield();
}