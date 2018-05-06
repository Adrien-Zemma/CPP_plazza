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

/*
	lire sur input
	ecrire sur output
*/


class Plazza {
public:
	Plazza(char *str); 
	~Plazza();
	int start();
	void	manager();
	class DataProc {
	public:
		DataProc(std::string name, size_t threadMax);
		std::string	_name;
		Process		_slave;
		Transport	_input;
		Transport	_output;
		size_t		_infos;
	};
	std::vector<std::string>	getResult(); // file result
	std::shared_ptr<std::map<std::string, std::string>>	getRegexList();
	std::shared_ptr<std::vector<std::pair<std::string, std::string>>> getQueu();

private:
	void	update();
	void	sendToProcess();
	void	buildNewProcess();
	std::vector<std::string>	getInfoProcess();
	std::vector<std::string>	cutString(std::string str);
	void	updateData(size_t nb, std::string info);
	size_t	_threadMax;
	bool	_exit_status;
	std::vector<std::unique_ptr<DataProc>> _info;
	std::shared_ptr<std::vector<std::string>> _result;
	std::shared_ptr<std::map<std::string, std::string>>	_regexList; //first name, second regex
	std::shared_ptr<std::vector<std::pair<std::string, std::string>>> _queu;
};

#include "process.hpp"

#endif /* !PLAZZA_HPP_ */
