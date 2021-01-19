#include "List.hpp"
#include <list>
#include <sstream>

// Used for show test result
#ifndef SHOW
# define SHOW
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

void check(std::stringstream *ss_std, std::stringstream *ss_ft)
{
	if (!ss_std->str().compare(ss_ft->str()))
	{
		#ifdef SHOW
		std::cout << "\033[1;32mOK\033[2;37m\n" << ss_std->str() << std::endl << ss_ft->str() << "\033[0m";
		#else
		std::cout << "\033[1;32mOK\033[0m";
		#endif
	}
	else
		std::cout << "\033[1;31mKO\n" << ss_std->str() << std::endl << ss_ft->str() << "\033[0m";
	std::cout << std::endl;
	ss_std->str("");
	ss_ft->str("");
}
