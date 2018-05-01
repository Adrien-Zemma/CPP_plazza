/*
** EPITECH PROJECT, 2018
** Plazza
** File description:
** Main cpp file
*/

#include "plazza.hpp"
#include "parse.hpp"

Plazza::Plazza()
{}

Plazza::~Plazza()
{}

Plazza::Plazza(char *str)
{
	_threadMax = atoi(str);
	_regexList = std::make_shared<std::map<std::string, std::string>>();
	_queu = std::make_shared<std::vector<std::pair<std::string, std::string>>>();
	_regexList.get()->insert({"EMAIL","adrien.zemma@epitech.eu"});
	_regexList.get()->insert({"PHONE","0647005996"});
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
	while(1)
	{
		Parse tmp (_regexList, _queu);
		tmp.read();
	}
	return 0;
}

