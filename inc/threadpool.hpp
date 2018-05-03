/*
** EPITECH PROJECT, 2018
** cpp_plazza
** File description:
** threadpool
*/

#include <vector>
#include <string>

#ifndef THREADPOOL_HPP_
	#define THREADPOOL_HPP_

class	Threadpool{
public:
	Threadpool();
	~Threadpool();
	void	setQueu(std::shared_ptr<std::vector<std::pair<std::string, std::string>>> _queu);
	void	work();
private:
void    getRegex(toTransfert &data)
{
	std::regex	toFind(data.request);
	std::string	lines;
	std::string	tmp;
	std::smatch	m;
	std::ifstream myfile	(data.file);
	if (!myfile)
		return ;
	while (getline(myfile, tmp))
		lines += tmp;
	myfile.close();
	while (std::regex_search (lines, m, toFind)) {
		data.flux << m[0];
        	lines = m.suffix().str();
	}
	std::this_thread::yield();
}
};

#endif /* !THREADPOOL_HPP_ */
