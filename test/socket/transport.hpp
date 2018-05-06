/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** transport
*/

#ifndef TRANSPORT_HPP_
	#define TRANSPORT_HPP_

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/un.h>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <netdb.h>
#include <memory>
#include <map>

class Transport
{
public:
	Transport();
	Transport(std::string socketFile);
	Transport(std::string socketFile, int nbClient);
	~Transport();
	size_t	getFdTarget();
	void	send(std::string);
	std::string	reading();
private:
	int	_fd;
	struct sockaddr_un addr;
};

#endif /* !TRANSPORT_HPP_ */
