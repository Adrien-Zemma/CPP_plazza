/*
** EPITECH PROJECT, 2018
** Plazza
** File description:
** Parse header file
*/

#ifndef PARSE_HPP_
	#define PARSE_HPP_

#include "plazza.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class Parse {
	public:
		Parse(std::shared_ptr<std::map<std::string, std::string>> regexList, std::shared_ptr<std::vector<std::pair<std::string, std::string>>> queue);
		~Parse();
		int read();
	private:
		std::shared_ptr<std::map<std::string, std::string>>	_regexList;
		std::shared_ptr<std::vector<std::pair<std::string, std::string>>> _queu;
		void manage_commands(std::string line);
		std::vector<std::string>	split_commands(std::string line);
		std::string	split(std::string line, char c, int nb);

};
#endif /* !PARSE_HPP_ */