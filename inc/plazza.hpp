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
#include "transport.hpp"
#include "process.hpp"
#include <sstream>

class Plazza {
public:
	Plazza(char *str); 
	~Plazza();
	int start();
	class data_t {
	public:
		data_t();
		std::string	_name;
		Transport	_input;
		Transport	_output;
		Process		_slave;
		std::map<std::string, std::string>	_infos;
	};
private:
	void	update();
	void	manager();
	void	sendToProcess();
	void	buildNewProcess();
	void	updateData(size_t nb, std::map<std::string, std::string> dataMap);
	size_t	_threadMax;
	bool	_exit_status;
	std::vector<Plazza::data_t> _info;
	std::shared_ptr<std::vector<std::string>> _result;
	std::shared_ptr<std::map<std::string, std::string>>	_regexList; //first name, second regex
	std::shared_ptr<std::vector<std::pair<std::string, std::string>>> _queu;
};

#include "process.hpp"

#endif /* !PLAZZA_HPP_ */
