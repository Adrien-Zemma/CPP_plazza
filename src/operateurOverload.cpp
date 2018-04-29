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

Transport &operator>>(Transport &flux, std::map<std::string, std::string> &map)
{
	std::string	text;
	std::string	key;
	std::string	value;
	text = flux.reading();
	for(size_t i = 0; i < text.size(); i++)
	{
		for (int i = 0; text[i] != ':'; i++)
			key.push_back(text[i]);
		for (int i = 0; text[i] != ';' && text[i] != '\n'; i++)
			value.push_back(text[i]);
		map.insert({key, value});	
	}
	return flux;
}

Transport &operator<<(std::map<std::string, std::string> &map, Transport &flux)
{
	std::string	text;
	std::string	key;
	std::string	value;
	text = flux.reading();
	for(size_t i = 0; i < text.size(); i++)
	{
		for (int i = 0; text[i] != ':'; i++)
			key.push_back(text[i]);
		for (int i = 0; text[i] != ';' && text[i] != '\n'; i++)
			value.push_back(text[i]);
		map.insert({key, value});	
	}
	return flux;
}