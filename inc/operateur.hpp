/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** operateur
*/

#ifndef OPERATEUR_HPP_
	#define OPERATEUR_HPP_

#include "transport.hpp"
/*
** EPITECH PROJECT, 2018
** myftp
** File description:
** operateurOverload
*/

#include "transport.hpp"

Transport &operator<<(Transport &flux, const std::string &text);
Transport &operator>>(const std::string &text, Transport &flux);
Transport &operator>>(Transport &flux, std::string &text);
Transport &operator<<(std::string &text, Transport &flux);
Transport &operator>>(Transport &flux, std::map<std::string, std::string> &map);
Transport &operator<<(std::map<std::string, std::string> &map, Transport &flux);

#endif /* !OPERATEUR_HPP_ */
