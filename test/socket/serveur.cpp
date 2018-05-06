#include "transport.hpp"

int main()
{
	Transport test(".coucou", 2);
	Transport test2(".salut");
	while (1)
	{
		std::cout << test.reading() << std::endl;
		test2.send("test boy\n");
	}
}