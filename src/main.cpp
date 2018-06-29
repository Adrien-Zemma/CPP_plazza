/*
** EPITECH PROJECT, 2018
** Plazza
** File description:
** main
*/

#include "Plazza.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		if (atoi(av[1]) == 0)
				return 84;
		Plazza lol(atoi(av[1]));
		lol.start();
		return 0;
	}
	return 84;
}