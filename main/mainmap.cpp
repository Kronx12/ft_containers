#include "Tester.hpp"

void constructor_test(int size)
{
	title("Constructor Size", size);

	title("Defaut constructor");
	std::map<int, int> std_map;
	ft::Map<int, int> ft_map;
	describe_map(std_map, ft_map);

	// TODO Replace random par 0->Size quand auto balancing
	for (int i = 0; i < size; i++)
		put_random(std_map, ft_map);
	ft_map.put_tree();
	title("");
	describe_map(std_map, ft_map);

	title("Range constructor :");
	std::map<int, int> std_map_range(std_map.begin(), std_map.end());
	ft::Map<int, int> ft_map_range(ft_map.begin(), ft_map.end());
	describe_map(std_map_range, ft_map_range);

	title("Copy constructor :");
	std::map<int, int> std_map_copy(std_map);
	ft::Map<int, int> ft_map_copy(ft_map);
	describe_map(std_map_copy, ft_map_copy);

	title("Assignement operator :");
	std::map<int, int> std_map_assign;
	ft::Map<int, int> ft_map_assign;
	std_map_assign = std_map;
	ft_map_assign = ft_map;
	describe_map(std_map_assign, ft_map_assign);
}

void iterator_test(int size)
{
	title("Iterator Size", size);

	std::map<int, int> std_map;
	ft::Map<int, int> ft_map;

	// TODO Replace random par 0->Size quand auto balancing
	for (int i = 0; i < size; i++)
		put_random(std_map, ft_map);
	ft_map.put_tree();
	title("");
	describe_map(std_map, ft_map);

	std::stringstream ss_std;
	std::stringstream ss_ft;

	title("Begin - End :");
	ss_std << "- ";
	ss_ft << "- ";
	for (std::map<int, int>::iterator itr = std_map.begin(); itr != std_map.end(); itr++)
		ss_std << "{ " << itr->first << " : " << itr->second << " } ";
	for (ft::Map<int, int>::iterator itr = ft_map.begin(); itr != ft_map.end(); itr++)
		ss_ft << "{ " << itr->first << " : " << itr->second << " } ";
	check(&ss_std, &ss_ft, DEFINED);

	title("Const Begin - Const End :");
	ss_std << "- ";
	ss_ft << "- ";
	for (std::map<int, int>::const_iterator itr = std_map.begin(); itr != std_map.end(); itr++)
		ss_std << "{ " << itr->first << " : " << itr->second << " } ";
	for (ft::Map<int, int>::const_iterator itr = ft_map.begin(); itr != ft_map.end(); itr++)
		ss_ft << "{ " << itr->first << " : " << itr->second << " } ";
	check(&ss_std, &ss_ft, DEFINED);

	title("Reverse Begin - Reverse End :");
	ss_std << "- ";
	ss_ft << "- ";
	for (std::map<int, int>::reverse_iterator itr = std_map.rbegin(); itr != std_map.rend(); itr++)
		ss_std << "{ " << itr->first << " : " << itr->second << " } ";
	for (ft::Map<int, int>::reverse_iterator itr = ft_map.rbegin(); itr != ft_map.rend(); itr++)
		ss_ft << "{ " << itr->first << " : " << itr->second << " } ";
	check(&ss_std, &ss_ft, DEFINED);

	title("Const Reverse Begin - Const Reverse End :");
	ss_std << "- ";
	ss_ft << "- ";
	for (std::map<int, int>::const_reverse_iterator itr = std_map.rbegin(); itr != std_map.rend(); itr++)
		ss_std << "{ " << itr->first << " : " << itr->second << " } ";
	for (ft::Map<int, int>::const_reverse_iterator itr = ft_map.rbegin(); itr != ft_map.rend(); itr++)
		ss_ft << "{ " << itr->first << " : " << itr->second << " } ";
	check(&ss_std, &ss_ft, DEFINED);
}

void capacity_test(int size)
{
	title("Capacity Size", size);

	std::map<int, int> std_map;
	ft::Map<int, int> ft_map;

	std::stringstream ss_std;
	std::stringstream ss_ft;

	title("Empty (true) :");
	ss_std << "- Empty(" << std_map.empty() << ")";
	ss_ft << "- Empty(" << ft_map.empty() << ")";
	check(&ss_std, &ss_ft, DEFINED);

	// TODO Replace random par 0->Size quand auto balancing
	for (int i = 0; i < size; i++)
		put_random(std_map, ft_map);
	ft_map.put_tree();
	title("");
	describe_map(std_map, ft_map);

	title("Empty (false) :");
	ss_std << "- Empty(" << std_map.empty() << ")";
	ss_ft << "- Empty(" << ft_map.empty() << ")";
	check(&ss_std, &ss_ft, DEFINED);

	title("Size :");
	ss_std << "- Size(" << std_map.size() << ")";
	ss_ft << "- Size(" << ft_map.size() << ")";
	check(&ss_std, &ss_ft, DEFINED);

	title("Max_Size (false) :");
	ss_std << "- Max_Size(" << std_map.max_size() << ")";
	ss_ft << "- Max_Size(" << ft_map.max_size() << ")";
	check(&ss_std, &ss_ft, DEFINED);
}

void element_access(int size)
{
	title("Element_Access Size", size);

	std::map<int, int> std_map;
	ft::Map<int, int> ft_map;

	std::stringstream ss_std;
	std::stringstream ss_ft;

	// TODO Replace random par 0->Size quand auto balancing
	for (int i = 0; i < size; i++)
		put_random(std_map, ft_map);
	ft_map.put_tree();
	title("");
	describe_map(std_map, ft_map);

	ss_std << "- ";
	ss_ft << "- ";
	for (std::map<int, int>::iterator itr = std_map.begin(); itr != std_map.end(); itr++)
		ss_std << std_map[itr->first] << ", ";
	for (ft::Map<int, int>::iterator itr = ft_map.begin(); itr != ft_map.end(); itr++)
		ss_ft << ft_map[itr->first] << ", ";
	check(&ss_std, &ss_ft, DEFINED);
}

void modifiers_test(int size)
{
	title("Modifiers Size", size);

	std::map<int, int> std_map;
	ft::Map<int, int> ft_map;
	std::map<int, int> std_map_bis;
	ft::Map<int, int> ft_map_bis;

	// TODO Replace random par 0->Size quand auto balancing
	for (int i = 0; i < size; i++)
		put_random(std_map, ft_map);
	title("After Insert (Value) :");
	ft_map.put_tree();
	describe_map(std_map, ft_map);

	std_map_bis.insert(std_map.begin(), std_map.end());
	ft_map_bis.insert(ft_map.begin(), ft_map.end());
	title("After Insert (First, Last) : ");
	ft_map_bis.put_tree();
	describe_map(std_map_bis, ft_map_bis);

	// TODO Heap-Use-After-Free
	// while (!std_map.empty())
	// 	std_map.erase(std_map.begin());
	// while (!ft_map.empty())
	// 	ft_map.erase(ft_map.begin());
	// title("After Erase (Position) : ");
	// ft_map_bis.put_tree();
	// describe_map(std_map, ft_map);
}

int main()
{
	// Init Random
	srand(static_cast<unsigned int>(time(NULL)));

#if TEST_MAP == 0 || TEST_MAP == 1
# ifndef SIZE
    constructor_test(100);
	constructor_test(10);
	constructor_test(5);
	constructor_test(2);
	constructor_test(1);
	constructor_test(0);
# else
	constructor_test(SIZE);
# endif
#endif

#if TEST_MAP == 0 || TEST_MAP == 2
# ifndef SIZE
    iterator_test(100);
	iterator_test(10);
	iterator_test(5);
	iterator_test(2);
	iterator_test(1);
	iterator_test(0);
# else
	iterator_test(SIZE);
# endif
#endif

#if TEST_MAP == 0 || TEST_MAP == 3
# ifndef SIZE
    capacity_test(100);
	capacity_test(10);
	capacity_test(5);
	capacity_test(2);
	capacity_test(1);
	capacity_test(0);
# else
	capacity_test(SIZE);
# endif
#endif

#if TEST_MAP == 0 || TEST_MAP == 4
# ifndef SIZE
    element_access(100);
	element_access(10);
	element_access(5);
	element_access(2);
	element_access(1);
	element_access(0);
# else
	element_access(SIZE);
# endif
#endif

#if TEST_MAP == 0 || TEST_MAP == 5
# ifndef SIZE
    modifiers_test(100);
	modifiers_test(10);
	modifiers_test(5);
	modifiers_test(2);
	modifiers_test(1);
	modifiers_test(0);
# else
	modifiers_test(SIZE);
# endif
#endif

    end_test();
}