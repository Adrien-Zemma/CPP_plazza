/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** main
*/

#include "plazza.hpp"
#include "parse.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		Plazza obj(av[1]);
		Parse tmp(obj.getRegexList(), obj.getQueu());
		tmp.read();
		while(1)
		{
			obj.manager();
		}
		return 0;
	}
	return 84;
}