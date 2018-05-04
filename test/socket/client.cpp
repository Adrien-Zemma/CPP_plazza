#include "transport.hpp"

int main()
{
	Transport test(".coucou");
	Transport test2(".salut", 1);
	while (1)
	{
		test.send(std::string("salut\n"));
		std::cout << test2.reading() << std::endl;
	}
}