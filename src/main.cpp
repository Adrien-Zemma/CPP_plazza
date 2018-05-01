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
		obj.start();
		return 0;
	}
	return 84;
}