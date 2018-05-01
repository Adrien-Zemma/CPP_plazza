/*
** EPITECH PROJECT, 2018
** Plazza
** File description:
** Main cpp file
*/

#include "plazza.hpp"

Plazza::Plazza()
{}

Plazza::~Plazza()
{}

Plazza::Plazza(char *str)
{
	str = str;
}

void	Plazza::manager()
{
}

void	Plazza::update()
{
	size_t	nb = 0;
	std::map<std::string, std::string> dataMap;
	for (auto it: _tabSocket)
	{
		it.first << "update";
		dataMap << it.second;
		for (auto el : dataMap)
			_tabData[nb].at(el.first) = el.second;
		nb++;
	}
}

int	Plazza::start()
{
	return 0;
}

