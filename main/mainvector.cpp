
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

	describe_vector(std_vec, ft_vec);

	std_vec.insert(std_vec.begin(), size, size);
	ft_vec.insert(ft_vec.begin(), size, size);

	describe_vector(std_vec, ft_vec);

	std_vec.erase(std_vec.begin());
	ft_vec.erase(ft_vec.begin());

	describe_vector(std_vec, ft_vec);
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