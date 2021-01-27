#include "Tester.hpp"

bool test_max_int(const int lhs) { return (lhs > 12 ? true : false); }

void constructor_test(int size)
{
	title("Constructor size", size);


	title("Defaut constructor");
	std::map<std::string, int> std_map;
	ft::Map<std::string, int> ft_map;

	// describe_map(std_map, ft_map);

}

// void map_test(int size)
// {
//     title("Map", size);
	
// 	std::map<char, std::string> std_map;
// 	ft::Map<char, std::string> ft_map;
// 	std_map['a'] = "str1" ;
// 	std_map['b'] = "str1" ;
// 	std_map['a'] = "str1" ;
// 	ft_map['a'] = "str1" ;

// 	std::map<char, std::string> m;
// 	m['a'] = "str1" ;
// 	m['b'] = "str2" ;
// 	m['c'] = "str3" ;
//     std::pair<char,std::string> last = *m.rbegin(); 
//     std::map<char,std::string>::iterator i = m.begin(); 

// 	std::map<char, int> m2;
// 	m2['b'] = 26 ;
// 	m2['y'] = 24 ;
// 	m2['t'] = 25 ;
// 	m2['u'] = 23 ;
// 	m2['u'] = 24 ;
// 	m2['d'] = 13 ;
// 	m2['c'] = 11 ;
// 	m2['e'] = 12 ;
// 	m2['a'] = 14 ;

//     std::pair<char,int> last2 = *m2.rbegin(); 
//     std::map<char,int>::iterator i2 = m2.begin(); 
  
//     std::cout
// 		<< "Map contains "
// 		<< "following elements"
// 	<< std::endl; 
//     do { 
//         std::cout
// 			<< i->first
// 			<< " = "
// 			<< i->second
// 		<< std::endl; 
//     } while (m.value_comp()(*i++, last)); 


// 	  std::cout << "Map2 contains " << "following elements" << std::endl; 
//     do { 
//         std::cout << i2->first << " = " << i2->second << std::endl; 
//     } while (m2.value_comp()(*i2++, last2));
  
// }

int main()
{
#if TEST_MAP == 0 || TEST_MAP == 1
# ifndef SIZE
    constructor_test(1000);
	constructor_test(10);
	constructor_test(5);
	constructor_test(2);
	constructor_test(1);
	constructor_test(0);
# else
	constructor_test(SIZE);
# endif
#endif
    // constructor_test(1000); // OK Sur linux (juste chiant a afficher)
	// map_test(10);
	// map_test(5);
	// map_test(2);
	// map_test(1);
	// map_test(0);

	ft::Map<int, int> m;
	std::map<int, int> mstd;

	mstd.insert(std::pair<int, int>(1, 54));
	mstd.insert(std::pair<int, int>(2, 152));
	mstd.insert(std::pair<int, int>(3, 10));
	mstd.insert(std::pair<int, int>(4, 34));
	mstd.insert(std::pair<int, int>(-1, 34));
	mstd.insert(std::pair<int, int>(-2, 34));
	mstd.insert(std::pair<int, int>(9, 34));
	mstd.insert(std::pair<int, int>(100, 34));
	mstd.insert(std::pair<int, int>(12, 34));
	mstd.insert(std::pair<int, int>(5, 34));
	mstd.insert(std::pair<int, int>(6, 34));
	mstd.insert(std::pair<int, int>(7, 34));
	mstd.insert(std::pair<int, int>(8, 34));
	mstd.insert(std::pair<int, int>(8, 35));

	m.insert(std::pair<int, int>(1, 54));
	m.insert(std::pair<int, int>(2, 152));
	m.insert(std::pair<int, int>(3, 10));
	m.insert(std::pair<int, int>(4, 34));
	m.insert(std::pair<int, int>(-1, 34));
	m.insert(std::pair<int, int>(-2, 34));
	m.insert(std::pair<int, int>(9, 34));
	m.insert(std::pair<int, int>(100, 34));
	m.insert(std::pair<int, int>(12, 34));
	m.insert(std::pair<int, int>(5, 34));
	m.insert(std::pair<int, int>(6, 34));
	m.insert(std::pair<int, int>(7, 34));
	m.insert(std::pair<int, int>(8, 34));
	m.insert(std::pair<int, int>(8, 35));

	title("STD MAP:\n");
	for (std::map<int, int>::iterator itr = mstd.begin(); itr != mstd.end(); itr++)
		std::cout << "[ " << itr->first << " : " << itr->second << "]\n";

	title("FT MAP:\n");
	m.debug_tree();


// Size
	std::cout << "std_size : " << mstd.size() << std::endl;
	std::cout << "ft_size : " << m.size() << std::endl;
	
// Operator []
	// std::cout << m[8] << std::endl;
	// std::cout << mstd[8] << std::endl;
	// TODO

// Range
	// std::pair<std::map<int,int>::iterator,std::map<int,int>::iterator> std_ret;
	// std_ret = mstd.equal_range(8);

	// std::cout << "lower bound points to: ";
	// std::cout << std_ret.first->first << " => " << std_ret.first->second << '\n';

	// std::cout << "upper bound points to: ";
	// std::cout << std_ret.second->first << " => " << std_ret.second->second << '\n';


	// std::pair<ft::Map<int,int>::iterator,ft::Map<int,int>::iterator> ft_ret;
	// ft_ret = m.equal_range(8);

	// std::cout << "lower bound points to: ";
	// std::cout << ft_ret.first->first << " => " << ft_ret.first->second << '\n';

	// std::cout << "upper bound points to: ";
	// std::cout << ft_ret.second->first << " => " << ft_ret.second->second << '\n';
	// TODO


// Erase
	title("FT MAP:\n");
	m.erase(1);
	m.debug_tree();

	title("STD MAP:\n");
	mstd.erase(1);
	for (std::map<int, int>::iterator itr = mstd.begin(); itr != mstd.end(); itr++)
		std::cout << "[ " << itr->first << " : " << itr->second << "]\n";

    end_test();

}