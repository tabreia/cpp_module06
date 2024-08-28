#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static	int	randNumber(size_t min, size_t max)
{
	srand(time(NULL));
	return ((rand() % max) + min);
}

Base * generate(void)
{
	size_t	num = randNumber(1, 3);
	Base	*base = NULL;


	switch (num)
	{
		case 1:
			base = dynamic_cast<Base *>(new A);
			break;
		case 2:
			base = dynamic_cast<Base *>(new B);
			break;
		case 3:
			base = dynamic_cast<Base *>(new C);
			break;
	}
	return (base);
}

void	identify(Base* p)
{
	try
	{
		if (dynamic_cast<A *>(p))
			std::cout << "A" << "\n";
		else if (dynamic_cast<B *>(p))
			std::cout << "B" << "\n";
		else if (dynamic_cast<C *>(p))
			std::cout << "C" << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	identify(Base& p)
{
	try
	{
		if (dynamic_cast<A *>(&p))
			std::cout << "A" << "\n";
		else if (dynamic_cast<B *>(&p))
			std::cout << "B" << "\n";
		else if (dynamic_cast<C *>(&p))
			std::cout << "C" << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main(void)
{
	Base *p1;
	Base *p2;

	p1 = generate();
	usleep(1000000);
	p2 = generate();

	std::cout << "Pointers:" << std::endl;
	identify(p1);
	identify(p2);

	std::cout << "References:" << std::endl;
	identify(*p1);
	identify(*p2);

	delete p1;
	delete p2;
	return (0);
}