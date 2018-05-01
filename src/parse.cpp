/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Parse class
*/

#include "parse.hpp"

Parse::Parse()
 : Plazza()
{
}

Parse::~Parse()
{}

int	Parse::read()
{
	std::string line;

	for (std::string line; std::getline(std::cin, line);) {
		std::cout << line << std::endl;
    	}
	return 0;
}

void	Parse::addEmail(std::string file)
{

}
void	Parse::addPhone(std::string file)
{

}
void	Parse::addIP(std::string file)
{

}