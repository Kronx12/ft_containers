
#include "Tester.hpp"

void constructor_test(int size)
{
	std::vector<int> std_vec;
	ft::Vector<int> ft_vec;

	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(i);
		ft_vec.push_back(i);
	}
	// for (std::vector<int>::iterator itr = std_vec.begin(); itr != std_vec.end(); itr++)
	// 	std::cout << *itr << std::endl;

	// for (std::vector<int>::reverse_iterator itr = std_vec.rbegin(); itr != std_vec.rend(); itr++)
	// 	std::cout << *itr << std::endl;

	for (ft::Vector<int>::iterator itr = ft_vec.begin(); itr != ft_vec.end(); itr++)
	{
		std::cout << itr._size << " " << itr._data << " " << itr._index << std::endl;
		std::cout << *itr << std::endl;
	}

	for (ft::Vector<int>::reverse_iterator itr = ft_vec.rbegin(); itr != ft_vec.rend(); itr++)
		std::cout << *itr << std::endl;
}

int main()
{
    // constructor_test(1000); // OK Sur linux (juste chiant a afficher)
	 constructor_test(10);
	// constructor_test(5);
	// constructor_test(2);
	// constructor_test(1);
	// constructor_test(0);

    end_test();

}