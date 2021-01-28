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

void test()
{
	std::map<int, int> mstd;
	std::map<std::string, std::string> t;
	ft::Map<int, int> m;

	std::cout << "TEST" << std::endl; 
	// t.insert(std::pair<std::string, std::string>(NULL, NULL));
	t.insert(std::pair<std::string, std::string>("la", "la"));
	t.insert(std::pair<std::string, std::string>("le", "le"));
	for (std::map<std::string, std::string>::iterator itr = t.begin(); itr != t.end(); itr++)
		std::cout << "[ " << itr->first << " : " << itr->second << "]\n";

	mstd.insert(std::pair<int, int>(15, 15));
	mstd.insert(std::pair<int, int>(2, 2));
	mstd.insert(std::pair<int, int>(1, 1));
	mstd.insert(std::pair<int, int>(5, 5));
	mstd.insert(std::pair<int, int>(4, 4));
	mstd.insert(std::pair<int, int>(3, 3));
	mstd.insert(std::pair<int, int>(10, 10));
	mstd.insert(std::pair<int, int>(11, 11));
	mstd.insert(std::pair<int, int>(12, 12));
	mstd.insert(std::pair<int, int>(6, 6));
	mstd.insert(std::pair<int, int>(8, 8));
	mstd.insert(std::pair<int, int>(17, 17));
	mstd.insert(std::pair<int, int>(20, 20));
	mstd.insert(std::pair<int, int>(16, 16));

	m.insert(std::pair<int, int>(15, 15));
	m.insert(std::pair<int, int>(2, 2));
	m.insert(std::pair<int, int>(1, 1));
	m.insert(std::pair<int, int>(5, 5));
	m.insert(std::pair<int, int>(4, 4));
	m.insert(std::pair<int, int>(3, 3));
	m.insert(std::pair<int, int>(10, 10));
	m.insert(std::pair<int, int>(11, 11));
	m.insert(std::pair<int, int>(12, 12));
	m.insert(std::pair<int, int>(6, 6));
	m.insert(std::pair<int, int>(8, 8));
	m.insert(std::pair<int, int>(17, 17));
	m.insert(std::pair<int, int>(20, 20));
	m.insert(std::pair<int, int>(16, 16));

	std::cout << "std" << std::endl;
	for (std::map<int, int>::iterator itr = mstd.begin(); itr != mstd.end(); itr++)
		std::cout << "[ " << itr->first << " : " << itr->second << "]\n";

	std::cout << "ft" << std::endl;
	ft::Map<int, int>::iterator itr = m.begin();
	ft::Map<int, int>::iterator itr2 = m.rbegin();
	std::cout << "ope++" << std::endl;
	for (unsigned long i = 0; i < m.size(); i++)
	{
		std::cout << "[ " << itr->first << " : " << itr->second << "]\n";
		itr++;
	}
	std::cout << "ope--" << std::endl;
	for (unsigned long i = 0; i < m.size(); i++)
	{
		std::cout << "[ " << itr2->first << " : " << itr2->second << "]\n";
		itr2--;
	}


	std::cout << "Upper bound : (std) 7  " << mstd.upper_bound(7)->first << std::endl;
	std::cout << "Upper bound : (ft)  7  " << m.upper_bound(7)->first << std::endl;
	std::cout << "Upper bound : (std) 17 " << mstd.upper_bound(17)->first << std::endl;
	std::cout << "Upper bound : (ft)  17 " << m.upper_bound(17)->first << std::endl;

	std::cout << "Lower bound : (std) 0  " << mstd.lower_bound(0)->first << std::endl;
	std::cout << "Lower bound : (ft)  0  " << m.lower_bound(0)->first << std::endl;
	std::cout << "Lower bound : (std) 7  " << mstd.lower_bound(7)->first << std::endl;
	std::cout << "Lower bound : (ft)  7  " << m.lower_bound(7)->first << std::endl;
	std::cout << "Lower bound : (std) 17 " << mstd.lower_bound(17)->first << std::endl;
	std::cout << "Lower bound : (ft)  17 " << m.lower_bound(17)->first << std::endl;

	std::cout << std::endl << "operator [] " << std::endl;
	std::cout << "std[17] " << mstd[17] << std::endl;
	std::cout << " ft[17] " << m[17] << std::endl;
	std::cout << "std[18] " << mstd[18] << std::endl;
	std::cout << " ft[18] " << m[18] << std::endl;
	mstd[18] = 11;
	m[18] = 11;
	std::cout << "std[18] " << mstd[18] << std::endl;
	std::cout << " ft[18] " << m[18] << std::endl;

	std::cout << std::endl << "find" << std::endl;

	std::cout << "std find 12 " << mstd.find(12)->first << std::endl;
	std::cout << " ft find 12 " << m.find(12)->first << std::endl;
	// std::cout << "std find 13 " << mstd.find(13)->first << std::endl;
	// std::cout << " ft find 13 " << m.find(13)->first << std::endl;


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
// 	m2['y'] = 22 ;
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
	srand(static_cast<unsigned int>(time(NULL)));
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
	std::map<int, int>::iterator itr;
	for (itr = mstd.begin(); itr != mstd.end(); itr++)
		std::cout << "[ " << itr->first << " : " << itr->second << "]\n";
	// itr++;

	title("FT MAP:\n");
	m.put_tree();

// Size

	// title("FT MAP (SIZE):\n");
	// std::cout << "std_size : " << mstd.size() << std::endl;
	// std::cout << "ft_size : " << m.size() << std::endl;

// Operator []
	// std::cout << m[8] << std::endl;
	// std::cout << mstd[8] << std::endl;
	// TODO

	title("STD MAP erase big daddy:[10]\n");
	mstd.erase(10);
	for (std::map<int, int>::iterator itr = mstd.begin(); itr != mstd.end(); itr++)
		std::cout << "[ " << itr->first << " : " << itr->second << "]\n";

	title("FT MAP erase big daddy:[10]\n");
	m.erase(10);
	m.put_tree();

	title("STD MAP erase leftmost loner:[2]\n");
	mstd.erase(2);
	for (std::map<int, int>::iterator itr = mstd.begin(); itr != mstd.end(); itr++)
		std::cout << "[ " << itr->first << " : " << itr->second << "]\n";

	title("FT MAP erase leftmost loner:[2]\n");
	m.erase(2);
	m.put_tree();

	title("STD MAP erase leftmost parent(rightchild):[3]\n");
	mstd.erase(3);
	for (std::map<int, int>::iterator itr = mstd.begin(); itr != mstd.end(); itr++)
		std::cout << "[ " << itr->first << " : " << itr->second << "]\n";

	title("FT MAP erase leftmost parent(rightchild):[3]\n");
	m.erase(3);
	m.put_tree();

	title("STD MAP erase rightmost loner:[18]\n");
	mstd.erase(18);
	for (std::map<int, int>::iterator itr = mstd.begin(); itr != mstd.end(); itr++)
		std::cout << "[ " << itr->first << " : " << itr->second << "]\n";

	title("FT MAP erase rightmost loner:[18]\n");
	m.erase(18);
	m.put_tree();

	title("STD MAP erase rightmost parent(leftchild):[17]\n");
	mstd.erase(17);
	for (std::map<int, int>::iterator itr = mstd.begin(); itr != mstd.end(); itr++)
		std::cout << "[ " << itr->first << " : " << itr->second << "]\n";

	title("FT MAP erase rightmost parent(leftchild):[17]\n");
	m.erase(17);
	m.put_tree();

	title("STD MAP erase non existing:[18]\n");
	mstd.erase(18);
	for (std::map<int, int>::iterator itr = mstd.begin(); itr != mstd.end(); itr++)
		std::cout << "[ " << itr->first << " : " << itr->second << "]\n";

	title("FT MAP erase non existing:[18]\n");
	m.erase(18);
	m.put_tree();

	title("STD MAP erase spam:\n");
	mstd.erase(6);
	mstd.erase(13);
	mstd.erase(15);
	mstd.erase(8);
	for (std::map<int, int>::iterator itr = mstd.begin(); itr != mstd.end(); itr++)
		std::cout << "[ " << itr->first << " : " << itr->second << "]\n";

	title("FT MAP erase spam:[6],[13],[15],[8]\n");
	m.erase(6);
	m.erase(13);
	m.erase(15);
	m.erase(8);
	m.put_tree(10);

	ft::Map<int, int> m2;

	/*m2.insert(std::pair<int, int>(50, 1));
	m2.insert(std::pair<int, int>(25, 2));
	m2.insert(std::pair<int, int>(75, 3));
	m2.insert(std::pair<int, int>(12, 4));
	m2.insert(std::pair<int, int>(62, 5));
	m2.insert(std::pair<int, int>(37, 6));
	m2.insert(std::pair<int, int>(87, 7));
	m2.insert(std::pair<int, int>(6, 8));
	m2.insert(std::pair<int, int>(56, 9));
	m2.insert(std::pair<int, int>(18, 10));
	m2.insert(std::pair<int, int>(68, 11));
	m2.insert(std::pair<int, int>(31, 12));
	m2.insert(std::pair<int, int>(81, 13));
	m2.insert(std::pair<int, int>(43, 14));
	m2.insert(std::pair<int, int>(93, 15));
	m2.insert(std::pair<int, int>(96, 15));
	m2.insert(std::pair<int, int>(90, 15));
	m2.insert(std::pair<int, int>(84, 15));
	m2.insert(std::pair<int, int>(78, 15));
	m2.insert(std::pair<int, int>(71, 15));
	m2.insert(std::pair<int, int>(65, 15));
	m2.insert(std::pair<int, int>(59, 15));
	m2.insert(std::pair<int, int>(53, 15));
	m2.insert(std::pair<int, int>(46, 15));
	m2.insert(std::pair<int, int>(40, 15));
	m2.insert(std::pair<int, int>(34, 15));
	m2.insert(std::pair<int, int>(28, 15));
	m2.insert(std::pair<int, int>(21, 15));
	m2.insert(std::pair<int, int>(15, 15));
	m2.insert(std::pair<int, int>(9, 15));
	m2.insert(std::pair<int, int>(3, 15));
	m2.insert(std::pair<int, int>(1, 15));
	m2.insert(std::pair<int, int>(2, 15));
	m2.insert(std::pair<int, int>(0, 15));
	m2.insert(std::pair<int, int>(5, 15));
	m2.insert(std::pair<int, int>(4, 15));*/
	for (int i = 0; i < 150000; i++)
			m2.insert(std::pair<int, int>(rand(), 15));
	m2.put_tree(1000);

    end_test();
}