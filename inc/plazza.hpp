/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Plazza
*/

/*!
 * @brief 
 * 	header of the Plazza Class
 * 
 * @file plazza.hpp
 * 
 */

#ifndef PLAZZA_HPP_
	#define PLAZZA_HPP_

#include <iostream>
#include <cstdlib>
#include <vector>
#include <memory>
#include <ctime>
#include <map>

class Process;
class Transport;

class Plazza {
	public:
		Plazza();
		Plazza(char *str); 
		~Plazza();
		int start();
	protected:
		std::shared_ptr<std::map<std::string, std::string>>	_regexList; //first name, second regex
		size_t	_threadMax;
	private:
		void	update();
		void	manager();
		bool	_exit_status;
		std::shared_ptr<std::vector<std::pair<std::string, std::string>>> _queu;
		std::vector<std::map<std::string, std::string>> _tabData;
		std::vector<std::pair<Transport, Transport>> _tabSocket;
		std::vector<Process>	_tabProcesses;

};

#include "process.hpp"

#endif /* !PLAZZA_HPP_ */
