/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** transport
*/

#ifndef TRANSPORT_HPP_
	#define TRANSPORT_HPP_

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <memory>
#include <map>
#include <sys/types.h>


class Transport
{
public:
	Transport(size_t status);
	~Transport();
	size_t	getFdTarget();
	void	send(std::string);
	std::string	reading();
private:
	void	createServer();
	void	connectClient();
	int	fd;
	std::shared_ptr<std::map<int, std::pair<size_t, size_t>>>	fdTab;
};

Transport &operator<<(Transport&flux, const std::string &text);
Transport &operator>>(Transport&flux, std::string &text);

#endif /* !TRANSPORT_HPP_ */
