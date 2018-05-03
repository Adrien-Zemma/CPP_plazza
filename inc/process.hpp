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
#include <memory>
#include <regex>
#include <map>
#include "plazza.hpp"
#include "transport.hpp"
#include "threadpool.hpp"

class Process {
public:
	Process();
	Process(std::string sockerName);
	Process(const Process &other);
	Process	&operator=(const Process &other);
	~Process();
	void	start();
	void	newTask(std::pair<std::string, std::string> order);
	class toTransfert{
	public:
		toTransfert();
		~toTransfert();
		Transport	flux;
		std::string	file;
		std::string	request;
		std::shared_ptr<bool>	ptr;
	};

private:
	size_t	getPid();
	void	sendResult();
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
	Threadpool	_pool;
	Transport	_input;
	Transport	_output;
	std::shared_ptr<std::vector<std::pair<std::string, std::string>>>	_queu;
	std::shared_ptr<std::vector<std::pair<std::pair<std::string, std::string>, std::string>>> _result //file, regex, result
	
};

#endif /* !PROCESS_HPP_ */
