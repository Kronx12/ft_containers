#include "../includes/test.hpp"
#include <random>

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	Span sp = Span(5);

	std::cout << "trying whithout value" << std::endl;
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception " << e.what() << std::endl;
	}

	try
	{
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(12);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception " << e.what() << std::endl;
	}

	std::cout << std::endl;
	Span sp2 = Span(15);
	try
	{
		sp2.addNumber(5);
		sp2.addNumber(3);
		sp2.addNumber(17);
		sp2.addNumber(0);
		sp2.addNumber(-17);
		sp2.addNumber(9);
		sp2.addNumber(11);
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;	
	}
	catch (std::exception & e)
	{
		std::cout << "Exception " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "trying max size and 150000 span" << std::endl;
	Span sp3 = Span(150000);
	try
	{
		for (int i = 0; i < 150001; i++)
			sp3.addNumber(rand());
	}
	catch (std::exception & e)
	{
		std::cout << "Exception " << e.what() << std::endl;
	}

	try
	{
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "trying INT MAX and INT MIN" << std::endl;
	std::cout << std::endl;
	Span sp4 = Span(15);
	try
	{
		sp4.addNumber(INT_MIN);
		sp4.addNumber(INT_MAX);
		std::cout << sp4.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception " << e.what() << std::endl;
	}
	try
	{
		std::cout << sp4.shortestSpan() << std::endl;	
	}
	catch (std::exception & e)
	{
		std::cout << "Exception " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "trying max size and 150000 span with iterator addNumber" << std::endl;
	Span sp5 = Span(150000);
	std::vector<int> vec(150000);
	std::generate(begin(vec), end(vec), rand);
	try
	{
		sp5.addMultiple(vec);
		std::cout << "Long " << sp5.longestSpan() << std::endl;
		std::cout << "Short " << sp5.shortestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception " << e.what() << std::endl;
	}

	std::cout << "trying max size and 1500 span with iterator addNumber" << std::endl;
	Span sp6 = Span(1500);
	std::vector<int> vec2(1500);
	std::generate(begin(vec2), end(vec2), rand);
	try
	{
		sp6.addMultiple(vec2);
		std::cout << "Long " << sp6.longestSpan() << std::endl;
		std::cout << "Short " << sp6.shortestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception " << e.what() << std::endl;
	}
}