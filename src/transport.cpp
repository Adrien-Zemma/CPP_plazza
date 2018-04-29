/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** transport
*/

#include "../inc/transport.hpp"
#include <sys/un.h>

Transport::Transport(size_t status)
{
	if (status == 1)
		createServer();
	else
		connectClient();
}

Transport::~Transport()
{}

void	Transport::send(std::string txt)
{
	int rc;
	if (*txt.end() != '\n')
		txt += '\n';
	rc = write(fd, txt.data(), txt.size());
	if (rc == -1) {
		perror("write error");
	}
}

std::string	Transport::reading()
{
	int rc;
	char	buf[2];
	std::string	tmp;
	while (read(fd, buf, 1))
	{
		tmp += buf[0];
		if (buf[0] == '\n')
			return tmp;
	}
	return tmp;
}

void	Transport::createServer()
{
	struct sockaddr_un addr;
	char buf[100];
	int cl;
	int rc;
	fd = socket(AF_UNIX, SOCK_STREAM, 0);
	memset(&addr, 0, sizeof(addr));
	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, "test.sock", sizeof(addr.sun_path)-1);
	bind(fd, (struct sockaddr*)&addr, sizeof(addr));
	listen(fd, 5);
	fd = accept(fd, NULL, NULL);
	
}

void	Transport::connectClient()
{
	struct sockaddr_un addr;
	char buf[100];
	int cl;
	int rc;
	fd = socket(AF_UNIX, SOCK_STREAM, 0);
	memset(&addr, 0, sizeof(addr));
	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, "test.sock", sizeof(addr.sun_path)-1);
	connect(fd, (struct sockaddr*)&addr, sizeof(addr));
}

