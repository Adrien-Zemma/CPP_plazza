/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Parse class
*/

#include "parse.hpp"

Parse::Parse(std::shared_ptr<std::map<std::string, std::string>> regexList, std::shared_ptr<std::vector<std::pair<std::string, std::string>>> queue)
{
	_regexList = regexList;
	_queu = queue;
}

Parse::~Parse()
{}

int	Parse::read()
{
	for (std::string line; std::getline(std::cin, line);)
		manage_commands(line);
	return 0;
}

std::vector<std::string> Parse::split_commands(std::string command)
{
	std::vector<std::string> ne;
	std::string line;

	for (int i = 0; command[i]; i++) {
		if (command[i] == ';') {
			ne.push_back(line);
			line.clear();
		}
		else
			line.push_back(command[i]);
	}
	ne.push_back(line);
	return ne;
}

std::string	Parse::split(std::string line, char c, int nb)
{
	std::string command;
	int	nb2 = 0;

	for (int i = 0; line[i]; i++) {
		if (line[i] == c) {
			nb2++;
			continue ;
		}
		if (nb2 > nb)
			break ;
		else if (nb2 == nb)
			command.push_back(line[i]);
	}
	return command;
}

void	Parse::manage_commands(std::string line)
{
	std::vector<std::string> commands = split_commands(line);

	for (auto &command: commands) {
		std::string type = split(command, ' ', std::count(command.begin(), command.end(), ' '));
		try {
			if (*_regexList.get()->find(type) != *_regexList.get()->end()) {
				for (int i = 0; i != std::count(command.begin(), command.end(), ' '); i++) {
					_queu.get()->push_back(std::pair<std::string, std::string>(split(command, ' ', i), type));
				}
			}
  		}
		catch (const std::out_of_range& oor) {
			std::cerr << "No type declared for: " << oor.what() << std::endl;
  		}
	}
}