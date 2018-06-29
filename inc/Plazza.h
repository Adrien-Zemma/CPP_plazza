/*
** EPITECH PROJECT, 2018
** Plazza
** File description:
** Plazza
*/

#include <vector>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <iostream>
#include <sys/time.h>
#include <sys/types.h>
#include "Threadpool.hpp"

class Plazza
{
public:
	Plazza(int threadMax);
	void start();
private:
	bool _continu;
	int _threadMax;
	struct timeval _tv;
	std::vector<int> _fdList;
	std::vector<std::string> _queu;
	std::vector<std::string> _resultList;
	
	void	manageFork();
	void	printResult();
	void	setFd(fd_set *rfds);
	void	readInMessage(int fd);
	void	manageFd(fd_set *rfds);
	void	lunchFork(std::string cmd);
	void	manageQueu(std::string cmd);
	void	checkInMessage(fd_set *rfds);
	void	runThreadPool(std::string cmd);
};
