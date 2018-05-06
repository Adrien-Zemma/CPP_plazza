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
	int tmp;
	pe = getprotobyname("TCP");
	_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
	if (_fd == -1) 
		perror("client socket error");
	addr.sin_family = AF_INET;
	addr.sin_port = htons(stoi(socketFile));
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	do{
		tmp = connect(_fd, (struct sockaddr*)&addr, sizeof(addr));
	}while ( tmp!= 0);
	_save = _fd;
}

Transport::Transport(std::string socketFile, int nbclient)
{
	pe = getprotobyname("TCP");
	_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
	if (_fd == -1)
		perror("socket");
	addr.sin_family = AF_INET;
	addr.sin_port = htons(stoi(socketFile));
	addr.sin_addr.s_addr = (INADDR_ANY);
	if (bind(_fd, (struct sockaddr*)&addr, sizeof(addr)) == -1)
		perror("bind");
	if (listen(_fd, nbclient) == -1)
		perror("listen");
	socklen_t tmp = sizeof(addr);
	_fd = accept(_fd, (struct sockaddr *)&addr, &tmp);
	if (_fd == -1)
		perror("accept");
}

Transport::~Transport()
{}

void	Transport::send(std::string txt)
{
	int rc;
	rc = write(_fd, txt.data(), txt.size());
	if (rc == -1) {
		perror("write error");
	}
}

std::string	Transport::reading()
{
	int status;
	char	buf[2];
	std::string	tmp;
	do {
		status = read(_fd, buf, 1);
		tmp += buf[0];
		if (buf[0] == '\n')
		{
			return tmp;
		}
	}while (status != 0);
	return tmp + '\n';
}
