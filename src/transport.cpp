/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** transport
*/

#include "transport.hpp"
#include <sys/un.h>

Transport::Transport(std::string socketFile)
{
	struct sockaddr_un addr;
	fd = socket(AF_UNIX, SOCK_STREAM, 0);
	memset(&addr, 0, sizeof(addr));
	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, socketFile.data(), sizeof(addr.sun_path)-1);
	connect(fd, (struct sockaddr*)&addr, sizeof(addr));
}

Transport::Transport()
{
	struct sockaddr_un addr;
	fd = socket(AF_UNIX, SOCK_STREAM, 0);
	memset(&addr, 0, sizeof(addr));
	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, "test.sock", sizeof(addr.sun_path)-1);
	bind(fd, (struct sockaddr*)&addr, sizeof(addr));
	listen(fd, 5);
	fd = accept(fd, NULL, NULL);
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
