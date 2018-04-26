/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** process
*/

#ifndef PROCESS_HPP_
	#define PROCESS_HPP_

#include "plazza.hpp"
#include <thread>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <regex>
#include <fstream>


class Process : private Plazza {
	public:
		Process();
		~Process();
		void	start();
		void	newTask(std::pair<std::string, Information> order);
		//TODO: communication by Transport Class
	private:
		size_t	getPid();
		void	checkThread();
		void	createNewTask();
		void	order_support();
		void	communication_support();
		void	getRegex(std::string file, std::string regex, std::unique_ptr<bool> ptr);
		pid_t	_pid;
		bool	_exit_status;
		Transport	input;
		Transport	output;
		size_t	_availableThread;
		std::thread	order_thrd;
		std::thread	communication_thrd;
		std::vector<std::pair<std::string, std::string>>	_queu;
		std::vector<std::pair<std::thread, std::shared_ptr<bool>>> _threads;
};
#endif /* !PROCESS_HPP_ */

