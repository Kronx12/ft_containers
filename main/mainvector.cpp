
#include "Tester.hpp"

void constructor_test(int size)
{
	(void) size;
	std::vector<int> std_vec;
	ft::Vector<int> ft_vec;

	std::cout << std_vec.max_size() << std::endl;
	std::cout << ft_vec.max_size() << std::endl;

	std::vector<std::string> std_vecs;
	ft::Vector<std::string> ft_vecs;

	std::cout << std_vecs.max_size() << std::endl;
	std::cout << ft_vecs.max_size() << std::endl;
}

int main()
{
    constructor_test(1000); // OK Sur linux (juste chiant a afficher)
	// constructor_test(10);
	// constructor_test(5);
	// constructor_test(2);
	// constructor_test(1);
	// constructor_test(0);

    end_test();

}