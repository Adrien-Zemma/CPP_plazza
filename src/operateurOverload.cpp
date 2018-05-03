/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** operateurOverload
*/

#include "transport.hpp"

Transport &operator<<(Transport &flux, const std::string &text)
{
	flux.send(text);
	return flux;
}

Transport &operator>>(const std::string &text, Transport &flux)
{
	flux.send(text);
	return flux;
}

Transport &operator>>(Transport &flux, std::string &text)
{
	text = flux.reading();
	return flux;
}


Transport &operator<<(std::string &text, Transport &flux)
{
	text = flux.reading();
	return flux;
}