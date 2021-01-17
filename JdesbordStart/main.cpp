#include "List.hpp"
#include <list>

template < class T >
void describe_list(std::list<T> lst, std::string name)
{
	int i = 0;
	std::cout << name << " :" << std::endl;
	if (lst.empty())
		std::cout << "(empty)";
	else
		for (typename std::list<T>::iterator itr = lst.begin(); itr != lst.end(); itr++)
		{
			std::cout << i << ":[" << *itr << "] ";
			i++;
		}
	std::cout << std::endl;
}

template < class T >
void describe_list(ft::List<T> lst, std::string name)
{
	int i = 0;
	std::cout << name << " :" << std::endl;
	if (lst.empty())
		std::cout << "(empty)";
	else
		for (typename ft::List<T>::iterator itr = lst.begin(); itr != lst.end(); itr++)
		{
			std::cout << i << ":[" << *itr << "] ";
			i++;
		}
	std::cout << std::endl;
}

template < class T >
void describe_list(std::list<T> std_lst, std::string std_name, ft::List<T> ft_lst, std::string ft_name)
{
	describe_list(std_lst, std_name);
	describe_list(ft_lst, ft_name);
	std::cout << std::endl;
}

void constructor_test(int size)
{
// default constructor
	std::list<int> std_lst;
	ft::List<int> ft_lst;
	describe_list(std_lst, "std_list", ft_lst, "ft_lst");

	for (int i = 0; i < size; i++)
	{
		std_lst.push_back(i);
		ft_lst.push_back(i);
	}
	describe_list(std_lst, "std_list", ft_lst, "ft_lst");

// fill constructor
	std::list<int> std_lst_fill(size);
	ft::List<int> ft_lst_fill(size);
	describe_list(std_lst_fill, "std_lst_fill", ft_lst_fill, "ft_lst_fill");

	// ====================================================================== BAD CONSTRUCTOR CALLED
	// std_lst_fill = std::list<int>(size, 5);
	// ft_lst_fill = ft::List<int>(size, 5);
	// describe_list(std_lst_fill, "std_lst_fill", ft_lst_fill, "ft_lst_fill");
	// TODO ========================================================================================

// range constructor
	std::list<int> std_lst_range(std_lst.begin(), std_lst.end());
	ft::List<int> ft_lst_range(ft_lst.begin(), ft_lst.end());
	describe_list(std_lst_range, "std_lst_range", ft_lst_range, "ft_lst_range");

// copy constructor
	std::list<int> std_lst_copy(std_lst);
	ft::List<int> ft_lst_copy(ft_lst);
	describe_list(std_lst_copy, "std_lst_copy", ft_lst_copy, "ft_lst_copy");


// assignment constructor
	std::list<int> std_lst_assignment;
	ft::List<int> ft_lst_assignment;
	std_lst_assignment = std_lst_range;
	ft_lst_assignment = ft_lst_range;
	describe_list(std_lst_assignment, "std_lst_assignment", ft_lst_assignment, "ft_lst_assignment");

	std::cout << "=========================" << std::endl << std::endl;
}

int main()
{
	// constructor_test(100000); OK Sur linux (juste chiant a afficher)
	constructor_test(10);
	constructor_test(5);
	constructor_test(2);
	constructor_test(1);
	constructor_test(0);

	/*
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
	testint.clear();*/
}