#include "List.hpp"

int main()
{
	ft::List<int> test;
	test.push_back(3);
	test.push_back(30);
	test.push_back(300);
	std::cout<< test.front() << std::endl;
	std::cout<< test.back() << std::endl;
	std::cout<< *(test.begin()) << std::endl;

	ft::List<std::string> test2;
	test2.push_back("ble");
	test2.push_back("blu");
	test2.push_back("bla");
	std::cout<< test2.front() << std::endl;
	std::cout<< test2.back() << std::endl;
	std::cout<< *(test2.begin()) << std::endl;
}
