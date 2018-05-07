/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** transport
*/

#include "transport.hpp"
#include <thread>
#include <chrono>

Transport::Transport()
{
	_save = 3;
}

Transport::Transport(std::string socketFile)
{
	int tmp;
	pe = getprotobyname("TCP");
	_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
	std::cout << "\033[35m[CLIENT][" << getpid() << "] socket : "<< _fd << "\033[0m"<<std::endl;
	if (_fd == -1)
		perror("client socket error");
	addr.sin_family = AF_INET;
	addr.sin_port = htons(stoi(socketFile));
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(2s);
	do{
		tmp = connect(_fd, (struct sockaddr*)&addr, sizeof(addr));
		if (tmp == -1)
			std::cout << "\033[31m[CLIENT][" << getpid() << "] test de connexion : "<< _fd<<" return : "<< tmp << "\033[0m"<<std::endl;
		else 
			std::cout << "\033[35m[CLIENT][" << getpid() << "] test de connexion : "<< _fd<<" return : "<< tmp << "\033[0m"<<std::endl;
	}while (tmp != 0);
	std::cout << "\033[35m[CLIENT][" << getpid() << "] fin du client : "<< _fd << "\033[0m"<<std::endl;
	_save = 1;
}

Transport::Transport(std::string socketFile, int nbclient)
{
	pe = getprotobyname("TCP");
	_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
	std::cout << "\033[32m[SERVER][" << getpid() << "] socket : "<< _fd << "\033[0m"<<std::endl;
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
	int save = _fd;
	_fd = accept(_fd, (struct sockaddr *)&addr, &tmp);
	std::cout << "\033[32m[SERVER][" << getpid() << "] accept : "<< _fd << " " << save<< "\033[0m"<<std::endl;
	if (_fd == -1)
		perror("accept");
	_save = 2;
}

Transport::~Transport()
{}

void	Transport::send(std::string txt)
{
	int rc;
	rc = write(_fd, txt.data(), txt.size());
	std::cout << "\033[36m[SEND  ][" << getpid() << "] on : "<< _fd <<" " + txt << rc<<" bytes" <<"\033[0m" << std::endl;
	if (rc == -1) {
		perror("write error");
	}
}

std::string	Transport::reading()
{
	int status;
	char	buf[2];
	std::string	tmp;
	std::cout << "\033[33m[READ  ][" << getpid() << "] on : "<< _fd << " save: "<< _save<< "\033[0m" << std::endl;
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
