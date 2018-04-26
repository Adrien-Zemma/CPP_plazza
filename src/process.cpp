/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** process
*/

#include "process.hpp"

Process::Process()
{
	_pid = 0;
	_exit_status = false;
	_pid = fork();
	//TODO: init communication
}

size_t	Process::getPid()
{
	return _pid;
}

void	Process::communication_support()
{
	while(_exit_status)
	{
		/*
		**TODO:
		*/
	}
}

void	Process::createNewTask()
{
	if (_threads.size < _threadMax)
	{
		auto tmp = std::make_shared<bool>(false);
		_threads.end()->first = std::thread(getRegex, _queu.begin()->first, _queu.begin()->first, tmp);
		_threads.end()->second = tmp;
	}
}

void	Process::checkThread()
{
	for (size_t i = 0; i < _threads.size(); i++){
		if (*_threads.at(i).second.get() == true)
		{
			_threads.erase(_threads.begin() + i);
			checkThread();
		}
	}
}

void	Process::order_support()
{
	while(_exit_status)
	{
		if (_queu.size > 0)
			createNewTask();
		checkThread();
	}
}

void	Process::start()
{
	communication_thrd = std::thread(Process::communication_support);
	order_thrd = std::thread(Process::order_support);
	communication_thrd.join();
	order_thrd.join();
}

void	Process::newTask(std::pair<std::string, Information> order)
{
}