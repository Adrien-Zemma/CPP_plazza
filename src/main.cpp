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
			std::cout << "111111111111" << std::endl;
			obj.manager();
			auto tab = obj.getResult();
			for (auto &it: tab)
				std::cout << it << std::endl;
		}
		return 0;
	}
	return 84;
}