#include "Tester.hpp"

/*

all = 0
constructor_test = 1
iterator_test = 2
capacity_test = 3
element_access_test = 4
modifiers_test = 5
modifiers2_test = 6
operator_test = 7
operations2_test = 8
operations3_test = 9
operators_test = 10

*/

#ifndef TEST_LIST
# define TEST_LIST 0
#endif

template <typename T>
void lstfor(std::list<T> &stdlst, ft::List<T> &ftlst, int size, T type, int)
{
	(void)type;
	for (int i = 0; i < size; i++)
	{
		stdlst.push_back(i);
		ftlst.push_back(i);
	}
	describe_list(stdlst, ftlst);
}

template <typename T>
void lstfor(std::list<T> &stdlst, ft::List<T> &ftlst, int size, T type, void *)
{
	for (int i = 0; i < size; i++)
	{
		stdlst.push_back(type);
		ftlst.push_back(type);
	}
	describe_list(stdlst, ftlst);
}

template <typename T>
void lstforfront(std::list<T> &stdlst, ft::List<T> &ftlst, int size, T type, int)
{
	(void)type;
	for (int i = 0; i < size; i++)
	{
		stdlst.push_front(i);
		ftlst.push_front(i);
	}
	describe_list(stdlst, ftlst);
}

template <typename T>
void lstforfront(std::list<T> &stdlst, ft::List<T> &ftlst, int size, T type, void *)
{
	for (int i = 0; i < size; i++)
	{
		stdlst.push_front(type);
		ftlst.push_front(type);
	}
	describe_list(stdlst, ftlst);
}

template <typename T>
void constructor_test(int size, T type)
{
	title("Constructor size", size);
// default constructor
	title("Default constructor");
	std::list<T> std_lst;
	ft::List<T> ft_lst;
	describe_list(std_lst, ft_lst);

	lstfor(std_lst, ft_lst, size, type, typename ft::is_integral<T>::type());

// fill constructor
	title("Fill constructor");
	std::list<T> std_lst_fill(size);
	ft::List<T> ft_lst_fill(size);
	describe_list(std_lst_fill, ft_lst_fill);

	std_lst_fill = std::list<T>(size, type);
	ft_lst_fill = ft::List<T>(size, type);
	describe_list(std_lst_fill, ft_lst_fill);

// range constructor
	title("Range constructor");
	std::list<T> std_lst_range(std_lst.begin(), std_lst.end());
	ft::List<T> ft_lst_range(ft_lst.begin(), ft_lst.end());
	describe_list(std_lst_range, ft_lst_range);

	title("Range constructor with STL Iterators");
	std::list<T> std_lst_range2(std_lst.begin(), std_lst.end());
	ft::List<T> ft_lst_range2(std_lst.begin(), std_lst.end());
	describe_list(std_lst_range2, ft_lst_range2);

// copy constructor
	title("Copy constructor");
	std::list<T> std_lst_copy(std_lst);
	ft::List<T> ft_lst_copy(ft_lst);
	describe_list(std_lst_copy, ft_lst_copy);


// assignment constructor
	title("assignment operator");
	std::list<T> std_lst_assignment;
	ft::List<T> ft_lst_assignment;
	std_lst_assignment = std_lst_range;
	ft_lst_assignment = ft_lst_range;
	describe_list(std_lst_assignment, ft_lst_assignment);

}

template <typename T>
void iterator_test(int size, T type)
{
	title("Iterator size", size);
	std::list<T> std_lst;
	ft::List<T> ft_lst;

	lstfor(std_lst, ft_lst, size, type, typename ft::is_integral<T>::type());

// iterators
	describe_list(std_lst, ft_lst);

// const_iterators
	const_describe_list(std_lst, ft_lst);

// reverse_iterators
	reverse_describe_list(std_lst, ft_lst);

// const_reverse_iterator
	const_reverse_describe_list(std_lst, ft_lst);
}

template <typename T>
void capacity_test(int size, T type)
{
	title("Capacity size", size);
	std::list<T> std_lst;
	ft::List<T> ft_lst;

	lstfor(std_lst, ft_lst, size, type, typename ft::is_integral<T>::type());

// capacity
	std::stringstream ss_std;
	std::stringstream ss_ft;

	ss_std << "size : " << std_lst.size();
	ss_ft << "size : " << ft_lst.size();
	check(&ss_std, &ss_ft, 0);

	ss_std << "max_size : " << std_lst.max_size();
	ss_ft << "max_size : " << ft_lst.max_size();
	check(&ss_std, &ss_ft, 0);

	ss_std << "empty : " << std_lst.empty();
	ss_ft << "empty : " << ft_lst.empty();
	check(&ss_std, &ss_ft, 0);
}

template <typename T>
void element_access_test(int size, T type)
{
	title("Element_access", size);
	std::list<T> std_lst;
	ft::List<T> ft_lst;

	lstfor(std_lst, ft_lst, size, type, typename ft::is_integral<T>::type());
// element access
	std::stringstream ss_std;
	std::stringstream ss_ft;

	ss_std << "front : " << std_lst.front();
	ss_ft << "front : " << ft_lst.front();
	check(&ss_std, &ss_ft, !size);

	ss_std << "back : " << std_lst.back();
	ss_ft << "back : " << ft_lst.back();
	check(&ss_std, &ss_ft, !size);
}

template <typename T>
void modifiers_test(int size, T type)
{
	title("Modifiers size", size);

	std::list<T> std_lst;
	ft::List<T> ft_lst;

	title("assign :");
	std_lst.assign(size, type);
	ft_lst.assign(size, type);
	describe_list(std_lst, ft_lst);

	std_lst = std::list<T>(size);
	ft_lst = ft::List<T>(size);
	title("initial :");
	describe_list(std_lst, ft_lst);
	std::list<T> std_lst_assign;
	ft::List<T> ft_lst_assign;

	title("assign from iterator :");
	std_lst_assign.assign(std_lst.begin(), std_lst.end());
	ft_lst_assign.assign(ft_lst.begin(), ft_lst.end());
	describe_list(std_lst_assign, ft_lst_assign);

	title("assign from STL iterator :");
	std_lst_assign.assign(std_lst.begin(), std_lst.end());
	ft_lst_assign.assign(std_lst.begin(), std_lst.end());
	describe_list(std_lst_assign, ft_lst_assign);

	title("push_back :");
	std::list<T> std_lst_back;
	ft::List<T> ft_lst_back;
	lstfor(std_lst_back, ft_lst_back, size, type, typename ft::is_integral<T>::type());

	title("push_front :");
	std::list<T> std_lst_front;
	ft::List<T> ft_lst_front;
	lstforfront(std_lst_front, ft_lst_front, size, type, typename ft::is_integral<T>::type());
	
	title("pop_back :");
	if (!std_lst.empty() && !ft_lst.empty())
	{
		std_lst.pop_back();
		ft_lst.pop_back();
		describe_list(std_lst, ft_lst);
	}
	while (!std_lst.empty() && !ft_lst.empty())
	{
		std_lst.pop_back();
		ft_lst.pop_back();
	}
	describe_list(std_lst, ft_lst);

	title("pop_front :");
	if (!std_lst.empty() && !ft_lst.empty())
	{
		std_lst_assign.pop_front();
		ft_lst_assign.pop_front();
		describe_list(std_lst_assign, ft_lst_assign);
	}
	while (!std_lst_assign.empty() && !ft_lst_assign.empty())
	{
		std_lst_assign.pop_front();
		ft_lst_assign.pop_front();
	}
	describe_list(std_lst_assign, ft_lst_assign);
}

template <typename T>
void modifiers2_test(int size, T type)
{
	title("Modifiers size", size);

	std::list<T> std_lst;
	ft::List<T> ft_lst;
	lstfor(std_lst, ft_lst, size, type, typename ft::is_integral<T>::type());

	title("swap :");
	std::list<T> std_lst_swap;
	ft::List<T> ft_lst_swap;
	lstfor(std_lst_swap, ft_lst_swap, size + 10, type, typename ft::is_integral<T>::type());
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
		lstfor(std_lst, ft_lst, size, type, typename ft::is_integral<T>::type());
		std_lst.erase(std_lst.begin());
		ft_lst.erase(ft_lst.begin());
		describe_list(std_lst, ft_lst);
		//erase itr
		title("erase with one itr range :");
		std_lst.clear();
		ft_lst.clear();
		lstfor(std_lst, ft_lst, size, type, typename ft::is_integral<T>::type());
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

template <typename T>
void operations1_test(int size, T type)
{
	title("Operations size", size);

	std::list<T> std_lst_a;
    std::list<T> std_lst_b;

	ft::List<T> ft_lst_a;
    ft::List<T> ft_lst_b;

	lstfor(std_lst_a, ft_lst_a, size, type, typename ft::is_integral<T>::type());
	lstfor(std_lst_b, ft_lst_b, size, type, typename ft::is_integral<T>::type());
 
    typename std::list<T>::iterator std_it = std_lst_a.begin();
    typename ft::List<T>::iterator ft_it = ft_lst_a.begin();
    
	if (size > 2)
	{
		std::advance(std_it, 2);
		ft_it++;
	    ft_it++;
	}

	describe_list(std_lst_a, ft_lst_a);
	describe_list(std_lst_b, ft_lst_b);
 
	title("splice itr, lst :");
    std_lst_a.splice(std_it, std_lst_b);
    ft_lst_a.splice(ft_it, ft_lst_b);

	describe_list(std_lst_a, ft_lst_a);
	describe_list(std_lst_b, ft_lst_b);
	
	title("insert itr, size_t, value :");
	std_lst_a.insert(std_lst_a.begin(), size, type);
	ft_lst_a.insert(ft_lst_a.begin(), size, type);

	describe_list(std_lst_a, ft_lst_a);
	describe_list(std_lst_b, ft_lst_b);
	
	std::list<T> std_lst_a_splice(size + 1, type);
	std::list<T> std_lst_b_splice(size + 3, type);
	ft::List<T> ft_lst_a_splice(size + 1, type);
	ft::List<T> ft_lst_b_splice(size + 3, type);

	title("splice itr, lst, lst_itr :");
	std_lst_b_splice.splice(std_lst_b_splice.begin(), std_lst_a_splice, std_lst_a_splice.begin());
	ft_lst_b_splice.splice(ft_lst_b_splice.begin(), ft_lst_a_splice, ft_lst_a_splice.begin());

	describe_list(std_lst_a_splice, ft_lst_a_splice);
	describe_list(std_lst_b_splice, ft_lst_b_splice);

	title("insert itr, size_t, value :");
	std_lst_a.insert(std_lst_a.begin(), size, type);
	ft_lst_a.insert(ft_lst_a.begin(), size, type);

	describe_list(std_lst_a, ft_lst_a);
	describe_list(std_lst_b, ft_lst_b);
	
	title("splice itr, lst, lst_itr_first, lst_itr_last :");
    std_lst_b.splice(std_lst_b.begin(), std_lst_a, std_it, std_lst_a.end());
    ft_lst_b.splice(ft_lst_b.begin(), ft_lst_a, ft_it, ft_lst_a.end());

	describe_list(std_lst_a, ft_lst_a);
	describe_list(std_lst_b, ft_lst_b);

}

bool test_max_int(const int lhs, const int rhs) { return (lhs > rhs ? true : false); }
bool test_max_troll(const Testclass lhs, const Testclass rhs) {return (lhs > rhs); }
bool test_paire_int(const int lhs) { return (lhs % 2 == 1); }
bool test_paire_int_unique(const int, const int rhs) { return (rhs % 2 == 1); }
static int ble = 0;
bool remhalf(const Testclass tc) { (void)tc; ble++; return (ble % 2); };

void operations2_test(int size)
{
	title("Operations - 2 size", size);
	std::list<int> std_lst;
	ft::List<int> ft_lst;
	lstfor(std_lst, ft_lst, size, 1, 1);

	title("remove : 0 (first)");
	std_lst.remove(0);
	ft_lst.remove(0);
	describe_list(std_lst, ft_lst);
	std_lst.clear();
	ft_lst.clear();
	lstfor(std_lst, ft_lst, size, 1, 1);

	title("remove : size (last)");
	std_lst.remove(size - 1);
	ft_lst.remove(size - 1);
	describe_list(std_lst, ft_lst);
	std_lst.clear();
	ft_lst.clear();
	lstfor(std_lst, ft_lst, size, 1, 1);

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

void operations2_testclass(int size, Testclass type)
{
	title("Operations - 2 class size", size);
	std::list<Testclass> std_lst;
	ft::List<Testclass> ft_lst;
	lstfor(std_lst, ft_lst, size, type, ft::is_integral<Testclass>::type());

	title("reverse :");
	std_lst.reverse();
	ft_lst.reverse();
	describe_list(std_lst, ft_lst);

	title("sort :");
	if (size > 1)
	{
		(*(++std_lst.begin())).str = "zblebasesort";
		(*(++ft_lst.begin())).str = "zblebasesort";
	}
	std_lst.sort();
	ft_lst.sort();
	describe_list(std_lst, ft_lst);

	title("sort with Compare :");
	if (size > 1)
	{
		(*(++std_lst.begin())).str = "ble2";
		(*(++ft_lst.begin())).str = "ble2";
	}
	std_lst.sort(test_max_troll);
	ft_lst.sort(test_max_troll);
	describe_list(std_lst, ft_lst);

	title("removeif : 1 out of 2");
	ble = 0;
	std_lst.remove_if(remhalf);
	ble = 0;
	ft_lst.remove_if(remhalf);
	describe_list(std_lst, ft_lst);

	title("remove : type (aka 'all')");
	std_lst.remove(type);
	ft_lst.remove(type);
	describe_list(std_lst, ft_lst);
}

void operations3_test(int size)
{
	title("Operations - 3 size", size);
	std::list<int> std_lst;
	ft::List<int> ft_lst;
	lstfor(std_lst, ft_lst, size, 1, 1);
	
	title("merge :");
	std::list<int> std_lst_merge;
	ft::List<int> ft_lst_merge;
	std_lst.sort();
	ft_lst.sort();
	lstfor(std_lst, ft_lst, size, 1, 1);
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

void operations3_testclass(int size, Testclass type)
{
	title("Operations - 3 class size", size);
	std::list<Testclass> std_lst;
	ft::List<Testclass> ft_lst;
	std::list<Testclass> std_lst_merge;
	ft::List<Testclass> ft_lst_merge;
	lstfor(std_lst, ft_lst, size, type, ft::is_integral<Testclass>::type());
	lstfor(std_lst_merge, ft_lst_merge, size, type, ft::is_integral<Testclass>::type());

	title("merge :");
	std_lst.sort();
	ft_lst.sort();
	describe_list(std_lst, ft_lst);
	describe_list(std_lst_merge, ft_lst_merge);
	std_lst.merge(std_lst_merge);
	ft_lst.merge(ft_lst_merge);
	describe_list(std_lst, ft_lst);
	describe_list(std_lst_merge, ft_lst_merge);
	
	title("merge_comp :");
	std::list<Testclass> std_lst_merge_comp(std_lst);
	ft::List<Testclass> ft_lst_merge_comp(ft_lst);
	describe_list(std_lst_merge_comp, ft_lst_merge_comp);
	std_lst_merge_comp.merge(std_lst, test_max_troll);
	ft_lst_merge_comp.merge(ft_lst, test_max_troll);
	describe_list(std_lst_merge_comp, ft_lst_merge_comp);

	title("unique :");
	std_lst_merge_comp.unique();
	ft_lst_merge_comp.unique();
	describe_list(std_lst_merge_comp, ft_lst_merge_comp);

	title("unique_comp :");
	std_lst_merge_comp.unique(test_max_troll);
	ft_lst_merge_comp.unique(test_max_troll);
	describe_list(std_lst_merge_comp, ft_lst_merge_comp);
}

void operators_test(int size)
{
	title("Operators size", size);
	std::list<int> std_lst_a;
	std::list<int> std_lst_b;
	ft::List<int> ft_lst_a;
	ft::List<int> ft_lst_b;
	
	for (int i = 0; i < size; i++)
	{
		std_lst_a.push_back(i);
		std_lst_b.push_front(i);
		ft_lst_a.push_back(i);
		ft_lst_b.push_front(i);
	}

	title("operator== :");
	std::stringstream std_ss;
	std::stringstream ft_ss;
	
	std_ss << (std_lst_a == std_lst_a);
	ft_ss << (ft_lst_a == ft_lst_a);
	check(&std_ss, &ft_ss, 0);
	
	std_ss << (std_lst_a == std_lst_b);
	ft_ss << (ft_lst_a == ft_lst_b);
	check(&std_ss, &ft_ss, 0);
	
	title("operator!= :");
	std_ss << (std_lst_a != std_lst_a);
	ft_ss << (ft_lst_a != ft_lst_a);
	check(&std_ss, &ft_ss, 0);
	
	std_ss << (std_lst_a != std_lst_b);
	ft_ss << (ft_lst_a != ft_lst_b);
	check(&std_ss, &ft_ss, 0);
	
	title("operator< :");
	std_ss << (std_lst_a < std_lst_a);
	ft_ss << (ft_lst_a < ft_lst_a);
	check(&std_ss, &ft_ss, 0);
	
	std_ss << (std_lst_a < std_lst_b);
	ft_ss << (ft_lst_a < ft_lst_b);
	check(&std_ss, &ft_ss, 0);
	
	title("operator<= :");
	std_ss << (std_lst_a <= std_lst_a);
	ft_ss << (ft_lst_a <= ft_lst_a);
	check(&std_ss, &ft_ss, 0);
	
	std_ss << (std_lst_a <= std_lst_b);
	ft_ss << (ft_lst_a <= ft_lst_b);
	check(&std_ss, &ft_ss, 0);
	
	title("operator> :");
	std_ss << (std_lst_a > std_lst_a);
	ft_ss << (ft_lst_a > ft_lst_a);
	check(&std_ss, &ft_ss, 0);
	
	std_ss << (std_lst_a > std_lst_b);
	ft_ss << (ft_lst_a > ft_lst_b);
	check(&std_ss, &ft_ss, 0);
	
	title("operator>= :");
	std_ss << (std_lst_a >= std_lst_a);
	ft_ss << (ft_lst_a >= ft_lst_a);
	check(&std_ss, &ft_ss, 0);
	
	std_ss << (std_lst_a >= std_lst_b);
	ft_ss << (ft_lst_a >= ft_lst_b);
	check(&std_ss, &ft_ss, 0);
}

void operators_testclass(int size)
{
	title("Operators size class", size);
	std::list<Testclass> std_lst_a;
	std::list<Testclass> std_lst_b;
	ft::List<Testclass> ft_lst_a;
	ft::List<Testclass> ft_lst_b;
	int r;
	if (size != 0)
		r = rand() % size;
	
	for (int i = 0; i < size; i++)
	{
		std::string s;
		std::stringstream out;
		
		out << i;
		s = out.str();
		std_lst_a.push_back(Testclass(s));
		ft_lst_a.push_back(Testclass(s));

		if (i == r)
			out << i + 1;
		s = out.str();
		std_lst_b.push_back(Testclass(s));
		ft_lst_b.push_back(Testclass(s));
	}

	describe_list(std_lst_a, ft_lst_a);
	describe_list(std_lst_b, ft_lst_b);

	title("operator== :");
	std::stringstream std_ss;
	std::stringstream ft_ss;
	
	std_ss << (std_lst_a == std_lst_a);
	ft_ss << (ft_lst_a == ft_lst_a);
	check(&std_ss, &ft_ss, 0);
	
	std_ss << (std_lst_a == std_lst_b);
	ft_ss << (ft_lst_a == ft_lst_b);
	check(&std_ss, &ft_ss, 0);
	
	title("operator!= :");
	std_ss << (std_lst_a != std_lst_a);
	ft_ss << (ft_lst_a != ft_lst_a);
	check(&std_ss, &ft_ss, 0);
	
	std_ss << (std_lst_a != std_lst_b);
	ft_ss << (ft_lst_a != ft_lst_b);
	check(&std_ss, &ft_ss, 0);
	
	title("operator< :");
	std_ss << (std_lst_a < std_lst_a);
	ft_ss << (ft_lst_a < ft_lst_a);
	check(&std_ss, &ft_ss, 0);
	
	std_ss << (std_lst_a < std_lst_b);
	ft_ss << (ft_lst_a < ft_lst_b);
	check(&std_ss, &ft_ss, 0);
	
	title("operator<= :");
	std_ss << (std_lst_a <= std_lst_a);
	ft_ss << (ft_lst_a <= ft_lst_a);
	check(&std_ss, &ft_ss, 0);
	
	std_ss << (std_lst_a <= std_lst_b);
	ft_ss << (ft_lst_a <= ft_lst_b);
	check(&std_ss, &ft_ss, 0);
	
	title("operator> :");
	std_ss << (std_lst_a > std_lst_a);
	ft_ss << (ft_lst_a > ft_lst_a);
	check(&std_ss, &ft_ss, 0);
	
	std_ss << (std_lst_a > std_lst_b);
	ft_ss << (ft_lst_a > ft_lst_b);
	check(&std_ss, &ft_ss, 0);
	
	title("operator>= :");
	std_ss << (std_lst_a >= std_lst_a);
	ft_ss << (ft_lst_a >= ft_lst_a);
	check(&std_ss, &ft_ss, 0);
	
	std_ss << (std_lst_a >= std_lst_b);
	ft_ss << (ft_lst_a >= ft_lst_b);
	check(&std_ss, &ft_ss, 0);
}

int main()
{
	g_test = 0;
	g_valid = 0;

	std::string str = "bonjour";
	Testclass ble;

#if TEST_LIST == 0 || TEST_LIST == 1

	constructor_test(1000, 5); // OK Sur linux (juste chiant a afficher)
	constructor_test(10, 5);
	constructor_test(5, 5);
	constructor_test(2, 5);
	constructor_test(1, 5);
	constructor_test(0, 5);
	constructor_test(1000, str); // OK Sur linux (juste chiant a afficher)
	constructor_test(10, str);
	constructor_test(5, str);
	constructor_test(2, str);
	constructor_test(1, str);
	constructor_test(0, str);

	constructor_test(1000, ble); // OK Sur linux (juste chiant a afficher)
	constructor_test(10, ble);
	constructor_test(5, ble);
	constructor_test(2, ble);
	constructor_test(1, ble);
	constructor_test(0, ble);

#endif
#if TEST_LIST == 0 || TEST_LIST == 2

	iterator_test(1000, 5); // OK Sur linux (juste chiant a afficher)
	iterator_test(10, 5);
	iterator_test(5, 5);
	iterator_test(2, 5);
	iterator_test(1, 5);
	iterator_test(0, 5);

	iterator_test(1000, str); // OK Sur linux (juste chiant a afficher)
	iterator_test(10, str);
	iterator_test(5, str);
	iterator_test(2, str);
	iterator_test(1, str);
	iterator_test(0, str);

	iterator_test(1000, ble); // OK Sur linux (juste chiant a afficher)
	iterator_test(10, ble);
	iterator_test(5, ble);
	iterator_test(2, ble);
	iterator_test(1, ble);
	iterator_test(0, ble);

#endif
#if TEST_LIST == 0 || TEST_LIST == 3

	capacity_test(1000, 5); // OK Sur linux (juste chiant a afficher)
	capacity_test(10, 5);
	capacity_test(5, 5);
	capacity_test(2, 5);
	capacity_test(1, 5);
	capacity_test(0, 5);

	capacity_test(1000, str); // OK Sur linux (juste chiant a afficher)
	capacity_test(10, str);
	capacity_test(5, str);
	capacity_test(2, str);
	capacity_test(1, str);
	capacity_test(0, str);

	capacity_test(1000, ble); // OK Sur linux (juste chiant a afficher)
	capacity_test(10, ble);
	capacity_test(5, ble);
	capacity_test(2, ble);
	capacity_test(1, ble);
	capacity_test(0, ble);

#endif
#if TEST_LIST == 0 || TEST_LIST == 4

	element_access_test(1000, 5); // OK Sur linux (juste chiant a afficher)
	element_access_test(10, 5);
	element_access_test(5, 5);
	element_access_test(2, 5);
	element_access_test(1, 5);
	element_access_test(0, 5);

	element_access_test(1000, str); // OK Sur linux (juste chiant a afficher)
	element_access_test(10, str);
	element_access_test(5, str);
	element_access_test(2, str);
	element_access_test(1, str);
	element_access_test(0, str);

	element_access_test(1000, ble); // OK Sur linux (juste chiant a afficher)
	element_access_test(10, ble);
	element_access_test(5, ble);
	element_access_test(2, ble);
	element_access_test(1, ble);
	element_access_test(0, ble);

#endif
#if TEST_LIST == 0 || TEST_LIST == 5

	modifiers_test(1000, 5); // OK Sur linux (juste chiant a afficher)
	modifiers_test(10, 5);
	modifiers_test(5, 5);
	modifiers_test(2, 5);
	modifiers_test(1, 5);
	modifiers_test(0, 5);

	modifiers_test(1000, str); // OK Sur linux (juste chiant a afficher)
	modifiers_test(10, str);
	modifiers_test(5, str);
	modifiers_test(2, str);
	modifiers_test(1, str);
	modifiers_test(0, str);

	modifiers_test(1000, ble); // OK Sur linux (juste chiant a afficher)
	modifiers_test(10, ble);
	modifiers_test(5, ble);
	modifiers_test(2, ble);
	modifiers_test(1, ble);
	modifiers_test(0, ble);

#endif
#if TEST_LIST == 0 || TEST_LIST == 6

	modifiers2_test(1000, 5); // OK Sur linux (juste chiant a afficher)
	modifiers2_test(10, 5);
	modifiers2_test(5, 5);
	modifiers2_test(2, 5);
	modifiers2_test(1, 5);
	modifiers2_test(0, 5);

	modifiers2_test(1000, str); // OK Sur linux (juste chiant a afficher)
	modifiers2_test(10, str);
	modifiers2_test(5, str);
	modifiers2_test(2, str);
	modifiers2_test(1, str);
	modifiers2_test(0, str);

	modifiers2_test(1000, ble); // OK Sur linux (juste chiant a afficher)
	modifiers2_test(10, ble);
	modifiers2_test(5, ble);
	modifiers2_test(2, ble);
	modifiers2_test(1, ble);
	modifiers2_test(0, ble);

#endif
#if TEST_LIST == 0 || TEST_LIST == 7

	operations1_test(1000, 5); // OK Sur linux (juste chiant a afficher)
	operations1_test(10, 5);
	operations1_test(5, 5);
	operations1_test(2, 5);
	operations1_test(1, 5);
	operations1_test(0, 5);

	operations1_test(1000, str); // OK Sur linux (juste chiant a afficher)
	operations1_test(10, str);
	operations1_test(5, str);
	operations1_test(2, str);
	operations1_test(1, str);
	operations1_test(0, str);

	operations1_test(1000, ble); // OK Sur linux (juste chiant a afficher)
	operations1_test(10, ble);
	operations1_test(5, ble);
	operations1_test(2, ble);
	operations1_test(1, ble);
	operations1_test(0, ble);
#endif
#if TEST_LIST == 0 || TEST_LIST == 8

	operations2_test(1000); // OK Sur linux (juste chiant a afficher)
	operations2_test(10);
	operations2_test(5);
	operations2_test(2);
	operations2_test(1);
	operations2_test(0);

	operations2_testclass(1000, ble);
	operations2_testclass(10,ble);
	operations2_testclass(5, ble);
	operations2_testclass(2, ble);
	operations2_testclass(1, ble);
	operations2_testclass(0, ble);

#endif
#if TEST_LIST == 0 || TEST_LIST == 9

	operations3_test(1000); // OK Sur linux (juste chiant a afficher)
	operations3_test(10);
	operations3_test(5);
	operations3_test(2);
	operations3_test(1);
	operations3_test(0);

	operations3_testclass(1000, ble); // OK Sur linux (juste chiant a afficher)
	operations3_testclass(10, ble);
	operations3_testclass(5, ble);
	operations3_testclass(2, ble);
	operations3_testclass(1, ble);
	operations3_testclass(0, ble);
#endif
#if TEST_LIST == 0 || TEST_LIST == 10

	operators_test(1000); // OK Sur linux (juste chiant a afficher)
	operators_test(10);
	operators_test(5);
	operators_test(2);
	operators_test(1);
	operators_test(0);

	operators_testclass(1000); // OK Sur linux (juste chiant a afficher)
	operators_testclass(10);
	operators_testclass(5);
	operators_testclass(2);
	operators_testclass(1);
	operators_testclass(0);

#endif

	end_test();

}
