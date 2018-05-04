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
	_fd = socket(AF_UNIX, SOCK_STREAM, 0);
	if (_fd == -1) 
		perror("socket error");
	memset(&addr, 0, sizeof(addr));
	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, socketFile.c_str(), sizeof(addr.sun_path) - 1);
	while (access(socketFile.data(), F_OK) != 0);
	if (connect(_fd, (struct sockaddr*)&addr, sizeof(addr)) == -1)
		perror("connect error");
}

Transport::Transport(std::string socketFile, int nbclient)
{
	_fd = socket(AF_UNIX, SOCK_STREAM, 0);
	memset(&addr, 0, sizeof(addr));
	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, socketFile.data(), sizeof(addr.sun_path)-1);
	bind(_fd, (struct sockaddr*)&addr, sizeof(addr));
	listen(_fd, nbclient);
	_fd = accept(_fd, NULL, NULL);
}

Transport::~Transport()
{}

void	Transport::send(std::string txt)
{
	int rc;
	std::cerr << "send:" << txt + "|" << _fd << "|" << std::endl;
	rc = write(_fd, txt.data(), txt.size());
	if (rc == -1) {
		perror("write error");
	}
}

std::string	Transport::reading()
{
	char	buf[2];
	std::string	tmp;
	while (read(_fd, buf, 1))
	{
		tmp += buf[0];
		if (buf[0] == '\n')
		{
			std::cerr << "read:" << tmp << std::endl;
			return tmp;
		}
	}
	return tmp + '\n';
}
