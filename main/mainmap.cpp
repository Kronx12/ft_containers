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

	mstd.insert(std::pair<int, int>(10, 1));
	mstd.insert(std::pair<int, int>(5, 2));
	mstd.insert(std::pair<int, int>(3, 3));
	mstd.insert(std::pair<int, int>(2, 4));
	mstd.insert(std::pair<int, int>(4, 5));
	mstd.insert(std::pair<int, int>(7, 6));
	mstd.insert(std::pair<int, int>(6, 7));
	mstd.insert(std::pair<int, int>(8, 8));
	mstd.insert(std::pair<int, int>(15, 9));
	mstd.insert(std::pair<int, int>(13, 10));
	mstd.insert(std::pair<int, int>(12, 11));
	mstd.insert(std::pair<int, int>(14, 12));
	mstd.insert(std::pair<int, int>(17, 13));
	mstd.insert(std::pair<int, int>(16, 14));
	mstd.insert(std::pair<int, int>(18, 15));
	
	m.insert(std::pair<int, int>(10, 1));
	m.insert(std::pair<int, int>(5, 2));
	m.insert(std::pair<int, int>(3, 3));
	m.insert(std::pair<int, int>(2, 4));
	m.insert(std::pair<int, int>(4, 5));
	m.insert(std::pair<int, int>(7, 6));
	m.insert(std::pair<int, int>(6, 7));
	m.insert(std::pair<int, int>(8, 8));
	m.insert(std::pair<int, int>(15, 9));
	m.insert(std::pair<int, int>(13, 10));
	m.insert(std::pair<int, int>(12, 11));
	m.insert(std::pair<int, int>(14, 12));
	m.insert(std::pair<int, int>(17, 13));
	m.insert(std::pair<int, int>(16, 14));
	m.insert(std::pair<int, int>(18, 15));

	title("STD MAP:\n");
	for (std::map<int, int>::iterator itr = mstd.begin(); itr != mstd.end(); itr++)
		std::cout << "[ " << itr->first << " : " << itr->second << "]\n";

	title("FT MAP:\n");
	m.debug_tree();

	std::cout << "std_size : " << mstd.size() << std::endl;
	std::cout << "ft_size : " << m.size() << std::endl;

	title("STD MAP erase big daddy:[10]\n");
	mstd.erase(10);
	for (std::map<int, int>::iterator itr = mstd.begin(); itr != mstd.end(); itr++)
		std::cout << "[ " << itr->first << " : " << itr->second << "]\n";

	title("FT MAP erase big daddy:[10]\n");
	m.erase(10);
	m.debug_tree();

	title("STD MAP erase leftmost loner:[2]\n");
	mstd.erase(2);
	for (std::map<int, int>::iterator itr = mstd.begin(); itr != mstd.end(); itr++)
		std::cout << "[ " << itr->first << " : " << itr->second << "]\n";

	title("FT MAP erase leftmost loner:[2]\n");
	m.erase(2);
	m.debug_tree();

	title("STD MAP erase leftmost parent(rightchild):[3]\n");
	mstd.erase(3);
	for (std::map<int, int>::iterator itr = mstd.begin(); itr != mstd.end(); itr++)
		std::cout << "[ " << itr->first << " : " << itr->second << "]\n";

	title("FT MAP erase leftmost parent(rightchild):[3]\n");
	m.erase(3);
	m.debug_tree();

	title("STD MAP erase rightmost loner:[18]\n");
	mstd.erase(18);
	for (std::map<int, int>::iterator itr = mstd.begin(); itr != mstd.end(); itr++)
		std::cout << "[ " << itr->first << " : " << itr->second << "]\n";

	title("FT MAP erase rightmost loner:[18]\n");
	m.erase(18);
	m.debug_tree();

	title("STD MAP erase rightmost parent(leftchild):[17]\n");
	mstd.erase(17);
	for (std::map<int, int>::iterator itr = mstd.begin(); itr != mstd.end(); itr++)
		std::cout << "[ " << itr->first << " : " << itr->second << "]\n";

	title("FT MAP erase rightmost parent(leftchild):[17]\n");
	m.erase(17);
	m.debug_tree();

	title("STD MAP erase non existing:[18]\n");
	mstd.erase(18);
	for (std::map<int, int>::iterator itr = mstd.begin(); itr != mstd.end(); itr++)
		std::cout << "[ " << itr->first << " : " << itr->second << "]\n";

	title("FT MAP erase non existing:[18]\n");
	m.erase(18);
	m.debug_tree();

	title("STD MAP erase spam:\n");
	mstd.erase(6);
	mstd.erase(13);
	mstd.erase(15);
	mstd.erase(8);
	for (std::map<int, int>::iterator itr = mstd.begin(); itr != mstd.end(); itr++)
		std::cout << "[ " << itr->first << " : " << itr->second << "]\n";

	title("FT MAP erase spam:\n");
	m.erase(6);
	m.erase(13);
	m.erase(15);
	m.erase(8);
	m.debug_tree();


    end_test();
}