#include "Tester.hpp"

/*

all = 0
constructor_test = 1
iterator_test = 2
capacity_test = 3
element_access_test = 4
modifiers_test = 5
modifiers2_test = 6

*/

#ifndef TEST_LIST
# define TEST_LIST 0
#endif


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

	std_lst_fill = std::list<int>(size, 5);
	ft_lst_fill = ft::List<int>(size, 5);
	describe_list(std_lst_fill, ft_lst_fill);

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

// iterators
	describe_list(std_lst, ft_lst);

// const_iterators
	const_describe_list(std_lst, ft_lst);

// reverse_iterators
	reverse_describe_list(std_lst, ft_lst);

// const_reverse_iterator
	const_reverse_describe_list(std_lst, ft_lst);
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

	title("assign :");
	std_lst.assign(size, size);
	ft_lst.assign(size, size);
	describe_list(std_lst, ft_lst);

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

		title("resize - 1 :");
		std_lst.resize(size - 1);
		ft_lst.resize(size - 1);
		describe_list(std_lst, ft_lst);
	}
	title("resize + 1 :");
	std_lst.resize(size + 1);
	ft_lst.resize(size + 1);
	describe_list(std_lst, ft_lst);

	title("resize == :");
	std_lst.resize(size);
	ft_lst.resize(size);
	describe_list(std_lst, ft_lst);
}

void operator_test(int size)
{
	title("Operator size", size);

	std::list<int> std_lst_a;
    std::list<int> std_lst_b;

	ft::List<int> ft_lst_a;
    ft::List<int> ft_lst_b;

	for (int i = 0; i < size; i++)
	{
		std_lst_a.push_back(i);
		std_lst_b.push_back(i * 10);
		ft_lst_a.push_back(i);
		ft_lst_b.push_back(i * 10);
	}
 
    std::list<int>::iterator std_it = std_lst_a.begin();
    ft::List<int>::iterator ft_it = ft_lst_a.begin();
    
	if (size > 2)
	{
		std::advance(std_it, 2);
		ft_it++;
	    ft_it++;
	}

	describe_list(std_lst_a, ft_lst_a);
	describe_list(std_lst_b, ft_lst_b);
 
    std_lst_a.splice(std_it, std_lst_b);
    ft_lst_a.splice(ft_it, ft_lst_b);

	describe_list(std_lst_a, ft_lst_a);
	describe_list(std_lst_b, ft_lst_b);
	
	std_lst_a.insert(std_lst_a.begin(), size, size);
	ft_lst_a.insert(ft_lst_a.begin(), size, size);

	describe_list(std_lst_a, ft_lst_a);
	describe_list(std_lst_b, ft_lst_b);
	
	// TODO Attention a ne pas tester sans debug sous peine de crash VM (/ Session ?) 

    // std_lst_b.splice(std_lst_b.begin(), std_lst_a, std_lst_a.begin());
    // ft_lst_b.splice(ft_lst_b.begin(), ft_lst_a, ft_lst_a.begin());

	// describe_list(std_lst_a, ft_lst_a);
	// describe_list(std_lst_b, ft_lst_b);
	
	std_lst_a.insert(std_lst_a.begin(), size, size);
	ft_lst_a.insert(ft_lst_a.begin(), size, size);

	describe_list(std_lst_a, ft_lst_a);
	describe_list(std_lst_b, ft_lst_b);
	
    std_lst_b.splice(std_lst_b.begin(), std_lst_a, std_it, std_lst_a.end());
    ft_lst_b.splice(ft_lst_b.begin(), ft_lst_a, ft_it, ft_lst_a.end());

	describe_list(std_lst_a, ft_lst_a);
	describe_list(std_lst_b, ft_lst_b);

}

bool test_max_int(const int lhs, const int rhs) { return (lhs > rhs ? true : false); }
bool test_paire_int(const int lhs) { return (lhs % 2 == 1); }
bool test_paire_int_unique(const int, const int rhs) { return (rhs % 2 == 1); }

void operations2_test(int size)
{
	title("Operations size", size);
	std::list<int> std_lst;
	ft::List<int> ft_lst;
	for (int i = 0; i < size; i++)
	{
		std_lst.push_back(i);
		ft_lst.push_back(i);
	}

	title("remove : 0 (first)");
	std_lst.remove(0);
	ft_lst.remove(0);
	describe_list(std_lst, ft_lst);
	std_lst.clear();
	ft_lst.clear();
	for (int i = 0; i < size; i++)
	{
		std_lst.push_back(i);
		ft_lst.push_back(i);
	}

	title("remove : size (last)");
	std_lst.remove(size - 1);
	ft_lst.remove(size - 1);
	describe_list(std_lst, ft_lst);
	std_lst.clear();
	ft_lst.clear();
	for (int i = 0; i < size; i++)
	{
		std_lst.push_back(i);
		ft_lst.push_back(i);
	}

	title("reverse :");
	std_lst.reverse();
	ft_lst.reverse();
	describe_list(std_lst, ft_lst);

	title("sort :");
	std_lst.sort();
	ft_lst.sort();
	describe_list(std_lst, ft_lst);

	title("sort with Compare :");
	std_lst.sort(test_max_int);
	ft_lst.sort(test_max_int);
	describe_list(std_lst, ft_lst);

	title("removeif :");
	std_lst.remove_if(test_paire_int);
	ft_lst.remove_if(test_paire_int);
	describe_list(std_lst, ft_lst);
}

void operations3_test(int size)
{
	title("Operations - 2 size", size);
	std::list<int> std_lst;
	ft::List<int> ft_lst;

	for (int i = 0; i < size; i++)
	{
		std_lst.push_back(i);
		ft_lst.push_back(i);
	}

	title("merge :");
	std::list<int> std_lst_merge;
	ft::List<int> ft_lst_merge;
	std_lst.sort();
	ft_lst.sort();
	for (int i = 0; i / 2 < size; i++)
	{
		i++;
		std_lst_merge.push_back(i);
		ft_lst_merge.push_back(i);
	}
	describe_list(std_lst, ft_lst);
	describe_list(std_lst_merge, ft_lst_merge);
	std_lst.merge(std_lst_merge);
	ft_lst.merge(ft_lst_merge);
	describe_list(std_lst, ft_lst);
	describe_list(std_lst_merge, ft_lst_merge);
	
	title("merge_comp :");
	std::list<int> std_lst_merge_comp(std_lst);
	ft::List<int> ft_lst_merge_comp(ft_lst);
	describe_list(std_lst_merge_comp, ft_lst_merge_comp);
	std_lst_merge_comp.merge(std_lst, test_max_int);
	ft_lst_merge_comp.merge(ft_lst, test_max_int);
	describe_list(std_lst_merge_comp, ft_lst_merge_comp);

	title("unique :");
	std_lst_merge_comp.unique();
	ft_lst_merge_comp.unique();
	describe_list(std_lst_merge_comp, ft_lst_merge_comp);

	title("unique_comp :");
	std_lst_merge_comp.unique(test_paire_int_unique);
	ft_lst_merge_comp.unique(test_paire_int_unique);
	describe_list(std_lst_merge_comp, ft_lst_merge_comp);
}

int main()
{

#if TEST_LIST == 0 || TEST_LIST == 1

	// constructor_test(1000); // OK Sur linux (juste chiant a afficher)
	constructor_test(10);
	constructor_test(5);
	constructor_test(2);
	constructor_test(1);
	constructor_test(0);

#endif
#if TEST_LIST == 0 || TEST_LIST == 2

	// iterator_test(1000); // OK Sur linux (juste chiant a afficher)
	iterator_test(10);
	iterator_test(5);
	iterator_test(2);
	iterator_test(1);
	iterator_test(0);

#endif
#if TEST_LIST == 0 || TEST_LIST == 3

	// capacity_test(1000); // OK Sur linux (juste chiant a afficher)
	capacity_test(10);
	capacity_test(5);
	capacity_test(2);
	capacity_test(1);
	capacity_test(0);

#endif
#if TEST_LIST == 0 || TEST_LIST == 4

	// element_access_test(1000); // OK Sur linux (juste chiant a afficher)
	element_access_test(10);
	element_access_test(5);
	element_access_test(2);
	element_access_test(1);
	element_access_test(0);

#endif
#if TEST_LIST == 0 || TEST_LIST == 5

	// modifiers_test(1000); // OK Sur linux (juste chiant a afficher)
	modifiers_test(10);
	modifiers_test(5);
	modifiers_test(2);
	modifiers_test(1);
	modifiers_test(0);

#endif
#if TEST_LIST == 0 || TEST_LIST == 6

	// modifiers2_test(1000); // OK Sur linux (juste chiant a afficher)
	modifiers2_test(10);
	modifiers2_test(5);
	modifiers2_test(2);
	modifiers2_test(1);
	modifiers2_test(0);

#endif
#if TEST_LIST == 0 || TEST_LIST == 7

	// operator_test(1000); // OK Sur linux (juste chiant a afficher)
	operator_test(10);
	operator_test(5);
	operator_test(2);
	operator_test(1);
	operator_test(0);
#endif
#if TEST_LIST == 0 || TEST_LIST == 8

	// operations2_test(1000); // OK Sur linux (juste chiant a afficher)
	operations2_test(10);
	operations2_test(5);
	operations2_test(2);
	operations2_test(1);
	operations2_test(0);
#endif
#if TEST_LIST == 0 || TEST_LIST == 9

	// operations3_test(1000); // OK Sur linux (juste chiant a afficher)
	operations3_test(10);
	operations3_test(5);
	operations3_test(2);
	operations3_test(1);
	operations3_test(0);
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