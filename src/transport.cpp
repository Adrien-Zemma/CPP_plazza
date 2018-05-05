/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** transport
*/

#include "transport.hpp"

Transport::Transport()
{}

Transport::Transport(std::string socketFile)
{
	pe = getprotobyname("TCP");
	_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
	if (_fd == -1) 
		perror("client socket error");
	addr.sin_family = AF_UNIX;
	addr.sin_port = htons(stoi(socketFile));
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	bzero(&addr, sizeof(addr));
	if (connect(_fd, (struct sockaddr*)&addr, sizeof(addr)) == -1)
		perror("connect error");
	_save = _fd;
	std::cerr<< "client connect\t" << _fd << std::endl;
}

Transport::Transport(std::string socketFile, int nbclient)
{
	pe = getprotobyname("TCP");
	_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
	if (_fd == -1)
		perror("socket");
	std::cerr << "socket: fd \t" << _fd <<std::endl;
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_UNIX;
	addr.sin_port = htons(stoi(socketFile));
	addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(_fd, (struct sockaddr*)&addr, sizeof(addr)) == -1)
		perror("bind");
	std::cerr << "socket: fd \t" << _fd <<std::endl;
	if (listen(_fd, nbclient) == -1)
		perror("listen");
	std::cerr << "socket: fd \t" << _fd <<std::endl;
	socklen_t tmp = sizeof(addr);
	_fd = accept(_fd, (struct sockaddr *)&addr, &tmp);
	if (_fd == -1)
		perror("accept");
	std::cerr<< "accept\t" << _fd << std::endl;
}

Transport::~Transport()
{}

void	Transport::send(std::string txt)
{
	int rc;
	std::cout << "send" << std::endl;
	std::cerr<< "send\t" << _fd << "\t" << txt << std::endl;
	rc = write(_fd, txt.data(), txt.size());
	if (rc == -1) {
		perror("write error");
	}
}

std::string	Transport::reading()
{
	char	buf[2];
	std::string	tmp;
	std::cout << "read" << std::endl;
	while (read(_fd, buf, 1))
	{
		tmp += buf[0];
		std::cerr<< "read\t" << _fd << "\t" << tmp << std::endl;
		if (buf[0] == '\n')
		{
			return tmp;
		}
	}
	std::cout << "read fini" << std::endl;
	return tmp + '\n';
}
