#include <thread>
#include <iostream>
#include <memory>
#include <vector>
#include <mutex>
#include <cstdlib>
#include <ctime>
#include <string>

std::mutex	lock;
std::vector<std::string> tmp;

static int lol()
{
	size_t nb = std::rand();
	std::string couille = std::to_string(nb);
	lock.lock();
	tmp.push_back(couille);
	lock.unlock();
	std::this_thread::yield();
}

int	main()
{
	int nb = 0;
	int nbWorker = 10;
	std::srand(time(NULL));
	std::vector<std::thread> worker;
	for (int i = 0; i < nbWorker; i++)
	{
		worker.push_back(std::thread(lol));
	}
	while (nb <  nbWorker)
	{
		if (lock.try_lock() == true)
		{
			if (tmp.size() > 0)
			{
				nb += tmp.size();
				for(auto el:tmp)
					std::cout << "|" + el + "|" << std::endl;
				tmp.clear();
			}
			lock.unlock();
		}
	}
	std::cout << "a";
	for (int i = 0; i < nbWorker; i++)
	{
		worker[i].join();
	}
	std::cout << "b";
}