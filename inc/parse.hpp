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

class Parse : public Plazza {
	public:
		Parse();
		~Parse();

		int read();
		void addEmail(std::string file);
		void addPhone(std::string file);
		void addIP(std::string file);
	private:
		void manage_commands(std::string line);
		std::vector<std::string>	split_commands(std::string line);
		std::string	split(std::string line, char c, int nb);

};
#endif /* !PARSE_HPP_ */
