#include "Tester.hpp"
#include "List.hpp"
#include <list>
#include <sstream>

// Use for show test result
#ifndef SHOW
# define SHOW
#endif

// Use for auto exit on error
#ifndef EXIT_ERR
# define EXIT_ERR 0
#endif

void title(std::string title)
{
	std::cout << "\033[33;1m" << std::endl << title << "\n\033[0m";
}

void title(std::string title, int size)
{
	std::cout << "\033[33;1m" << std::endl << "=========================\n" << "\033[0m";
	std::cout << "\033[33;1m" << title << " (" << size << ")" << std::endl << "\033[0m";
	std::cout << "\033[33;1m" << "=========================\n\n" << "\033[0m";
}

void check(std::stringstream *ss_std, std::stringstream *ss_ft, int flag)
{
	bool e = false;
	if (!ss_std->str().compare(ss_ft->str()) && !flag)
	{
		#ifdef SHOW
		std::cout << "\033[1;32mOK\033[2;37m\n" << ss_std->str() << std::endl << ss_ft->str() << "\033[0m";
		#else
		std::cout << "\033[1;32mOK\033[0m";
		#endif
		g_valid++;
	}
	else if (flag == 1)
	{
		std::cout << "\033[3;33mUNDEFINED\n" << ss_std->str() << std::endl << ss_ft->str() << "\033[0m";
		g_valid++;
	}
	else
	{
		std::cout << "\033[1;31mKO\n" << ss_std->str() << std::endl << ss_ft->str() << "\033[0m";
		#if EXIT_ERR==1
			e = true;
		#endif
	}
	std::cout << std::endl;
	ss_std->str("");
	ss_ft->str("");
	g_test++;
	if (e) exit(1);
}

void end_test()
{
	if (g_valid == g_test)
		std::cout << "\033[1;32m=====[ " << g_valid << "/" << g_test << " ]=====\033[0m" << std::endl;
	else
		std::cout << "\033[1;33m=====[ " << g_valid << "/" << g_test << " ]=====\033[0m" << std::endl;
}
