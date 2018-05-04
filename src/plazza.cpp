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
	std::cerr << "PLAZZA\t" << "Building Plazza" << std::endl;
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
	:_name(name),_slave(name, threadMax), _input(".S" + name, 1), _output(".S" + name + "R")
{
	std::cerr << "PLAZZA\t" << "Building slave" << std::endl;
	_infos = 0;
	if (_slave.getPid() == 0)
			_slave.start();
}

void	Plazza::buildNewProcess()
{
	std::string	tmp;
	tmp = std::to_string(std::rand() % 10000000);
	//if (access(tmp.c_str(), F_OK) == 0)
	{
		_info.push_back(std::make_unique<DataProc>(tmp, _threadMax));
	}
	/*else 
		buildNewProcess();*/
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
	std::cerr << "PLAZZA\t" << "wait for order" << std::endl;
	for (size_t i = 0; i < _queu.get()->size(); i++)
	{
		std::cerr << "PLAZZA\t" << "order receve" << std::endl;
		if (_queu.get()->size() > 0 && _info.size() == 0)
			buildNewProcess();
		if (_queu.get()->size() > 0)
		{
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
	std::cerr << "PLAZZA\t" << "updating all info" << std::endl;
	std::map<std::string, std::string> dataMap;
	for (size_t nb = 0; nb < _info.size(); nb++)
	{
		std::cerr << "PLAZZA\t" << "updating slave "<< nb << std::endl;
		_info[nb].get()->_output << "update:\n";
		std::string tmp = "c";
		while (tmp != "")
		{
			tmp << _info[nb].get()->_input;
			updateData(nb, tmp);
		}
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

