#include "List.hpp"
#include <list>
#include <sstream>

/*

all = 0
constructor_test = 1
iterator_test = 2
capacity_test = 3
element_access_test = 4
modifiers_test = 5
modifiers2_test = 6

*/
#ifndef TEST
# define TEST 0
#endif

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

template < class T >
void describe_list(std::list<T> std_lst, ft::List<T> ft_lst)
{
	std::stringstream ss_std;
	std::stringstream ss_ft;

	ss_std << "- ";
	ss_ft << "- ";

	int i = 0;
	if (std_lst.empty())
		ss_std << "(empty)";
	else
		for (typename std::list<T>::iterator itr = std_lst.begin(); itr != std_lst.end(); itr++)
		{
			ss_std << i << ":[" << *itr << "] ";
			i++;
		}

	i = 0;
	if (ft_lst.empty())
		ss_ft << "(empty)";
	else
		for (typename ft::List<T>::iterator itr = ft_lst.begin(); itr != ft_lst.end(); itr++)
		{
			ss_ft << i << ":[" << *itr << "] ";
			i++;
		}
	check(&ss_std, &ss_ft);
}

template < class T >
void const_describe_list(const std::list<T> std_lst, const ft::List<T> ft_lst)
{
	std::stringstream ss_std;
	std::stringstream ss_ft;

	ss_std << "- ";
	ss_ft << "- ";

	int i = 0;
	if (std_lst.empty())
		ss_std << "(empty)";
	else
		for (typename std::list<T>::const_iterator itr = std_lst.begin(); itr != std_lst.end(); itr++)
		{
			ss_std << i << ":[" << *itr << "] ";
			i++;
		}

	i = 0;
	if (ft_lst.empty())
		ss_ft << "(empty)";
	else
		for (typename ft::List<T>::const_iterator itr = ft_lst.begin(); itr != ft_lst.end(); itr++)
		{
			ss_ft << i << ":[" << *itr << "] ";
			i++;
		}
	check(&ss_std, &ss_ft);
}

template < class T >
void reverse_describe_list(std::list<T> std_lst, ft::List<T> ft_lst)
{
	std::stringstream ss_std;
	std::stringstream ss_ft;

	ss_std << "- ";
	ss_ft << "- ";

	int i = 0;
	if (std_lst.empty())
		ss_std << "(empty)";
	else
		for (typename std::list<T>::reverse_iterator itr = std_lst.rbegin(); itr != std_lst.rend(); itr++)
		{
			ss_std << i << ":[" << *itr << "] ";
			i++;
		}

	i = 0;
	if (ft_lst.empty())
		ss_ft << "(empty)";
	else
		for (typename ft::List<T>::reverse_iterator itr = ft_lst.rbegin(); itr != ft_lst.rend(); itr++)
		{
			ss_ft << i << ":[" << *itr << "] ";
			i++;
		}
	check(&ss_std, &ss_ft);
}

template < class T >
void const_reverse_describe_list(const std::list<T> std_lst, const ft::List<T> ft_lst)
{
	std::stringstream ss_std;
	std::stringstream ss_ft;

	ss_std << "- ";
	ss_ft << "- ";

	int i = 0;
	if (std_lst.empty())
		ss_std << "(empty)";
	else
		for (typename std::list<T>::const_reverse_iterator itr = std_lst.rbegin(); itr != std_lst.rend(); itr++)
		{
			ss_std << i << ":[" << *itr << "] ";
			i++;
		}

	i = 0;
	if (ft_lst.empty())
		ss_ft << "(empty)";
	else {
		for (typename ft::List<T>::const_reverse_iterator itr = ft_lst.rbegin(); itr != ft_lst.rend(); itr++)
		{
			ss_ft << i << ":[" << *itr << "] ";
			i++;
		}
	}
	check(&ss_std, &ss_ft);
}

void constructor_test(int size)
{
	title("Constructor size", size);
// default constructor
	std::list<int> std_lst;
	ft::List<int> ft_lst;
	describe_list(std_lst, ft_lst);

	for (int i = 0; i < size; i++)
	{
		std_lst.push_back(i);
		ft_lst.push_back(i);
	}
	describe_list(std_lst, ft_lst);

// fill constructor
	std::list<int> std_lst_fill(size);
	ft::List<int> ft_lst_fill(size);
	describe_list(std_lst_fill, ft_lst_fill);

	// ====================================================================== BAD CONSTRUCTOR CALLED
	// std_lst_fill = std::list<int>(size, 5);
	// ft_lst_fill = ft::List<int>(size, 5);
	// describe_list(std_lst_fill, "std_lst_fill", ft_lst_fill, "ft_lst_fill");
	// TODO ========================================================================================

// range constructor
	std::list<int> std_lst_range(std_lst.begin(), std_lst.end());
	ft::List<int> ft_lst_range(ft_lst.begin(), ft_lst.end());
	describe_list(std_lst_range, ft_lst_range);

// copy constructor
	std::list<int> std_lst_copy(std_lst);
	ft::List<int> ft_lst_copy(ft_lst);
	describe_list(std_lst_copy, ft_lst_copy);


// assignment constructor
	std::list<int> std_lst_assignment;
	ft::List<int> ft_lst_assignment;
	std_lst_assignment = std_lst_range;
	ft_lst_assignment = ft_lst_range;
	describe_list(std_lst_assignment, ft_lst_assignment);

}

void iterator_test(int size)
{
	title("Iterator size", size);
	std::list<int> std_lst;
	ft::List<int> ft_lst;

	for (int i = 0; i < size; i++)
	{
		std_lst.push_back(i);
		ft_lst.push_back(i);
	}

	const std::list<int> const_std_lst(std_lst);
	const ft::List<int> const_ft_lst(ft_lst);

// iterators
	describe_list(std_lst, ft_lst);

// const_iterators
	const_describe_list(const_std_lst, const_ft_lst);

// reverse_iterators
	reverse_describe_list(std_lst, ft_lst);

// const_reverse_iterator
	const_reverse_describe_list(const_std_lst, const_ft_lst);
}

void capacity_test(int size)
{
	title("Capacity size", size);
	std::list<int> std_lst;
	std::list<int> ft_lst;

	for (int i = 0; i < size; i++)
	{
		std_lst.push_back(i);
		ft_lst.push_back(i);
	}

// capacity
	std::stringstream ss_std;
	std::stringstream ss_ft;

	ss_std << "size : " << std_lst.size();
	ss_ft << "size : " << ft_lst.size();
	check(&ss_std, &ss_ft);

	ss_std << "max_size : " << std_lst.max_size();
	ss_ft << "max_size : " << ft_lst.max_size();
	check(&ss_std, &ss_ft);

	ss_std << "empty : " << std_lst.empty();
	ss_ft << "empty : " << ft_lst.empty();
	check(&ss_std, &ss_ft);
}

void element_access_test(int size)
{
	title("Element_access", size);
	std::list<int> std_lst;
	std::list<int> ft_lst;

	for (int i = 0; i < size; i++)
	{
		std_lst.push_back(i);
		ft_lst.push_back(i);
	}

// element access
	std::stringstream ss_std;
	std::stringstream ss_ft;

	ss_std << "front : " << std_lst.front();
	ss_ft << "front : " << ft_lst.front();
	check(&ss_std, &ss_ft);

	ss_std << "back : " << std_lst.back();
	ss_ft << "back : " << ft_lst.back();
	check(&ss_std, &ss_ft);
}

void modifiers_test(int size)
{
	title("Modifiers size", size);

	std::list<int> std_lst;
	ft::List<int> ft_lst;

	// ====================================================================== BAD ASSIGN CALLED
	// std_lst.assign(size, size);
	// ft_lst.assign(size, size);
	// std::cout << "assign(" << size << ":" << size << ")" << std::endl;
	// describe_list(std_lst, "std_lst", ft_lst, "ft_lst");
	// TODO ==========================================================================================

	std_lst = std::list<int>(size);
	ft_lst = ft::List<int>(size);
	title("initial :");
	describe_list(std_lst, ft_lst);
	std::list<int> std_lst_assign;
	ft::List<int> ft_lst_assign;

	title("assign from iterator :");
	std_lst_assign.assign(std_lst.begin(), std_lst.end());
	ft_lst_assign.assign(ft_lst.begin(), ft_lst.end());
	describe_list(std_lst_assign, ft_lst_assign);

	title("push_back :");
	std::list<int> std_lst_back;
	ft::List<int> ft_lst_back;
	for (int i = 0; i < size; i++)
	{
		std_lst_back.push_back(i);
		ft_lst_back.push_back(i);
	}
	describe_list(std_lst_back, ft_lst_back);

	title("push_front :");
	std::list<int> std_lst_front;
	ft::List<int> ft_lst_front;
	for (int i = 1; i < size; i++)
	{
		std_lst_front.push_front(i);
		ft_lst_front.push_front(i);
	}
	describe_list(std_lst_front, ft_lst_front);
	
	title("pop_back :");
	while (!std_lst.empty() && !ft_lst.empty())
	{
		std_lst.pop_back();
		ft_lst.pop_back();
		describe_list(std_lst, ft_lst);
	}

	title("pop_front :");
	while (!std_lst_assign.empty() && !ft_lst_assign.empty())
	{
		std_lst_assign.pop_front();
		ft_lst_assign.pop_front();
		describe_list(std_lst_assign, ft_lst_assign);
	}
}

void modifiers2_test(int size)
{
	title("Modifiers size", size);

	std::list<int> std_lst;
	ft::List<int> ft_lst;
	for (int i = 0; i < size; i++)
	{
		std_lst.push_back(i);
		ft_lst.push_back(i);
	}

	title("swap :");
	std::list<int> std_lst_swap;
	ft::List<int> ft_lst_swap;
	for (int i = 0; i < size; i++)
	{
		std_lst_swap.push_back(size - i);
		ft_lst_swap.push_back(size - i);
	}
	std_lst.swap(std_lst_swap);
	ft_lst.swap(ft_lst_swap);
	describe_list(std_lst, ft_lst);
	describe_list(std_lst_swap, ft_lst_swap);

	title("clear :");
	std_lst.clear();
	ft_lst.clear();
	std_lst_swap.clear();
	ft_lst_swap.clear();
	describe_list(std_lst, ft_lst);
	describe_list(std_lst_swap, ft_lst_swap);

	if (size > 0)
	{
		//erase nb
		title("erase with one nb :");
		for (int i = 0; i < size; i++)
		{
			std_lst.push_back(size - i);
			ft_lst.push_back(size - i);
		}
		std_lst.erase(std_lst.begin());
		ft_lst.erase(ft_lst.begin());
		describe_list(std_lst, ft_lst);
		//erase itr
		title("erase with one itr range :");
		std_lst.clear();
		ft_lst.clear();
		for (int i = 0; i < size; i++)
		{
			std_lst.push_back(size - i);
			ft_lst.push_back(size - i);
		}
		std_lst.erase(std_lst.begin(), std_lst.end());
		ft_lst.erase(ft_lst.begin(), ft_lst.end());
		describe_list(std_lst, ft_lst);
	}

	// ====================================================================== No proto Resize
	// std::cout << "resize :" << std::endl;
	// std_lst.resize(size + 1);
	// ft_lst.resize(size + 1);
	// describe_list(std_lst, ft_lst);
	// TODO ==========================================================================================
}

int main()
{

#if TEST == 0 || TEST == 1

	// constructor_test(1000); // OK Sur linux (juste chiant a afficher)
	constructor_test(10);
	constructor_test(5);
	constructor_test(2);
	constructor_test(1);
	constructor_test(0);

#endif
#if TEST == 0 || TEST == 2

	// iterator_test(1000); // OK Sur linux (juste chiant a afficher)
	iterator_test(10);
	iterator_test(5);
	iterator_test(2);
	iterator_test(1);
	iterator_test(0);

#endif
#if TEST == 0 || TEST == 3

	// capacity_test(1000); // OK Sur linux (juste chiant a afficher)
	capacity_test(10);
	capacity_test(5);
	capacity_test(2);
	capacity_test(1);
	capacity_test(0);

#endif
#if TEST == 0 || TEST == 4

	// element_access_test(1000); // OK Sur linux (juste chiant a afficher)
	element_access_test(10);
	element_access_test(5);
	element_access_test(2);
	element_access_test(1);
	element_access_test(0);

#endif
#if TEST == 0 || TEST == 5

	// modifiers_test(1000); // OK Sur linux (juste chiant a afficher)
	modifiers_test(10);
	modifiers_test(5);
	modifiers_test(2);
	modifiers_test(1);
	modifiers_test(0);

#endif
#if TEST == 0 || TEST == 6

	// modifiers2_test(1000); // OK Sur linux (juste chiant a afficher)
	modifiers2_test(10);
	modifiers2_test(5);
	modifiers2_test(2);
	modifiers2_test(1);
	modifiers2_test(0);

#endif

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