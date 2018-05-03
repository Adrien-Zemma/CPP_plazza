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
	std::srand(std::time(nullptr));
	_exit_status = true;
	_threadMax = atoi(str);
	_regexList = std::make_shared<std::map<std::string,
	std::string>>();
	_queu = std::make_shared<std::vector<std::pair<std::string,
	std::string>>>();
	_regexList.get()->insert({"EMAIL","(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w
	+))+"});
	_regexList.get()->insert({"PHONE","^(?:(?:\+|00)33|0)\s*[1-9](?:[\s.-]
	*\d{2}){4}$"});
	_regexList.get()->insert({"IP", "^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]
	?)\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$"})
}

void	Plazza::buildNewProcess()
{
	std::string name(rand()%1000);
	_tabProcesses.push_back(Process());
	_tabSocket.push_back({Transport("." + name), Transport("." + name + "R")})
}

void	sendToProcess()
{
	size_t i = -1;
	size_t	target;
	std::string	tmp;
	for (auto it: _tabProcesses)
	{
		i++;
		target = stoi(_tabData[i]["threadLeft"])
		for (size_t nb = 0; nb < target; nb++)
		{
			tmp += _queu.begin().first + "|" + _queu.begin().second;
			_queu.erase(_queu.begin());
		}
		if (tmp.size())
			_tabSocket[i] << "queu:" + tmp;
	}
}

void	Plazza::manager()
{
	for(auto it: _queu)
	{
		update();
		if (_tabProcesses.size() == 0)
			buildNewProcess();
		sendToProcess();
	}
}

void	Plazza::update()
{
	size_t	nb = 0;
	std::map<std::string, std::string> dataMap;
	for (auto it: _tabSocket)
	{
		it.second << "update";
		dataMap << it.first;
		for (auto el : dataMap)
			_tabData[nb].at(el.first) = el.second;
		nb++;
	}
}

int	Plazza::start()
{
	Parse tmp (_regexList, _queu);
	while(_exit_status)
	{
		tmp.read();
		manage();
	}
	return 0;
}

