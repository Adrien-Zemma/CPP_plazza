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
#include "plazza.hpp"
#include "transport.hpp"

class Process : public Plazza {
public:
	Process(std::string sockerName);
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
	void	communication_support();
	static void	getRegex(toTransfert &data);
	pid_t	_pid;
	bool	_exit_status;

	clock_t	_start;
	clock_t	_end;
	Transport	_input;
	Transport	_output;
	size_t	_availableThread;
	std::thread	order_thrd;
	std::thread	communication_thrd;
	std::vector<std::pair<std::string, std::string>>	_queu;
	std::vector<std::pair<std::thread, toTransfert>> _threads;
};

#endif /* !PROCESS_HPP_ */
