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

	m.insert(std::pair<int, int>(1, 54));
	m.insert(std::pair<int, int>(2, 152));
	m.insert(std::pair<int, int>(3, 10));
	m.insert(std::pair<int, int>(4, 34));
	m.insert(std::pair<int, int>(-1, 34));
	m.insert(std::pair<int, int>(-2, 34));
	m.insert(std::pair<int, int>(9, 34));
	m.insert(std::pair<int, int>(100, 34));
	m.insert(std::pair<int, int>(12, 34));

	m.debug_tree();

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


    end_test();

}