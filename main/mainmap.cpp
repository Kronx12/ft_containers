#include "Tester.hpp"

void constructor_test(int size)
{
	title("Constructor Size", size);

	title("Defaut constructor"); // TODO constructor with other parameters (fnct cmp)
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

	std::stringstream ss_std;
	std::stringstream ss_ft;

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

	// int v = rand() % 1000000;
	// std_map_bis.insert(std_map_bis.begin(), std::pair<int, int>(v, v));
	// ft_map_bis.insert(ft_map_bis.begin(), std::pair<int, int>(v, v));
	// title("After Insert (First, Value) : ");
	// ft_map_bis.put_tree();
	// describe_map(std_map_bis, ft_map_bis);

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

void observers_test(int size)
{
	title("Observers Size", size);
	// TODO ?
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

#if TEST_MAP == 0 || TEST_MAP == 6
# ifndef SIZE
    observers_test(100);
	observers_test(10);
	observers_test(5);
	observers_test(2);
	observers_test(1);
	observers_test(0);
# else
	observers_test(SIZE);
# endif
#endif

#if TEST_MAP == 0 || TEST_MAP == 7
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

#if TEST_MAP == 0 || TEST_MAP == 8
# ifndef SIZE
    operators_functions(100);
	operators_functions(10);
	operators_functions(5);
	operators_functions(2);
	operators_functions(1);
	operators_functions(0);
# else
	operators_functions(SIZE);
# endif
#endif

<<<<<<< HEAD
#if TEST_MAP == 0 || TEST_MAP == 9
	ft::Map<int, int> ft_map;
	ft_map.insert(std::pair<int, int>(30, 1));
	ft_map.put_tree();
	ft_map.insert(std::pair<int, int>(50, 3));
	ft_map.put_tree();
	ft_map.insert(std::pair<int, int>(40, 2));
	ft_map.put_tree();
	ft_map.insert(std::pair<int, int>(20, 2));
	ft_map.put_tree();
	ft_map.insert(std::pair<int, int>(10, 2));
	ft_map.put_tree();
	ft_map.insert(std::pair<int, int>(9, 2));
	ft_map.put_tree();
	ft_map.insert(std::pair<int, int>(8, 2));
	ft_map.put_tree();
	ft_map.insert(std::pair<int, int>(7, 2));
	ft_map.put_tree();
	ft_map.insert(std::pair<int, int>(0, 2));
	ft_map.put_tree();
	ft_map.insert(std::pair<int, int>(6, 2));
	ft_map.put_tree();
	ft_map.insert(std::pair<int, int>(-6, 2));
	ft_map.put_tree();
	ft_map.insert(std::pair<int, int>(4, 2));
	ft_map.put_tree();
	ft_map.insert(std::pair<int, int>(-4, 2));
	ft_map.put_tree();
	ft_map.insert(std::pair<int, int>(5, 2));
	ft_map.put_tree();
	ft_map.insert(std::pair<int, int>(-5, 2));
	ft_map.put_tree();
#endif
=======
// #if TEST_MAP == 0 || TEST_MAP == 9
	// ft::Map<int, int> ft_map;
	// for (int i = 0; i < 500; i++)
	// 	ft_map.insert(std::pair<int, int>(rand() % 1000, rand() % 1000));
	// ft_map.put_tree();

	// ft_map.insert(std::pair<int, int>(29, 3));
	// ft_map.insert(std::pair<int, int>(7, 2));
	// ft_map.insert(std::pair<int, int>(4, 2));
	// ft_map.insert(std::pair<int, int>(2, 2));
	// ft_map.insert(std::pair<int, int>(18, 2));
	// ft_map.insert(std::pair<int, int>(11, 2));
	// ft_map.insert(std::pair<int, int>(20, 2));
	// ft_map.put_tree();
	// ft_map.insert(std::pair<int, int>(15, 2));
	// ft_map.put_tree();
// #endif

	
>>>>>>> 50afc2926a8019a3e614c46b260e01fa8e0d49bd

    end_test();
}