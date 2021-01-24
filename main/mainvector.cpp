
#include "Tester.hpp"

void constructor_test(int size)
{
	title("Constructor Size", size);

	title("Default Constructor :");
	std::vector<int> std_vec;
	ft::Vector<int> ft_vec;
	
	describe_vector(std_vec, ft_vec);

	title("Allocator Constructor :");
	std_vec = std::vector<int>(std::allocator<int>());
	ft_vec = ft::Vector<int>(std::allocator<int>());

	describe_vector(std_vec, ft_vec);

	title("Size and Value Constructor :");
	std_vec = std::vector<int>(size, size);
	ft_vec = ft::Vector<int>(size, size);

	describe_vector(std_vec, ft_vec);

	std_vec = std::vector<int>(static_cast<std::size_t>(size), static_cast<std::size_t>(size));
	ft_vec = ft::Vector<int>(static_cast<std::size_t>(size), static_cast<std::size_t>(size));

	describe_vector(std_vec, ft_vec);

	title("Range Constructor :");
	std::vector<int> std_vec_bis(std_vec.begin(), std_vec.end());
	ft::Vector<int> ft_vec_bis(ft_vec.begin(), ft_vec.end());

	describe_vector(std_vec_bis, ft_vec_bis);

	title("Copy Constructor :");
	std_vec = std::vector<int>(std_vec_bis);
	ft_vec = ft::Vector<int>(ft_vec_bis);

	describe_vector(std_vec, ft_vec);
	
	std_vec = std::vector<int>();
	ft_vec = ft::Vector<int>();

	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(size - i);
		ft_vec.push_back(size - i);
	}

	title("Assignment Operator :");
	title("Before assignment :");
	describe_vector(std_vec, ft_vec);

	std_vec = std_vec_bis;
	ft_vec = ft_vec_bis;

	title("After assignment :");
	describe_vector(std_vec, ft_vec);
	title("Assign (count, value) :");

	std_vec.clear();
	ft_vec.clear();
	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(size);
		ft_vec.push_back(size);
	}

	std_vec.assign(size, size);
	ft_vec.assign(size, size);

	describe_vector(std_vec, ft_vec);

	std_vec.clear();
	ft_vec.clear();
	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(size - i);
		ft_vec.push_back(size - i);
	}

	std_vec.assign(static_cast<std::size_t>(size), static_cast<std::size_t>(size));
	ft_vec.assign(static_cast<std::size_t>(size), static_cast<std::size_t>(size));

	describe_vector(std_vec, ft_vec);
	title("Assign (range) :");

	std_vec.clear();
	ft_vec.clear();
	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(size - i);
		ft_vec.push_back(size - i);
	}

	std_vec.assign(std_vec_bis.begin(), std_vec_bis.end());
	ft_vec.assign(ft_vec_bis.begin(), ft_vec_bis.end());
	describe_vector(std_vec, ft_vec);
}

void element_access_test(int size) {(void)size;}
void iterator_test(int size) {(void)size;}
void capacity_test(int size) {(void)size;}
void modifiers_test(int size) {(void)size;}

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

#if TEST_VECTOR == 0 || TEST_VECTOR == 5
    operator_test(1000); // OK Sur linux (juste chiant a afficher)
	operator_test(10);
	operator_test(5);
	operator_test(2);
	operator_test(1);
	operator_test(0);
#endif

    end_test();
}