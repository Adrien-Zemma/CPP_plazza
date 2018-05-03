/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** process
*/

#ifndef PROCESS_HPP_
	#define PROCESS_HPP_

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fstream>
#include <thread>
#include <regex>
#include <map>
#include "plazza.hpp"
#include "transport.hpp"

class Process {
public:
	Process(std::string sockerName);
	Process(const Process &other);
	Process	&operator=(const Process &other);
	~Process();
	void	start();
	void	newTask(std::pair<std::string, std::string> order);
	class	toTransfert{
	public:
		toTransfert();
		~toTransfert();
		Transport	flux;
		std::string	file;
		std::string	request;
		std::shared_ptr<bool>	ptr;
		std::vector<std::string>	result;
	};

private:
	size_t	getPid();
	void	checkThread();
	void	createNewTask();
	void	order_support();
	void	buildNewProcess();
	void	communication_support();
	static void	getRegex(toTransfert &data);
	clock_t	_end;
	pid_t	_pid;
	clock_t	_start;
	size_t	_threadMax;
	bool	_exit_status;
	Transport	_input;
	Transport	_output;
	size_t	_availableThread;
	std::thread	order_thrd;
	std::thread	communication_thrd;
	std::vector<std::pair<std::thread, toTransfert>> _threads;
	std::vector<std::pair<std::string, std::string>>	_queu;
};

#endif /* !PROCESS_HPP_ */
