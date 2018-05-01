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
	for (std::string line; std::getline(std::cin, line);)
		manage_command(line);
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

std::vector<std::string> split_commands(std::string command)
{
	std::vector<std::string> ne;
	std::string line;

	for (int i = 0; command[i]; i++) {
		if (command[i] == ';') {
			ne.append(line);
			line.clear();
		}
		line.append(command[i]);
	}
	ne.append(line);
	return ne;
}

std::string	split(std::string line, char c, int nb)
{
	std::string command;
	int	nb2 = 0;

	for (int i = 0; line[i]; i++) {
		if (line[i] == c) {
			nb2++;
			continue ;
		}
		if (nb2 >= nb)
			break ;
		command.append(line[i]);
	}
	return command;
}

void manage_commands(std::string line)
{
	std::vector<std::string> commands = split_commands(line);

	for (auto &command: commands) {
		std::string type = split(line, ' ', std::count(s.begin(), s.end(), ' '));
		
	}
}