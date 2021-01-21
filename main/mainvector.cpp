
#include "Tester.hpp"

void constructor_test(int size)
{
	(void) size;
	std::vector<int> std_vec;
	ft::Vector<int> ft_vec;

	std_vec[0];
	ft_vec[0];
}

int main()
{
    
    // constructor_test(1000); // OK Sur linux (juste chiant a afficher)
	constructor_test(10);
	constructor_test(5);
	constructor_test(2);
	constructor_test(1);
	constructor_test(0);

    end_test();

}