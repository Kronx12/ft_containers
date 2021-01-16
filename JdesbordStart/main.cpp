#include "List.hpp"
#include <list>

int main()
{
	std::cout << "INT TESTS" << std::endl;
	ft::List<int> testint;
	testint.push_back(2);
	testint.push_back(1);
	testint.push_back(3);
	std::list<int> testint_base;
	testint_base.push_back(2);
	testint_base.push_back(1);
	testint_base.push_back(4);

	//testint.clear();
	//test erase END
	std::cout << "sizeTest base --> " << testint_base.max_size() << std::endl;
	std::cout << "sizeTest new  --> " << testint.max_size() << std::endl;
	testint_base.assign(testint_base.begin(), testint_base.end());
	testint.assign(testint_base.begin(), testint_base.end());
	std::cout<< "ft::List front()  --> " << testint.front() << std::endl;
	std::cout<< "std::list front() --> " << testint_base.front() << std::endl;
	std::cout<< "ft::List back()  --> " << testint.back() << std::endl;
	std::cout<< "std::list back() --> " << testint_base.back() << std::endl;
	std::cout<< "ft::List begin()  --> " << *(testint.begin()) << std::endl;
	std::cout<< "std::list begin() --> " << *(testint_base.begin()) << std::endl;

	std::cout << std::endl << "STRING TESTS" << std::endl;
	ft::List<std::string> teststring;
	teststring.push_back("string_1");
	teststring.push_back("string_2");
	teststring.push_back("string_3");
	std::list<std::string> teststring_base;
	teststring_base.push_back("string_1");
	teststring_base.push_back("string_2");
	teststring_base.push_back("string_4");

	teststring_base.insert(teststring_base.begin(), "ble");
	std::cout << "Base" << std::endl;
	teststring_base.assign(teststring_base.begin(), teststring_base.end());
	std::cout << "Mine" << std::endl;
	teststring.assign(teststring_base.begin(), teststring_base.end());
	std::cout<< "ft::List front()  --> " << teststring.front() << std::endl;
	std::cout<< "std::list front() --> " << teststring_base.front() << std::endl;
	std::cout<< "ft::List back()  --> " << teststring.back() << std::endl;
	std::cout<< "std::list back() --> " << teststring_base.back() << std::endl;
	std::cout<< "ft::List begin()  --> " << *(++teststring.begin()) << std::endl;
	std::cout<< "std::list begin() --> " << *(++teststring_base.begin()) << std::endl;
	std::cout<< "ft::List --end()  --> " << *(--teststring.end()) << std::endl;
	std::cout<< "std::List --end() --> " << *(--teststring_base.end()) << std::endl;
	std::cout<< "ft::List rbegin()  --> " << *(teststring.rbegin()) << std::endl;
	std::cout<< "std::List rbegin() --> " << *(teststring_base.rbegin()) << std::endl;
	std::cout<< "ft::List --rend()  --> " << *(--teststring.rend()) << std::endl;
	std::cout<< "std::List --rend() --> " << *(--teststring_base.rend()) << std::endl;


	std::cout << "SORT TESTS" << std::endl;
	std::cout<< "ft::List front()  --> " << testint.front() << std::endl;
	std::cout<< "std::list front()  --> " << testint_base.front() << std::endl;
	testint.sort();
	testint_base.sort();
	std::cout<< "ft::List front()  --> " << testint.front() << std::endl;
	std::cout<< "std::list front()  --> " << testint_base.front() << std::endl;


	std::cout << "ERASE / CLEAR TESTS" << std::endl;
	std::cout << "erase begin val = " << testint.front() << std::endl;
	testint.erase(testint.begin());
	testint.erase(testint.begin());
	testint.erase(testint.begin());
	std::cout << "erase from begin to end - 1" << std::endl;
	testint.erase(testint.begin(), --testint.end());
	std::cout << "clear" << std::endl;
	testint.clear();
	std::cout << "clear on cleared list" << std::endl;
	testint.clear();
}
