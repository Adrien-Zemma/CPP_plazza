/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Threadpool
*/

#include "Threadpool.hpp"
#include <iostream>

Threadpool::Threadpool(std::string cmd, std::string reg, int threadMax)
{
	_regex = reg;
	std::vector<std::string> content;
	std::ifstream file(cmd, std::ios::in);
	if(file)
	{
		std::string line;
		while (std::getline(file, line))
			_input.push_back(line);
		file.close();
	}
	_exit = true;
	for (int i = 0; i < threadMax; i++)
		_threadList.push_back(std::thread([this](){run();}));
	size_t status;
	do{
		_lockInput.lock();
		status = _input.size();
		_lockInput.unlock();
	}while(status != 0);
	_lockExit.lock();
	_exit = false;
	_lockExit.unlock();
	for(auto &el: _threadList)
		el.join();
}

Threadpool::~Threadpool()
{
	
}

std::vector<std::string> Threadpool::getResult()
{
	_lockOutput.lock();
	auto tmp = _output;
	_output.clear();
	_lockOutput.unlock();
	return tmp;
}

void	Threadpool::getRegex(std::string line, std::regex reg)
{
	std::smatch pieces_match;
	std::regex pieces_regex(reg);
	std::vector<std::string> result;
	
	if (std::regex_match(line, pieces_match, pieces_regex))
	{
		std::ssub_match sub_match = pieces_match[0];
		std::string piece = sub_match.str();
		result.push_back(piece);
	}
	_lockOutput.lock();
	for (auto el: result)
		_output.push_back(el);
	_lockOutput.unlock();
}

void	Threadpool::run()
{
	bool status;
	std::string reg = "";
	std::string line = "";

	_lockInput.lock();
	if (_input.size() > 0)
	{
		reg = _regex;
		line = _input[0];
		_input.erase(_input.begin());
	}
	_lockInput.unlock();
	if (line != "")
		getRegex(line, std::regex(reg));
	_lockExit.lock();
	status = _exit;
	_lockExit.unlock();
	if (status)
		run();
}