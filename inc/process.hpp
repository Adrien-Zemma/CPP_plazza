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
#include "transport.hpp"
#include "threadpool.hpp"

class Process {
public:
	Process(std::string sockerName, size_t threadMax, int thisPid);
	~Process();
	void	start();
	void	newTask(std::pair<std::string, std::string> order);
	size_t	getPid();

private:

	void	updateQueu();
	void	sendResult();
	void	checkThread();
	void	createNewTask();
	void	order_support();
	void	buildNewProcess();
	void	sendInformation();
	std::vector<std::string>	cutString(std::string str);
	clock_t	_end;
	pid_t	_pid;
	clock_t	_start;
	size_t	_threadMax;
	bool	_exit_status;
	std::string _sockerName;
	Threadpool	_pool;
	Transport	_output;
	std::vector<std::pair<std::string, std::string>>	_queu;
	std::vector<std::string> _result; //file, result
	
};

#endif /* !PROCESS_HPP_ */
