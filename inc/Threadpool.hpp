/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Threadpool
*/

#ifndef THREADPOOL_HPP_
	#define THREADPOOL_HPP_

#include <mutex>
#include <regex>
#include <string>
#include <vector>
#include <thread>
#include <fstream>

class Threadpool {
	public:
		Threadpool(std::string file, std::string reg, int threadMax);
		~Threadpool();
		std::vector<std::string> getResult();
	protected:
		void	run();
		void	getRegex(std::string line, std::regex reg);
		bool _exit;
		std::string _regex;
		std::mutex _lockExit;
		std::mutex _lockInput;
		std::mutex _lockOutput;
		std::vector<std::string> _output;
		std::vector<std::thread> _threadList;
		std::vector<std::string> _input;
	private:
};

#endif /* !THREADPOOL_HPP_ */
