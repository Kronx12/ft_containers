
#include "Tester.hpp"

void constructor_test(int size)
{
	title("Constructor Size", size);

	std::vector<int> std_vec;
	ft::Vector<int> ft_vec;

	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(i);
		ft_vec.push_back(i);
	}

	if (!std_vec.empty())
		describe_vector(std_vec, ft_vec);

	std_vec.insert(std_vec.begin(), size, size);
	ft_vec.insert(ft_vec.begin(), size, size);

	describe_vector(std_vec, ft_vec);

	std_vec.insert(std_vec.begin(), std_vec.begin(), std_vec.end());
	ft_vec.insert(ft_vec.begin(), ft_vec.begin(), ft_vec.end());

	describe_vector(std_vec, ft_vec);

	// TODO : ESSAYER De comprendre pk si je call empty()
	// TODO : Sur un std::vector vide qui a subit un pop_back j'ai un bad_alloc
	// TODO : C'est trite aled

	/* 
	TODO	std_vec.pop_back();		
	TODO	ft_vec.pop_back();		
	TODO	describe_vector(std_vec, ft_vec);
	TODO	std::bad_alloc error
	*/

	if (!std_vec.empty())
	{
		std_vec.pop_back();
		ft_vec.pop_back();
		describe_vector(std_vec, ft_vec);
	}

	std::vector<int> std_vec_bis(std_vec);
	ft::Vector<int> ft_vec_bis(ft_vec);

	describe_vector(std_vec, ft_vec);

	std_vec.swap(std_vec_bis);
	ft_vec.swap(ft_vec_bis);
}
void test_test(int size)
{
	title("Operator Size", size);

	std::vector<int> std_vector;
	ft::Vector<int> ft_vector;

	for (int i = 0; i < size; i++)
	{
		std_vector.push_back(i);
		ft_vector.push_back(i);
	}

	describe_vector(std_vector, ft_vector);

	std::cout << *std_vector.erase(std_vector.begin(), ++(std_vector.begin())) << std::endl;
	std::cout << *ft_vector.erase(ft_vector.begin(), ++(ft_vector.begin())) << std::endl;

	describe_vector(std_vector, ft_vector);

	std::cout << *std_vector.erase(std_vector.begin(), std_vector.end()) << std::endl;
	std::cout << *ft_vector.erase(ft_vector.begin(), ft_vector.end()) << std::endl;

	describe_vector(std_vector, ft_vector);

}

void operator_test(int size)
{
	title("Operator Size", size);

	std::vector<int> std_vector;
	std::vector<int> std_vector_bis;
	ft::Vector<int> ft_vector;
	ft::Vector<int> ft_vector_bis;

	for (int i = 0; i < size; i++)
	{
		std_vector.push_back(i);
		std_vector_bis.push_back(size - i);
		ft_vector.push_back(i);
		ft_vector_bis.push_back(size - i);
	}

	title("std_vector | ft_vector :");
	describe_vector(std_vector, ft_vector);
	title("std_vector_bis | ft_vector_bis :");
	describe_vector(std_vector_bis, ft_vector_bis);

	std::stringstream std_ss;
	std::stringstream ft_ss;

	title("Operator (vector | vector_bis) != :");
	std_ss << (std_vector != std_vector_bis);
	ft_ss << (ft_vector != ft_vector_bis);
	check(&std_ss, &ft_ss, 0);

	title("Operator (vector | vector) != :");
	std_ss << (std_vector != std_vector);
	ft_ss << (ft_vector != ft_vector);
	check(&std_ss, &ft_ss, 0);

	title("Operator (vector_bis | vector) != :");
	std_ss << (std_vector_bis != std_vector);
	ft_ss << (ft_vector_bis != ft_vector);
	check(&std_ss, &ft_ss, 0);



	title("Operator (vector | vector_bis) < :");
	std_ss << (std_vector < std_vector_bis);
	ft_ss << (ft_vector < ft_vector_bis);
	check(&std_ss, &ft_ss, 0);

	title("Operator (vector | vector) < :");
	std_ss << (std_vector < std_vector);
	ft_ss << (ft_vector < ft_vector);
	check(&std_ss, &ft_ss, 0);

	title("Operator (vector_bis | vector) < :");
	std_ss << (std_vector_bis < std_vector);
	ft_ss << (ft_vector_bis < ft_vector);
	check(&std_ss, &ft_ss, 0);



	title("Operator (vector | vector_bis) <= :");
	std_ss << (std_vector <= std_vector_bis);
	ft_ss << (ft_vector <= ft_vector_bis);
	check(&std_ss, &ft_ss, 0);

	title("Operator (vector | vector) <= :");
	std_ss << (std_vector <= std_vector);
	ft_ss << (ft_vector <= ft_vector);
	check(&std_ss, &ft_ss, 0);

	title("Operator (vector_bis | vector) <= :");
	std_ss << (std_vector_bis <= std_vector);
	ft_ss << (ft_vector_bis <= ft_vector);
	check(&std_ss, &ft_ss, 0);



	title("Operator (vector | vector_bis) > :");
	std_ss << (std_vector > std_vector_bis);
	ft_ss << (ft_vector > ft_vector_bis);
	check(&std_ss, &ft_ss, 0);

	title("Operator (vector | vector) > :");
	std_ss << (std_vector > std_vector);
	ft_ss << (ft_vector > ft_vector);
	check(&std_ss, &ft_ss, 0);

	title("Operator (vector_bis | vector) > :");
	std_ss << (std_vector_bis > std_vector);
	ft_ss << (ft_vector_bis > ft_vector);
	check(&std_ss, &ft_ss, 0);



	title("Operator (vector | vector_bis) >= :");
	std_ss << (std_vector >= std_vector_bis);
	ft_ss << (ft_vector >= ft_vector_bis);
	check(&std_ss, &ft_ss, 0);

	title("Operator (vector | vector) >= :");
	std_ss << (std_vector >= std_vector);
	ft_ss << (ft_vector >= ft_vector);
	check(&std_ss, &ft_ss, 0);

	title("Operator (vector_bis | vector) >= :");
	std_ss << (std_vector_bis >= std_vector);
	ft_ss << (ft_vector_bis >= ft_vector);
	check(&std_ss, &ft_ss, 0);
}

int main()
{

#if TEST_VECTOR == 0 || TEST_VECTOR == 1
    // constructor_test(1000); // OK Sur linux (juste chiant a afficher)
	constructor_test(10);
	constructor_test(5);
	constructor_test(2);
	constructor_test(1);
	constructor_test(0);
#endif

#if TEST_VECTOR == 0 || TEST_VECTOR == 2
    operator_test(1000); // OK Sur linux (juste chiant a afficher)
	operator_test(10);
	operator_test(5);
	operator_test(2);
	operator_test(1);
	operator_test(0);
#endif

#if TEST_VECTOR == 0 || TEST_VECTOR == 3
    // test_test(1000); // OK Sur linux (juste chiant a afficher)
	test_test(10);
	// test_test(5);
	// test_test(2);
	// test_test(1);
	// test_test(0);
#endif

    end_test();
}