/*
** EPITECH PROJECT, 2018
** Plazza
** File description:
** Main cpp file
*/

#include "plazza.hpp"
#include "parse.hpp"

Plazza::~Plazza()
{}

Plazza::Plazza(char *str)
{
	std::srand(std::time(nullptr));
	_exit_status = true;
	_threadMax = atoi(str);
	_regexList = std::make_shared<std::map<std::string, std::string>>();
	_queu = std::make_shared<std::vector<std::pair<std::string, std::string>>>();
	_regexList.get()->insert({"EMAIL","(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"});
	_regexList.get()->insert({"PHONE","^(?:(?:\+|00)33|0)\s*[1-9](?:[\s.-]*\d{2}){4}$"});
	_regexList.get()->insert({"IP", "^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$"});
}

Plazza::data_t::data_t()
{
	_name = std::rand() % 1000;
	_slave = Process(_name);
	_input = Transport("." + _name);
	_output = Transport("." + _name + "R");
}

void	Plazza::buildNewProcess()
{

	_info.push_back(data_t());
}

std::shared_ptr<std::map<std::string, std::string>>	Plazza::getRegexList()
{
	return _regexList;
}

void	Plazza::sendToProcess()
{
	size_t i = -1;
	size_t	target;
	std::string	tmp;

	for(size_t nb = 0; nb < _info.size(); nb++)
	{
		target = stoi(_info[i]._infos["threadLeft"]);
		for (size_t el = 0; el < target; el++)
		{
			tmp += _queu.get()->begin()->first + "|" + _queu.get()->begin()->second;
			_queu.get()->erase(_queu.get()->begin());
		}
		if (tmp.size())
			_info[nb]._output << ("queu:" + tmp);
	}
}

void	Plazza::manager()
{
	for (size_t i = 0; i < _queu.get()->size(); i++)
	{
		if (_queu.get()->size > 0)
			buildNewProcess();
		sendToProcess();
		update();
	}
}

void	Plazza::updateData(size_t nb, std::map<std::string, std::string> dataMap)
{
	for (auto el: dataMap)
	{
		if (_info[nb]._infos.find(el.first) != _info[nb]._infos.end())
			_info[nb]._infos.at(el.first) = el.second;
		else
			_info[nb]._infos.insert(el);
	}
}

void	Plazza::update()
{
	size_t	nb = 0;
	std::map<std::string, std::string> dataMap;
	for (; nb < _info.size(); nb++)
	{
		_info[nb]._input << "update: ";
		dataMap << _info[nb]._output;
		updateData(nb, dataMap);
	}
}

int	Plazza::start()
{
	Parse tmp (_regexList, _queu);
	while(_exit_status)
	{
		tmp.read();
		update();
		manager();
	}
	return 0;
}

