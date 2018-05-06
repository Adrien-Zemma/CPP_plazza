/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** threadpool
*/

#include <vector>
#include <string>
#include <memory>
#include <mutex>
#include <thread>
#include <iostream>

#ifndef THREADPOOL_HPP_
	#define THREADPOOL_HPP_

class	Threadpool {
public:
	Threadpool(size_t threadMax); //construit tout les treads
	~Threadpool();
	size_t	getInfo();
	std::vector <std::string> getResult();
	void	addCommande(std::pair<std::string, std::string> order);
	
protected:

	bool	getExit();
	void	threadWork(size_t nb);
	std::string	getRegex(size_t id);
	void	setID(size_t id, bool data);
	void	pushResult(std::string tmp);
	std::pair<std::string, std::string>	getFirstQueu();
	size_t	_threadMax;
	bool	_exit;
	std::mutex	_lockQueu;
	std::mutex	_lockInfo;
	std::mutex	_lockExit;
	std::mutex	_lockResult;
	std::vector<std::string> _result;
	std::vector<bool>	_threadStatus;
	std::vector<std::thread>	_threads;
	std::vector<std::pair<std::string, std::string>> _queu;

};

#endif /* !THREADPOOL_HPP_ */
