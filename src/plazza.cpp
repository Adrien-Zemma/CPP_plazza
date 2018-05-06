/*
** EPITECH PROJECT, 2018
** Plazza
** File description:
** Main cpp file
*/

#include "plazza.hpp"
#include "parse.hpp"
#include <stdio.h>

Plazza::Plazza(char *str)
{
	std::srand(std::time(nullptr));
	_exit_status = true;
	_threadMax = atoi(str);
	_regexList = std::make_shared<std::map<std::string, std::string>>();
	_queu = std::make_shared<std::vector<std::pair<std::string, std::string>>>();
	_regexList.get()->insert({"EMAIL", "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"});
	_regexList.get()->insert({"PHONE", "0647005996"});
	_regexList.get()->insert({"IP", "(\\d{1,3}(\\.\\d{1,3}){3})"});
}

Plazza::~Plazza()
{}

Plazza::DataProc::DataProc(std::string name, size_t threadMax)
	:_name(name),_slave(name, threadMax), _input(name, 1), _output(name + "1")
{
	_infos = 0;
}

std::vector<std::string>	Plazza::getInfoProcess()
{
	std::vector<std::string> tmp; 
	for (auto &el: _info)
	{
		tmp.push_back(std::to_string(el.get()->_infos));
	}
	return tmp;
}

void	Plazza::buildNewProcess()
{
	std::string	tmp;
	tmp = std::to_string(std::rand() % 10024 + 2000);
	_info.push_back(std::make_unique<DataProc>(tmp, _threadMax));
}

std::shared_ptr<std::map<std::string, std::string>>	Plazza::getRegexList()
{
	return _regexList;
}

std::shared_ptr<std::vector<std::pair<std::string, std::string>>> Plazza::getQueu()
{
	return _queu;
}

std::vector<std::string>	Plazza::getResult()
{
	std::vector<std::string> tmp = *_result.get();
	_result.get()->clear();
	return tmp;
}

void	Plazza::sendToProcess()
{
	for (auto &it: _info)
	{
		for (size_t nb = 0; nb < it.get()->_infos && _queu.get()->size() > 0; nb ++)
		{
			it.get()->_output << "queu:" + _queu.get()->begin()->first + "," + _queu.get()->begin()->first + "\n";
			_queu.get()->erase(_queu.get()->begin());
		}
	}
}

void	Plazza::manager()
{
	for (size_t i = 0; i < _queu.get()->size(); i++)
	{
		if (_queu.get()->size() > 0 && _info.size() == 0)
			buildNewProcess();
		if (_queu.get()->size() > 0)
		{
			std::cout << 1 << std::endl;
			update();
			sendToProcess();
		}
		update();
	}
}

std::vector<std::string>	Plazza::cutString(std::string str)
{
	std::vector<std::string> tmp;
	std::string line = "";
	size_t nb = 0;
	for(nb = 0; str[nb] != ':' && nb < str.size(); nb++)
		line += str[nb];
	tmp.push_back(line);
	line.clear();
	nb++;
	for (; str[nb] != ',' && nb < str.size(); nb++)
		line += str[nb];
	tmp.push_back(line);
	line.clear();
	nb++;
	for (; str[nb] != '\n' && nb < str.size(); nb++)
		line += str[nb];
	tmp.push_back(line);
	return tmp;
}

void	Plazza::updateData(size_t nb, std::string info)
{
	std::vector<std::string> tmp = cutString(info);
	if (tmp[0] == "info")
		_info[nb].get()->_infos = stoi(tmp[2]);
	else if (tmp[0] == "result")
		_result.get()->push_back(tmp[1] + " " + tmp[2]);
}

void	Plazza::update()
{
	std::map<std::string, std::string> dataMap;
	for (size_t nb = 0; nb < _info.size(); nb++)
	{
		_info[nb].get()->_output << "update:\n";
		std::string tmp;
		std::cout << 2 << std::endl;
		do{
			std::cout << 3 << std::endl;
			tmp << _info[nb].get()->_input;
			std::cout << 4 << std::endl;
			updateData(nb, tmp);
		}while (tmp != "");
	}
	
}

int	Plazza::start()
{
	while(_exit_status)
	{
		manager();
	}
	return 0;
}

