#include "List.hpp"
#include <list>

int main()
{
	std::cout << "INT TESTS" << std::endl;
	ft::List<int> testint;
	testint.push_back(1);
	testint.push_back(2);
	testint.push_back(3);
	std::list<int> testint_base;
	testint_base.push_back(1);
	testint_base.push_back(2);
	testint_base.push_back(3);

	std::cout<< "ft::List front() --> " << testint.front() << std::endl;
	std::cout<< "std::list front() --> " << testint_base.front() << std::endl;
	std::cout<< "ft::List back() --> " << testint.back() << std::endl;
	std::cout<< "std::list back() --> " << testint_base.back() << std::endl;
	std::cout<< "ft::List begin() --> " << *(testint.begin()) << std::endl;
	std::cout<< "std::list begin() --> " << *(testint_base.begin()) << std::endl;

	std::cout << std::endl << "STRING TESTS" << std::endl;
	ft::List<std::string> test2;
	test2.push_back("string_1");
	test2.push_back("string_2");
	test2.push_back("string_3");
	std::list<std::string> test2_base;
	test2_base.push_back("string_1");
	test2_base.push_back("string_2");
	test2_base.push_back("string_3");

	std::cout<< "ft::List front() --> " << test2.front() << std::endl;
	std::cout<< "std::list front() --> " << test2_base.front() << std::endl;
	std::cout<< "ft::List back() --> " << test2.back() << std::endl;
	std::cout<< "std::list back() --> " << test2_base.back() << std::endl;
	std::cout<< "ft::List begin() --> " << *(test2.begin()) << std::endl;
	std::cout<< "std::list begin() --> " << *(test2.begin()) << std::endl;
	std::cout<< *(--test2.rend()) << std::endl;
	std::cout<< *(test2_base.rbegin()) << std::endl;
	std::cout << *(--test2_base.rend()) << std::endl;
}
