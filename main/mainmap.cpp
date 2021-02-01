#include "Tester.hpp"

void constructor_test(int size)
{
	title("Constructor Size", size);

	title("Defaut constructor");
	std::map<int, int> std_map;
	ft::Map<int, int> ft_map;
	describe_map(std_map, ft_map);

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

void constructor_test_str(int size)
{
	title("Constructor (Str) Size", size);

	title("Defaut constructor");
	std::map<std::string, std::string> std_map;
	ft::Map<std::string, std::string> ft_map;
	describe_map(std_map, ft_map);

	for (int i = 0; i < size; i++)
		put_random_str(std_map, ft_map);
	ft_map.put_tree();
	title("");
	describe_map(std_map, ft_map);

	title("Range constructor :");
	std::map<std::string, std::string> std_map_range(std_map.begin(), std_map.end());
	ft::Map<std::string, std::string> ft_map_range(ft_map.begin(), ft_map.end());
	describe_map(std_map_range, ft_map_range);

	title("Copy constructor :");
	std::map<std::string, std::string> std_map_copy(std_map);
	ft::Map<std::string, std::string> ft_map_copy(ft_map);
	describe_map(std_map_copy, ft_map_copy);

	title("Assignement operator :");
	std::map<std::string, std::string> std_map_assign;
	ft::Map<std::string, std::string> ft_map_assign;
	std_map_assign = std_map;
	ft_map_assign = ft_map;
	describe_map(std_map_assign, ft_map_assign);
}

void constructor_test_class(int size)
{
	title("Constructor (Class) Size", size);

	title("Defaut constructor");
	std::map<Testclass, Testclass> std_map;
	ft::Map<Testclass, Testclass> ft_map;
	describe_map(std_map, ft_map);

	for (int i = 0; i < size; i++)
		put_random_class(std_map, ft_map);
	ft_map.put_tree();
	title("");
	describe_map(std_map, ft_map);

	title("Range constructor :");
	std::map<Testclass, Testclass> std_map_range(std_map.begin(), std_map.end());
	ft::Map<Testclass, Testclass> ft_map_range(ft_map.begin(), ft_map.end());
	describe_map(std_map_range, ft_map_range);

	title("Copy constructor :");
	std::map<Testclass, Testclass> std_map_copy(std_map);
	ft::Map<Testclass, Testclass> ft_map_copy(ft_map);
	describe_map(std_map_copy, ft_map_copy);

	title("Assignement operator :");
	std::map<Testclass, Testclass> std_map_assign;
	ft::Map<Testclass, Testclass> ft_map_assign;
	std_map_assign = std_map;
	ft_map_assign = ft_map;
	describe_map(std_map_assign, ft_map_assign);
}

void iterator_test(int size)
{
	title("Iterator Size", size);

	std::map<int, int> std_map;
	ft::Map<int, int> ft_map;

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

void iterator_test_str(int size)
{
	title("Iterator (Str) Size", size);

	std::map<std::string, std::string> std_map;
	ft::Map<std::string, std::string> ft_map;

	for (int i = 0; i < size; i++)
		put_random_str(std_map, ft_map);
	ft_map.put_tree();
	title("");
	describe_map(std_map, ft_map);

	std::stringstream ss_std;
	std::stringstream ss_ft;

	title("Begin - End :");
	ss_std << "- ";
	ss_ft << "- ";
	for (std::map<std::string, std::string>::iterator itr = std_map.begin(); itr != std_map.end(); itr++)
		ss_std << "{ " << itr->first << " : " << itr->second << " } ";
	for (ft::Map<std::string, std::string>::iterator itr = ft_map.begin(); itr != ft_map.end(); itr++)
		ss_ft << "{ " << itr->first << " : " << itr->second << " } ";
	check(&ss_std, &ss_ft, DEFINED);

	title("Const Begin - Const End :");
	ss_std << "- ";
	ss_ft << "- ";
	for (std::map<std::string, std::string>::const_iterator itr = std_map.begin(); itr != std_map.end(); itr++)
		ss_std << "{ " << itr->first << " : " << itr->second << " } ";
	for (ft::Map<std::string, std::string>::const_iterator itr = ft_map.begin(); itr != ft_map.end(); itr++)
		ss_ft << "{ " << itr->first << " : " << itr->second << " } ";
	check(&ss_std, &ss_ft, DEFINED);

	title("Reverse Begin - Reverse End :");
	ss_std << "- ";
	ss_ft << "- ";
	for (std::map<std::string, std::string>::reverse_iterator itr = std_map.rbegin(); itr != std_map.rend(); itr++)
		ss_std << "{ " << itr->first << " : " << itr->second << " } ";
	for (ft::Map<std::string, std::string>::reverse_iterator itr = ft_map.rbegin(); itr != ft_map.rend(); itr++)
		ss_ft << "{ " << itr->first << " : " << itr->second << " } ";
	check(&ss_std, &ss_ft, DEFINED);

	title("Const Reverse Begin - Const Reverse End :");
	ss_std << "- ";
	ss_ft << "- ";
	for (std::map<std::string, std::string>::const_reverse_iterator itr = std_map.rbegin(); itr != std_map.rend(); itr++)
		ss_std << "{ " << itr->first << " : " << itr->second << " } ";
	for (ft::Map<std::string, std::string>::const_reverse_iterator itr = ft_map.rbegin(); itr != ft_map.rend(); itr++)
		ss_ft << "{ " << itr->first << " : " << itr->second << " } ";
	check(&ss_std, &ss_ft, DEFINED);
}

void iterator_test_class(int size)
{
	title("Iterator (Class) Size", size);

	std::map<Testclass, Testclass> std_map;
	ft::Map<Testclass, Testclass> ft_map;

	for (int i = 0; i < size; i++)
		put_random_class(std_map, ft_map);
	ft_map.put_tree();
	title("");
	describe_map(std_map, ft_map);

	std::stringstream ss_std;
	std::stringstream ss_ft;

	title("Begin - End :");
	ss_std << "- ";
	ss_ft << "- ";
	for (std::map<Testclass, Testclass>::iterator itr = std_map.begin(); itr != std_map.end(); itr++)
		ss_std << "{ " << itr->first << " : " << itr->second << " } ";
	for (ft::Map<Testclass, Testclass>::iterator itr = ft_map.begin(); itr != ft_map.end(); itr++)
		ss_ft << "{ " << itr->first << " : " << itr->second << " } ";
	check(&ss_std, &ss_ft, DEFINED);

	title("Const Begin - Const End :");
	ss_std << "- ";
	ss_ft << "- ";
	for (std::map<Testclass, Testclass>::const_iterator itr = std_map.begin(); itr != std_map.end(); itr++)
		ss_std << "{ " << itr->first << " : " << itr->second << " } ";
	for (ft::Map<Testclass, Testclass>::const_iterator itr = ft_map.begin(); itr != ft_map.end(); itr++)
		ss_ft << "{ " << itr->first << " : " << itr->second << " } ";
	check(&ss_std, &ss_ft, DEFINED);

	title("Reverse Begin - Reverse End :");
	ss_std << "- ";
	ss_ft << "- ";
	for (std::map<Testclass, Testclass>::reverse_iterator itr = std_map.rbegin(); itr != std_map.rend(); itr++)
		ss_std << "{ " << itr->first << " : " << itr->second << " } ";
	for (ft::Map<Testclass, Testclass>::reverse_iterator itr = ft_map.rbegin(); itr != ft_map.rend(); itr++)
		ss_ft << "{ " << itr->first << " : " << itr->second << " } ";
	check(&ss_std, &ss_ft, DEFINED);

	title("Const Reverse Begin - Const Reverse End :");
	ss_std << "- ";
	ss_ft << "- ";
	for (std::map<Testclass, Testclass>::const_reverse_iterator itr = std_map.rbegin(); itr != std_map.rend(); itr++)
		ss_std << "{ " << itr->first << " : " << itr->second << " } ";
	for (ft::Map<Testclass, Testclass>::const_reverse_iterator itr = ft_map.rbegin(); itr != ft_map.rend(); itr++)
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

void capacity_test_str(int size)
{
	title("Capacity (Str) Size", size);

	std::map<std::string, std::string> std_map;
	ft::Map<std::string, std::string> ft_map;

	std::stringstream ss_std;
	std::stringstream ss_ft;

	title("Empty (true) :");
	ss_std << "- Empty(" << std_map.empty() << ")";
	ss_ft << "- Empty(" << ft_map.empty() << ")";
	check(&ss_std, &ss_ft, DEFINED);

	for (int i = 0; i < size; i++)
		put_random_str(std_map, ft_map);
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

void capacity_test_class(int size)
{
	title("Capacity (Class) Size", size);

	std::map<Testclass, Testclass> std_map;
	ft::Map<Testclass, Testclass> ft_map;

	std::stringstream ss_std;
	std::stringstream ss_ft;

	title("Empty (true) :");
	ss_std << "- Empty(" << std_map.empty() << ")";
	ss_ft << "- Empty(" << ft_map.empty() << ")";
	check(&ss_std, &ss_ft, DEFINED);

	for (int i = 0; i < size; i++)
		put_random_class(std_map, ft_map);
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

void element_access_str(int size)
{
	title("Element_Access (Str) Size", size);

	std::map<std::string, std::string> std_map;
	ft::Map<std::string, std::string> ft_map;

	std::stringstream ss_std;
	std::stringstream ss_ft;

	for (int i = 0; i < size; i++)
		put_random_str(std_map, ft_map);
	ft_map.put_tree();
	title("");
	describe_map(std_map, ft_map);

	ss_std << "- ";
	ss_ft << "- ";
	for (std::map<std::string, std::string>::iterator itr = std_map.begin(); itr != std_map.end(); itr++)
		ss_std << std_map[itr->first] << ", ";
	for (ft::Map<std::string, std::string>::iterator itr = ft_map.begin(); itr != ft_map.end(); itr++)
		ss_ft << ft_map[itr->first] << ", ";
	check(&ss_std, &ss_ft, DEFINED);
}

void element_access_class(int size)
{
	title("Element_Access (Class) Size", size);

	std::map<Testclass, Testclass> std_map;
	ft::Map<Testclass, Testclass> ft_map;

	std::stringstream ss_std;
	std::stringstream ss_ft;

	for (int i = 0; i < size; i++)
		put_random_class(std_map, ft_map);
	ft_map.put_tree();
	title("");
	describe_map(std_map, ft_map);

	ss_std << "- ";
	ss_ft << "- ";
	for (std::map<Testclass, Testclass>::iterator itr = std_map.begin(); itr != std_map.end(); itr++)
		ss_std << std_map[itr->first] << ", ";
	for (ft::Map<Testclass, Testclass>::iterator itr = ft_map.begin(); itr != ft_map.end(); itr++)
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

	std::stringstream ss_std;
	std::stringstream ss_ft;

	if (size > 2)
	{
		for (int i = 0; i < size; i++)
			put_random(std_map, ft_map);
		title("After Insert (Value) :");
		int v = rand() % 10000;
		std_map_bis.insert(++std_map.begin(), std::pair<int, int>(v, v));
		ft_map_bis.insert(++ft_map.begin(), std::pair<int, int>(v, v));
		ft_map.put_tree();
		describe_map(std_map, ft_map);
	}

	std_map_bis.insert(std_map.begin(), std_map.end());
	ft_map_bis.insert(std_map.begin(), std_map.end());
	title("After Insert (First, Last) : ");
	ft_map_bis.put_tree();
	describe_map(std_map_bis, ft_map_bis);

	ft_map_bis.clear();
	ft_map_bis.insert(std_map_bis.begin(), std_map_bis.end());
	title("After Insert (First, Last (With std iterator)) : ");
	ft_map_bis.put_tree();
	describe_map(std_map_bis, ft_map_bis);

	int v = rand() % 10000;
	std_map_bis.insert(std_map_bis.begin(), std::pair<int, int>(v, v));
	ft_map_bis.insert(ft_map_bis.begin(), std::pair<int, int>(v, v));
	title("After Insert (First, Value) : ");
	ft_map_bis.put_tree();
	describe_map(std_map_bis, ft_map_bis);

	while (!std_map.empty())
		std_map.erase(std_map.begin());
	while (!ft_map.empty())
		ft_map.erase(ft_map.begin());
	title("After Erase (Position) : ");
	ft_map_bis.put_tree();
	describe_map(std_map, ft_map);

	for (int i = 0; i < size; i++)
		put_random(std_map, ft_map);

	title("Empty (false) :");
	ss_std << "- Empty(" << std_map.empty() << ")";
	ss_ft << "- Empty(" << ft_map.empty() << ")";
	check(&ss_std, &ss_ft, DEFINED);
	std_map.clear();
	ft_map.put_tree();
	ft_map.clear();
	ft_map.put_tree();
	title("Empty (true) :");
	ss_std << "- Empty(" << std_map.empty() << ")";
	ss_ft << "- Empty(" << ft_map.empty() << ")";
	check(&ss_std, &ss_ft, DEFINED);

	title("Swap : ");
	for (int i = 0; i < size; i++)
		put_random(std_map, ft_map);
	describe_map(std_map, ft_map);
	describe_map(std_map_bis, ft_map_bis);
	ft_map.put_tree();
	ft_map_bis.put_tree();
	std_map.swap(std_map_bis);
	ft_map.swap(ft_map_bis);
	describe_map(std_map, ft_map);
	describe_map(std_map_bis, ft_map_bis);
	ft_map.put_tree();
	ft_map_bis.put_tree();
}

void modifiers_test_str(int size)
{
	title("Modifiers (Str) Size", size);

	std::map<std::string, std::string> std_map;
	ft::Map<std::string, std::string> ft_map;
	std::map<std::string, std::string> std_map_bis;
	ft::Map<std::string, std::string> ft_map_bis;

	std::stringstream ss_std;
	std::stringstream ss_ft;

	if (size > 2)
	{
		for (int i = 0; i < size; i++)
			put_random_str(std_map, ft_map);
		title("After Insert (Value) :");
		std::string k = "abcdefghijklmnopqrstuvwxyz0123456789";
		std::random_shuffle(k.begin(), k.end());
		std::string v = "abcdefghijklmnopqrstuvwxyz0123456789";
		std::random_shuffle(v.begin(), v.end());
		k = k.substr(0, 5);
		v = v.substr(0, 5);
		std_map.insert(++std_map.begin(), std::pair<std::string, std::string>(k, v));
		ft_map.insert(++ft_map.begin(), std::pair<std::string, std::string>(k, v));
		ft_map.put_tree();
		describe_map(std_map, ft_map);
	}

	std_map_bis.insert(std_map.begin(), std_map.end());
	ft_map_bis.insert(std_map.begin(), std_map.end());
	title("After Insert (First, Last) : ");
	ft_map_bis.put_tree();
	describe_map(std_map_bis, ft_map_bis);

	ft_map_bis.clear();
	ft_map_bis.insert(std_map_bis.begin(), std_map_bis.end());
	title("After Insert (First, Last (With std iterator)) : ");
	ft_map_bis.put_tree();
	describe_map(std_map_bis, ft_map_bis);

	std::string k = "abcdefghijklmnopqrstuvwxyz0123456789";
	std::random_shuffle(k.begin(), k.end());
	std::string v = "abcdefghijklmnopqrstuvwxyz0123456789";
	std::random_shuffle(v.begin(), v.end());
	k = k.substr(0, 5);
	v = v.substr(0, 5);
	std_map_bis.insert(std_map_bis.begin(), std::pair<std::string, std::string>(k, v));
	ft_map_bis.insert(ft_map_bis.begin(), std::pair<std::string, std::string>(k, v));
	title("After Insert (First, Value) : ");
	ft_map_bis.put_tree();
	describe_map(std_map_bis, ft_map_bis);

	while (!std_map.empty())
		std_map.erase(std_map.begin());
	while (!ft_map.empty())
		ft_map.erase(ft_map.begin());
	title("After Erase (Position) : ");
	ft_map_bis.put_tree();
	describe_map(std_map, ft_map);

	for (int i = 0; i < size; i++)
		put_random_str(std_map, ft_map);

	title("Empty (false) :");
	ss_std << "- Empty(" << std_map.empty() << ")";
	ss_ft << "- Empty(" << ft_map.empty() << ")";
	check(&ss_std, &ss_ft, DEFINED);
	std_map.clear();
	ft_map.put_tree();
	ft_map.clear();
	ft_map.put_tree();
	title("Empty (true) :");
	ss_std << "- Empty(" << std_map.empty() << ")";
	ss_ft << "- Empty(" << ft_map.empty() << ")";
	check(&ss_std, &ss_ft, DEFINED);

	title("Swap : ");
	for (int i = 0; i < size; i++)
		put_random_str(std_map, ft_map);
	describe_map(std_map, ft_map);
	describe_map(std_map_bis, ft_map_bis);
	ft_map.put_tree();
	ft_map_bis.put_tree();
	std_map.swap(std_map_bis);
	ft_map.swap(ft_map_bis);
	describe_map(std_map, ft_map);
	describe_map(std_map_bis, ft_map_bis);
	ft_map.put_tree();
	ft_map_bis.put_tree();
}

void modifiers_test_class(int size)
{
	title("Modifiers (Class) Size", size);

	std::map<Testclass, Testclass> std_map;
	ft::Map<Testclass, Testclass> ft_map;
	std::map<Testclass, Testclass> std_map_bis;
	ft::Map<Testclass, Testclass> ft_map_bis;

	std::stringstream ss_std;
	std::stringstream ss_ft;

	if (size > 2)
	{
		for (int i = 0; i < size; i++)
			put_random_class(std_map, ft_map);
		title("After Insert (Value) :");
		std::string k = "abcdefghijklmnopqrstuvwxyz0123456789";
		std::random_shuffle(k.begin(), k.end());
		std::string v = "abcdefghijklmnopqrstuvwxyz0123456789";
		std::random_shuffle(v.begin(), v.end());
		k = k.substr(0, 5);
		v = v.substr(0, 5);
		Testclass kc(k);
		Testclass vc(v);
		std_map.insert(++std_map.begin(), std::pair<Testclass, Testclass>(k, v));
		ft_map.insert(++ft_map.begin(), std::pair<Testclass, Testclass>(k, v));
		ft_map.put_tree();
		describe_map(std_map, ft_map);
	}

	std_map_bis.insert(std_map.begin(), std_map.end());
	ft_map_bis.insert(std_map.begin(), std_map.end());
	title("After Insert (First, Last) : ");
	ft_map_bis.put_tree();
	describe_map(std_map_bis, ft_map_bis);

	ft_map_bis.clear();
	ft_map_bis.insert(std_map_bis.begin(), std_map_bis.end());
	title("After Insert (First, Last (With std iterator)) : ");
	ft_map_bis.put_tree();
	describe_map(std_map_bis, ft_map_bis);

	std::string k = "abcdefghijklmnopqrstuvwxyz0123456789";
	std::random_shuffle(k.begin(), k.end());
	std::string v = "abcdefghijklmnopqrstuvwxyz0123456789";
	std::random_shuffle(v.begin(), v.end());
	Testclass kc(k);
	Testclass vc(v);
	std_map_bis.insert(std_map_bis.begin(), std::pair<Testclass, Testclass>(k, v));
	ft_map_bis.insert(ft_map_bis.begin(), std::pair<Testclass, Testclass>(k, v));
	title("After Insert (First, Value) : ");
	ft_map_bis.put_tree();
	describe_map(std_map_bis, ft_map_bis);

	while (!std_map.empty())
		std_map.erase(std_map.begin());
	while (!ft_map.empty())
		ft_map.erase(ft_map.begin());
	title("After Erase (Position) : ");
	ft_map_bis.put_tree();
	describe_map(std_map, ft_map);

	for (int i = 0; i < size; i++)
		put_random_class(std_map, ft_map);

	title("Empty (false) :");
	ss_std << "- Empty(" << std_map.empty() << ")";
	ss_ft << "- Empty(" << ft_map.empty() << ")";
	check(&ss_std, &ss_ft, DEFINED);
	std_map.clear();
	ft_map.put_tree();
	ft_map.clear();
	ft_map.put_tree();
	title("Empty (true) :");
	ss_std << "- Empty(" << std_map.empty() << ")";
	ss_ft << "- Empty(" << ft_map.empty() << ")";
	check(&ss_std, &ss_ft, DEFINED);

	title("Swap : ");
	for (int i = 0; i < size; i++)
		put_random_class(std_map, ft_map);
	describe_map(std_map, ft_map);
	describe_map(std_map_bis, ft_map_bis);
	ft_map.put_tree();
	ft_map_bis.put_tree();
	std_map.swap(std_map_bis);
	ft_map.swap(ft_map_bis);
	describe_map(std_map, ft_map);
	describe_map(std_map_bis, ft_map_bis);
	ft_map.put_tree();
	ft_map_bis.put_tree();
}

void operations_test(int size)
{
	title("Operations Size", size);

	std::map<int, int> std_map;
	ft::Map<int, int> ft_map;

	std::stringstream ss_std;
	std::stringstream ss_ft;

	for (int i = 0; i < size; i++)
		put_random(std_map, ft_map);
	describe_map(std_map, ft_map);
	ft_map.put_tree();

	title("Find : ");
	if (std_map.size() > 0)
	{
		std::map<int, int>::iterator itr = std_map.find(std_map.begin()->first);
		std::map<int, int>::iterator itr_b = std_map.find((--(std_map.end()))->first);
		ss_std << "{ " << itr->first << " : " << itr->second << " } ";
		ss_std << "{ " << itr_b->first << " : " << itr_b->second << " } ";
	}
	if (ft_map.size() > 0)
	{
		ft::Map<int, int>::iterator itr = ft_map.find(ft_map.begin()->first);
		ft::Map<int, int>::iterator itr_b = ft_map.find((--(ft_map.end()))->first);
		ss_ft << "{ " << itr->first << " : " << itr->second << " } ";
		ss_ft << "{ " << itr_b->first << " : " << itr_b->second << " } ";
	}
	check(&ss_std, &ss_ft, DEFINED);

	title("Const Find : ");
	if (std_map.size() > 0)
	{
		std::map<int, int>::const_iterator itr = std_map.find(std_map.begin()->first);
		std::map<int, int>::const_iterator itr_b = std_map.find((--(std_map.end()))->first);
		ss_std << "{ " << itr->first << " : " << itr->second << " } ";
		ss_std << "{ " << itr_b->first << " : " << itr_b->second << " } ";
	}
	if (ft_map.size() > 0)
	{
		ft::Map<int, int>::const_iterator itr = ft_map.find(ft_map.begin()->first);
		ft::Map<int, int>::const_iterator itr_b = ft_map.find((--(ft_map.end()))->first);
		ss_ft << "{ " << itr->first << " : " << itr->second << " } ";
		ss_ft << "{ " << itr_b->first << " : " << itr_b->second << " } ";
	}
	check(&ss_std, &ss_ft, DEFINED);

	title("Count : ");
	if (std_map.size() > 0)
	{
		std::map<int, int>::size_type ret = std_map.count(std_map.begin()->first);
		std::map<int, int>::size_type ret_b = std_map.count((--(std_map.end()))->first);
		std::map<int, int>::size_type ret_c = std_map.count(-1);
		ss_std << "count : " << ret << " | ";
		ss_std << "count : " << ret_b << " | ";
		ss_std << "count : " << ret_c;
	}
	if (ft_map.size() > 0)
	{
		ft::Map<int, int>::size_type ret = ft_map.count(ft_map.begin()->first);
		ft::Map<int, int>::size_type ret_b = ft_map.count((--(ft_map.end()))->first);
		ft::Map<int, int>::size_type ret_c = ft_map.count(-1);
		ss_ft << "count : " << ret << " | ";
		ss_ft << "count : " << ret_b << " | ";
		ss_ft << "count : " << ret_c;
	}
	check(&ss_std, &ss_ft, DEFINED);

	title("Lower_Bound : ");
	describe_map(std_map, ft_map);
	ft_map.put_tree();
	if (std_map.size() > 0)
	{
		std::map<int, int>::iterator itr_c = std_map.lower_bound(-1);
		ss_std << "lower_bound : " << itr_c->first;
		ft::Map<int, int>::iterator itr_c2 = ft_map.lower_bound(-1);
		ss_ft << "lower_bound : " << itr_c2->first;
		check(&ss_std, &ss_ft, DEFINED);
		
		if (std_map.size() > 1)
		{
			std::map<int, int>::iterator itr_a = std_map.lower_bound(std_map.begin()->first);
			ss_std << "lower_bound : " << itr_a->first;
			ft::Map<int, int>::iterator itr_a2 = ft_map.lower_bound(ft_map.begin()->first);
			ss_ft << "lower_bound : " << itr_a2->first;
			check(&ss_std, &ss_ft, DEFINED);
		}

		int rint = rand();
		if (ft_map.rbegin()->second)
			rint %= ft_map.rbegin()->second;
		std::map<int, int>::iterator itr_b = std_map.lower_bound(rint);
		ft::Map<int, int>::iterator itr_b2 = ft_map.lower_bound(rint);
		if (itr_b != std_map.end() && itr_b2 != ft_map.end())
		{
			ss_std << "lower_bound : " << itr_b->first;
			ss_ft << "lower_bound : " << itr_b2->first;
			check(&ss_std, &ss_ft, DEFINED);
		}
	}

	title("Const Lower_Bound : ");
	describe_map(std_map, ft_map);
	ft_map.put_tree();
	if (std_map.size() > 0)
	{
		std::map<int, int>::const_iterator itr_c = std_map.lower_bound(-1);
		ss_std << "const lower_bound : " << itr_c->first;
		ft::Map<int, int>::const_iterator itr_c2 = ft_map.lower_bound(-1);
		ss_ft << "const lower_bound : " << itr_c2->first;
		check(&ss_std, &ss_ft, DEFINED);
		
		if (std_map.size() > 1)
		{
			std::map<int, int>::const_iterator itr_a = std_map.lower_bound(std_map.begin()->first);
			ss_std << "const lower_bound : " << itr_a->first;
			ft::Map<int, int>::const_iterator itr_a2 = ft_map.lower_bound(ft_map.begin()->first);
			ss_ft << "const lower_bound : " << itr_a2->first;
			check(&ss_std, &ss_ft, DEFINED);
		}

		int rint = rand();
		if (ft_map.rbegin()->second)
			rint %= ft_map.rbegin()->second;
		std::map<int, int>::const_iterator itr_b = std_map.lower_bound(rint);
		ft::Map<int, int>::const_iterator itr_b2 = ft_map.lower_bound(rint);
		if (itr_b != std_map.end() && itr_b2 != ft_map.end())
		{
			ss_std << "const lower_bound : " << itr_b->first;
			ss_ft << "const lower_bound : " << itr_b2->first;
			check(&ss_std, &ss_ft, DEFINED);
		}
	}

	title("Upper_Bound : ");
	describe_map(std_map, ft_map);
	ft_map.put_tree();
	if (std_map.size() > 0)
	{
		std::map<int, int>::iterator itr_c = std_map.upper_bound(-1);
		ss_std << "upper_bound : " << itr_c->first;
		ft::Map<int, int>::iterator itr_c2 = ft_map.upper_bound(-1);
		ss_ft << "upper_bound : " << itr_c2->first;
		check(&ss_std, &ss_ft, DEFINED);
		
		if (std_map.size() > 1)
		{
			std::map<int, int>::iterator itr_a = std_map.upper_bound(std_map.begin()->first); // crash so size =< 1
			ss_std << "upper_bound : " << itr_a->first;
			ft::Map<int, int>::iterator itr_a2 = ft_map.upper_bound(ft_map.begin()->first);
			ss_ft << "upper_bound : " << itr_a2->first;
			check(&ss_std, &ss_ft, DEFINED);
		}

		int rint = rand();
		if (ft_map.rbegin()->second)
			rint %= ft_map.rbegin()->second;
		std::map<int, int>::iterator itr_b = std_map.upper_bound(rint);
		ft::Map<int, int>::iterator itr_b2 = ft_map.upper_bound(rint);
		if (itr_b != std_map.end() && itr_b2 != ft_map.end())
		{
			ss_std << "upper_bound : " << itr_b->first;
			ss_ft << "upper_bound : " << itr_b2->first;
			check(&ss_std, &ss_ft, DEFINED);
		}
	}

	title("Const Upper_Bound : ");
	describe_map(std_map, ft_map);
	ft_map.put_tree();
	if (std_map.size() > 0)
	{
		std::map<int, int>::const_iterator itr_c = std_map.upper_bound(-1);
		ss_std << "const upper_bound : " << itr_c->first;
		ft::Map<int, int>::const_iterator itr_c2 = ft_map.upper_bound(-1);
		ss_ft << "const upper_bound : " << itr_c2->first;
		check(&ss_std, &ss_ft, DEFINED);
		
		if (std_map.size() > 1)
		{
			std::map<int, int>::const_iterator itr_a = std_map.upper_bound(std_map.begin()->first); // crash so size =< 1
			ss_std << "const upper_bound : " << itr_a->first ;
			ft::Map<int, int>::const_iterator itr_a2 = ft_map.upper_bound(ft_map.begin()->first);
			ss_ft  << "const upper_bound : " << itr_a2->first;
			check(&ss_std, &ss_ft, DEFINED);
		}

		int rint = rand();
		if (ft_map.rbegin()->second)
			rint %= ft_map.rbegin()->second;
		std::map<int, int>::const_iterator itr_b = std_map.upper_bound(rint);
		ft::Map<int, int>::const_iterator itr_b2 = ft_map.upper_bound(rint);
		if (itr_b != std_map.end() && itr_b2 != ft_map.end())
		{
			ss_std << "const upper_bound : " << itr_b->first;
			ss_ft << "const upper_bound : " << itr_b2->first;
			check(&ss_std, &ss_ft, DEFINED);
		}
	}

	title("Equal_Range : ");
	describe_map(std_map, ft_map);
	ft_map.put_tree();
	if (std_map.size() > 0)
	{
		std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator>  itr_std_c = std_map.equal_range(-1);
		std::pair<ft::Map<int, int>::iterator, ft::Map<int, int>::iterator> itr_ft_c = ft_map.equal_range(-1);
		ss_std << "equal_range : " << itr_std_c.first->first << " : " << itr_std_c.second->first;
		ss_ft << "equal_range : " << itr_ft_c.first->first << " : " << itr_ft_c.second->first;
		check(&ss_std, &ss_ft, DEFINED);
		if (std_map.size() > 1)
		{
			std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> itr_std_a = std_map.equal_range(std_map.begin()->first);
			std::pair<ft::Map<int, int>::iterator, ft::Map<int, int>::iterator> itr_ft_a = ft_map.equal_range(ft_map.begin()->first);
			ss_std << "equal_range : " << itr_std_a.first->first << " : " << itr_std_a.second->first;
			ss_ft << "equal_range : " << itr_ft_a.first->first << " : " << itr_ft_a.second->first;
			check(&ss_std, &ss_ft, DEFINED);
		}
		int rint = rand();
		if (ft_map.rbegin()->second)
			rint %= ft_map.rbegin()->second;
		std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator>  itr_std_b = std_map.equal_range(rint);
		std::pair<ft::Map<int, int>::iterator, ft::Map<int, int>::iterator> itr_ft_b = ft_map.equal_range(rint);
		if (itr_std_b.first != std_map.end() && itr_std_b.second != std_map.end() && itr_ft_b.first != ft_map.end() && itr_ft_b.second != ft_map.end())
		{
			ss_std << "equal_range : " << itr_std_b.first->first << " : " << itr_std_b.second->first;
			ss_ft << "equal_range : " << itr_ft_b.first->first << " : " << itr_ft_b.second->first;
			check(&ss_std, &ss_ft, DEFINED);
		}
	}

	title("Const Equal_Range : ");
	describe_map(std_map, ft_map);
	ft_map.put_tree();
	if (std_map.size() > 0)
	{
		std::pair<std::map<int, int>::const_iterator, std::map<int, int>::const_iterator>  itr_std_c = std_map.equal_range(-1);
		std::pair<ft::Map<int, int>::const_iterator, ft::Map<int, int>::const_iterator> itr_ft_c = ft_map.equal_range(-1);
		ss_std << "equal_range : " << itr_std_c.first->first << " : " << itr_std_c.second->first;
		ss_ft << "equal_range : " << itr_ft_c.first->first << " : " << itr_ft_c.second->first;
		check(&ss_std, &ss_ft, DEFINED);
		if (std_map.size() > 1)
		{
			std::pair<std::map<int, int>::const_iterator, std::map<int, int>::const_iterator> itr_std_a = std_map.equal_range(std_map.begin()->first);
			std::pair<ft::Map<int, int>::const_iterator, ft::Map<int, int>::const_iterator> itr_ft_a = ft_map.equal_range(ft_map.begin()->first);
			ss_std << "equal_range : " << itr_std_a.first->first << " : " << itr_std_a.second->first;
			ss_ft << "equal_range : " << itr_ft_a.first->first << " : " << itr_ft_a.second->first;
			check(&ss_std, &ss_ft, DEFINED);
		}
		int rint = rand();
		if (ft_map.rbegin()->second)
			rint %= ft_map.rbegin()->second;
		std::pair<std::map<int, int>::const_iterator, std::map<int, int>::const_iterator>  itr_std_b = std_map.equal_range(rint);
		std::pair<ft::Map<int, int>::const_iterator, ft::Map<int, int>::const_iterator> itr_ft_b = ft_map.equal_range(rint);
		if (itr_std_b.first != std_map.end() && itr_std_b.second != std_map.end() && itr_ft_b.first != ft_map.end() && itr_ft_b.second != ft_map.end())
		{
			ss_std << "equal_range : " << itr_std_b.first->first << " : " << itr_std_b.second->first;
			ss_ft << "equal_range : " << itr_ft_b.first->first << " : " << itr_ft_b.second->first;
			check(&ss_std, &ss_ft, DEFINED);
		}
	}
}

void operators_functions(int size)
{
	title("Operators Size", size);

	std::map<int, int> std_map;
	ft::Map<int, int> ft_map;
	std::map<int, int> std_map_bis;
	ft::Map<int, int> ft_map_bis;

	std::stringstream ss_std;
	std::stringstream ss_ft;

	for (int i = 0; i < size; i++)
	{
		put_random(std_map, ft_map);
		put_random(std_map_bis, ft_map_bis);
	}
	ft_map.put_tree();
	ft_map_bis.put_tree();

	title("Operator== (map == map) :");
	ss_std << (std_map == std_map);
	ss_ft << (ft_map == ft_map);
	check(&ss_std, &ss_ft, DEFINED);
	
	title("Operator== (map == map_bis) :");
	ss_std << (std_map == std_map_bis);
	ss_ft << (ft_map == ft_map_bis);
	check(&ss_std, &ss_ft, DEFINED);
	
	title("Operator== (map_bis == map) :");
	ss_std << (std_map_bis == std_map);
	ss_ft << (ft_map_bis == ft_map);
	check(&ss_std, &ss_ft, DEFINED);


	title("Operator!= (map != map) :");
	ss_std << (std_map != std_map);
	ss_ft << (ft_map != ft_map);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator!= (map != map_bis):");
	ss_std << (std_map != std_map_bis);
	ss_ft << (ft_map != ft_map_bis);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator!= (map_bis != map) :");
	ss_std << (std_map_bis != std_map);
	ss_ft << (ft_map_bis != ft_map);
	check(&ss_std, &ss_ft, DEFINED);


	title("Operator< (map < map):");
	ss_std << (std_map < std_map);
	ss_ft << (ft_map < ft_map);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator< (map < map_bis):");
	ss_std << (std_map < std_map_bis);
	ss_ft << (ft_map < ft_map_bis);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator< (map_bis < map):");
	ss_std << (std_map_bis < std_map);
	ss_ft << (ft_map_bis < ft_map);
	check(&ss_std, &ss_ft, DEFINED);
	

	title("Operator<= (map <= map):");
	ss_std << (std_map <= std_map);
	ss_ft << (ft_map <= ft_map);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator<= (map <= map_bis):");
	ss_std << (std_map <= std_map_bis);
	ss_ft << (ft_map <= ft_map_bis);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator<= (map_bis <= map):");
	ss_std << (std_map_bis <= std_map);
	ss_ft << (ft_map_bis <= ft_map);
	check(&ss_std, &ss_ft, DEFINED);
	

	title("Operator> (map > map):");
	ss_std << (std_map > std_map);
	ss_ft << (ft_map > ft_map);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator> (map > map_bis):");
	ss_std << (std_map > std_map_bis);
	ss_ft << (ft_map > ft_map_bis);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator> (map_bis > map):");
	ss_std << (std_map_bis > std_map);
	ss_ft << (ft_map_bis > ft_map);
	check(&ss_std, &ss_ft, DEFINED);


	title("Operator>= (map >= map):");
	ss_std << (std_map >= std_map);
	ss_ft << (ft_map >= ft_map);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator>= (map >= map_bis):");
	ss_std << (std_map >= std_map_bis);
	ss_ft << (ft_map >= ft_map_bis);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator>= (map_bis >= map):");
	ss_std << (std_map_bis >= std_map);
	ss_ft << (ft_map_bis >= ft_map);
	check(&ss_std, &ss_ft, DEFINED);

}

void operators_functions_str(int size)
{
	title("Operators (Str) Size", size);

	std::map<std::string, std::string> std_map;
	ft::Map<std::string, std::string> ft_map;
	std::map<std::string, std::string> std_map_bis;
	ft::Map<std::string, std::string> ft_map_bis;

	std::stringstream ss_std;
	std::stringstream ss_ft;

	for (int i = 0; i < size; i++)
	{
		put_random_str(std_map, ft_map);
		put_random_str(std_map_bis, ft_map_bis);
	}
	ft_map.put_tree();
	ft_map_bis.put_tree();

	title("Operator== (map == map) :");
	ss_std << (std_map == std_map);
	ss_ft << (ft_map == ft_map);
	check(&ss_std, &ss_ft, DEFINED);
	
	title("Operator== (map == map_bis) :");
	ss_std << (std_map == std_map_bis);
	ss_ft << (ft_map == ft_map_bis);
	check(&ss_std, &ss_ft, DEFINED);
	
	title("Operator== (map_bis == map) :");
	ss_std << (std_map_bis == std_map);
	ss_ft << (ft_map_bis == ft_map);
	check(&ss_std, &ss_ft, DEFINED);


	title("Operator!= (map != map) :");
	ss_std << (std_map != std_map);
	ss_ft << (ft_map != ft_map);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator!= (map != map_bis):");
	ss_std << (std_map != std_map_bis);
	ss_ft << (ft_map != ft_map_bis);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator!= (map_bis != map) :");
	ss_std << (std_map_bis != std_map);
	ss_ft << (ft_map_bis != ft_map);
	check(&ss_std, &ss_ft, DEFINED);


	title("Operator< (map < map):");
	ss_std << (std_map < std_map);
	ss_ft << (ft_map < ft_map);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator< (map < map_bis):");
	ss_std << (std_map < std_map_bis);
	ss_ft << (ft_map < ft_map_bis);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator< (map_bis < map):");
	ss_std << (std_map_bis < std_map);
	ss_ft << (ft_map_bis < ft_map);
	check(&ss_std, &ss_ft, DEFINED);
	

	title("Operator<= (map <= map):");
	ss_std << (std_map <= std_map);
	ss_ft << (ft_map <= ft_map);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator<= (map <= map_bis):");
	ss_std << (std_map <= std_map_bis);
	ss_ft << (ft_map <= ft_map_bis);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator<= (map_bis <= map):");
	ss_std << (std_map_bis <= std_map);
	ss_ft << (ft_map_bis <= ft_map);
	check(&ss_std, &ss_ft, DEFINED);
	

	title("Operator> (map > map):");
	ss_std << (std_map > std_map);
	ss_ft << (ft_map > ft_map);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator> (map > map_bis):");
	ss_std << (std_map > std_map_bis);
	ss_ft << (ft_map > ft_map_bis);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator> (map_bis > map):");
	ss_std << (std_map_bis > std_map);
	ss_ft << (ft_map_bis > ft_map);
	check(&ss_std, &ss_ft, DEFINED);


	title("Operator>= (map >= map):");
	ss_std << (std_map >= std_map);
	ss_ft << (ft_map >= ft_map);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator>= (map >= map_bis):");
	ss_std << (std_map >= std_map_bis);
	ss_ft << (ft_map >= ft_map_bis);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator>= (map_bis >= map):");
	ss_std << (std_map_bis >= std_map);
	ss_ft << (ft_map_bis >= ft_map);
	check(&ss_std, &ss_ft, DEFINED);

}

void operators_functions_class(int size)
{
	title("Operators (Class) Size", size);

	std::map<Testclass, Testclass> std_map;
	ft::Map<Testclass, Testclass> ft_map;
	std::map<Testclass, Testclass> std_map_bis;
	ft::Map<Testclass, Testclass> ft_map_bis;

	std::stringstream ss_std;
	std::stringstream ss_ft;

	for (int i = 0; i < size; i++)
	{
		put_random_class(std_map, ft_map);
		put_random_class(std_map_bis, ft_map_bis);
	}
	ft_map.put_tree();
	ft_map_bis.put_tree();

	title("Operator== (map == map) :");
	ss_std << (std_map == std_map);
	ss_ft << (ft_map == ft_map);
	check(&ss_std, &ss_ft, DEFINED);
	
	title("Operator== (map == map_bis) :");
	ss_std << (std_map == std_map_bis);
	ss_ft << (ft_map == ft_map_bis);
	check(&ss_std, &ss_ft, DEFINED);
	
	title("Operator== (map_bis == map) :");
	ss_std << (std_map_bis == std_map);
	ss_ft << (ft_map_bis == ft_map);
	check(&ss_std, &ss_ft, DEFINED);


	title("Operator!= (map != map) :");
	ss_std << (std_map != std_map);
	ss_ft << (ft_map != ft_map);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator!= (map != map_bis):");
	ss_std << (std_map != std_map_bis);
	ss_ft << (ft_map != ft_map_bis);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator!= (map_bis != map) :");
	ss_std << (std_map_bis != std_map);
	ss_ft << (ft_map_bis != ft_map);
	check(&ss_std, &ss_ft, DEFINED);


	title("Operator< (map < map):");
	ss_std << (std_map < std_map);
	ss_ft << (ft_map < ft_map);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator< (map < map_bis):");
	ss_std << (std_map < std_map_bis);
	ss_ft << (ft_map < ft_map_bis);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator< (map_bis < map):");
	ss_std << (std_map_bis < std_map);
	ss_ft << (ft_map_bis < ft_map);
	check(&ss_std, &ss_ft, DEFINED);
	

	title("Operator<= (map <= map):");
	ss_std << (std_map <= std_map);
	ss_ft << (ft_map <= ft_map);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator<= (map <= map_bis):");
	ss_std << (std_map <= std_map_bis);
	ss_ft << (ft_map <= ft_map_bis);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator<= (map_bis <= map):");
	ss_std << (std_map_bis <= std_map);
	ss_ft << (ft_map_bis <= ft_map);
	check(&ss_std, &ss_ft, DEFINED);
	

	title("Operator> (map > map):");
	ss_std << (std_map > std_map);
	ss_ft << (ft_map > ft_map);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator> (map > map_bis):");
	ss_std << (std_map > std_map_bis);
	ss_ft << (ft_map > ft_map_bis);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator> (map_bis > map):");
	ss_std << (std_map_bis > std_map);
	ss_ft << (ft_map_bis > ft_map);
	check(&ss_std, &ss_ft, DEFINED);


	title("Operator>= (map >= map):");
	ss_std << (std_map >= std_map);
	ss_ft << (ft_map >= ft_map);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator>= (map >= map_bis):");
	ss_std << (std_map >= std_map_bis);
	ss_ft << (ft_map >= ft_map_bis);
	check(&ss_std, &ss_ft, DEFINED);

	title("Operator>= (map_bis >= map):");
	ss_std << (std_map_bis >= std_map);
	ss_ft << (ft_map_bis >= ft_map);
	check(&ss_std, &ss_ft, DEFINED);

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

    constructor_test_str(100);
	constructor_test_str(10);
	constructor_test_str(5);
	constructor_test_str(2);
	constructor_test_str(1);
	constructor_test_str(0);

    constructor_test_class(100);
	constructor_test_class(10);
	constructor_test_class(5);
	constructor_test_class(2);
	constructor_test_class(1);
	constructor_test_class(0);
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

    iterator_test_str(100);
	iterator_test_str(10);
	iterator_test_str(5);
	iterator_test_str(2);
	iterator_test_str(1);
	iterator_test_str(0);

    iterator_test_class(100);
	iterator_test_class(10);
	iterator_test_class(5);
	iterator_test_class(2);
	iterator_test_class(1);
	iterator_test_class(0);
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

    capacity_test_str(100);
	capacity_test_str(10);
	capacity_test_str(5);
	capacity_test_str(2);
	capacity_test_str(1);
	capacity_test_str(0);

    capacity_test_class(100);
	capacity_test_class(10);
	capacity_test_class(5);
	capacity_test_class(2);
	capacity_test_class(1);
	capacity_test_class(0);
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

    element_access_str(100);
	element_access_str(10);
	element_access_str(5);
	element_access_str(2);
	element_access_str(1);
	element_access_str(0);

    element_access_class(100);
	element_access_class(10);
	element_access_class(5);
	element_access_class(2);
	element_access_class(1);
	element_access_class(0);
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

    modifiers_test_str(100);
	modifiers_test_str(10);
	modifiers_test_str(5);
	modifiers_test_str(2);
	modifiers_test_str(1);
	modifiers_test_str(0);

    modifiers_test_class(100);
	modifiers_test_class(10);
	modifiers_test_class(5);
	modifiers_test_class(2);
	modifiers_test_class(1);
	modifiers_test_class(0);
# else
	modifiers_test(SIZE);
# endif
#endif

#if TEST_MAP == 0 || TEST_MAP == 6
# ifndef SIZE
    operations_test(100);
	operations_test(10);
	operations_test(5);
	operations_test(2);
	operations_test(1);
	operations_test(0);
# else
	operations_test(SIZE);
# endif
#endif

#if TEST_MAP == 0 || TEST_MAP == 7
# ifndef SIZE
    operators_functions(100);
	operators_functions(10);
	operators_functions(5);
	operators_functions(2);
	operators_functions(1);
	operators_functions(0);

    operators_functions_str(100);
	operators_functions_str(10);
	operators_functions_str(5);
	operators_functions_str(2);
	operators_functions_str(1);
	operators_functions_str(0);

    operators_functions_class(100);
	operators_functions_class(10);
	operators_functions_class(5);
	operators_functions_class(2);
	operators_functions_class(1);
	operators_functions_class(0);
# else
	operators_functions(SIZE);
# endif
#endif

#if TEST_MAP == 0 || TEST_MAP == 8
# ifndef SIZE
	ft::Map<int, int> ft_map;
	for (int i = 0; i < 1000; i++)
		ft_map.insert(std::pair<int, int>(rand(), 0));
	ft_map.put_tree();
# else
	ft::Map<int, int> ft_map;
	for (int i = 0; i < SIZE; i++)
		ft_map.insert(std::pair<int, int>(i, 0));
	ft_map.put_tree();
	ft_map.erase(8);
	ft_map.put_tree();
# endif
#endif

    end_test();
}