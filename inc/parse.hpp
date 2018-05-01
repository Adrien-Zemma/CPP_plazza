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

class Parse : public Plazza {
	public:
		Parse();
		~Parse();

		int read();
		void addEmail(std::string file);
		void addPhone(std::string file);
		void addIP(std::string file);
	private:

};
#endif /* !PARSE_HPP_ */
