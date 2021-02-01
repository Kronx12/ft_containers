#include "Tester.hpp"

// TODO Test Class
// TODO Test String
// TODO Test STD_Iterator

void constructor_test(int size)
{
	title("Constructor (Int) Size", size);

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

void constructor_test_str(int size)
{
	std::string str = "str_global";
	title("Constructor (Str) Size", size);

	title("Default Constructor :");
	std::vector<std::string> std_vec;
	ft::Vector<std::string> ft_vec;
	
	describe_vector(std_vec, ft_vec);

	title("Allocator Constructor :");
	std_vec = std::vector<std::string>(std::allocator<std::string>());
	ft_vec = ft::Vector<std::string>(std::allocator<std::string>());

	describe_vector(std_vec, ft_vec);

	title("Size and Value Constructor :");
	std_vec = std::vector<std::string>(size, str);
	ft_vec = ft::Vector<std::string>(size, str);

	describe_vector(std_vec, ft_vec);

	title("Range Constructor :");
	std::vector<std::string> std_vec_bis(std_vec.begin(), std_vec.end());
	ft::Vector<std::string> ft_vec_bis(ft_vec.begin(), ft_vec.end());

	describe_vector(std_vec_bis, ft_vec_bis);

	title("Copy Constructor :");
	std_vec = std::vector<std::string>(std_vec_bis);
	ft_vec = ft::Vector<std::string>(ft_vec_bis);

	describe_vector(std_vec, ft_vec);
	
	std_vec = std::vector<std::string>();
	ft_vec = ft::Vector<std::string>();

	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(str);
		ft_vec.push_back(str);
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
		std_vec.push_back(str);
		ft_vec.push_back(str);
	}

	std_vec.assign(size, str);
	ft_vec.assign(size, str);

	describe_vector(std_vec, ft_vec);

	std_vec.clear();
	ft_vec.clear();
	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(str);
		ft_vec.push_back(str);
	}

	describe_vector(std_vec, ft_vec);
	title("Assign (range) :");

	std_vec.clear();
	ft_vec.clear();
	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(str);
		ft_vec.push_back(str);
	}

	std_vec.assign(std_vec_bis.begin(), std_vec_bis.end());
	ft_vec.assign(ft_vec_bis.begin(), ft_vec_bis.end());
	describe_vector(std_vec, ft_vec);
}

void constructor_test_class(int size)
{
	Testclass c;
	title("Constructor (Class) Size", size);

	title("Default Constructor :");
	std::vector<Testclass> std_vec;
	ft::Vector<Testclass> ft_vec;
	
	describe_vector(std_vec, ft_vec);

	title("Allocator Constructor :");
	std_vec = std::vector<Testclass>(std::allocator<Testclass>());
	ft_vec = ft::Vector<Testclass>(std::allocator<Testclass>());

	describe_vector(std_vec, ft_vec);

	title("Size and Value Constructor :");
	std_vec = std::vector<Testclass>(size, c);
	ft_vec = ft::Vector<Testclass>(size, c);

	describe_vector(std_vec, ft_vec);

	title("Range Constructor :");
	std::vector<Testclass> std_vec_bis(std_vec.begin(), std_vec.end());
	ft::Vector<Testclass> ft_vec_bis(ft_vec.begin(), ft_vec.end());

	describe_vector(std_vec_bis, ft_vec_bis);

	title("Copy Constructor :");
	std_vec = std::vector<Testclass>(std_vec_bis);
	ft_vec = ft::Vector<Testclass>(ft_vec_bis);

	describe_vector(std_vec, ft_vec);
	
	std_vec = std::vector<Testclass>();
	ft_vec = ft::Vector<Testclass>();

	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(c);
		ft_vec.push_back(c);
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
		std_vec.push_back(c);
		ft_vec.push_back(c);
	}

	std_vec.assign(size, c);
	ft_vec.assign(size, c);

	describe_vector(std_vec, ft_vec);

	std_vec.clear();
	ft_vec.clear();
	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(c);
		ft_vec.push_back(c);
	}

	describe_vector(std_vec, ft_vec);
	title("Assign (range) :");

	std_vec.clear();
	ft_vec.clear();
	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(c);
		ft_vec.push_back(c);
	}

	std_vec.assign(std_vec_bis.begin(), std_vec_bis.end());
	ft_vec.assign(ft_vec_bis.begin(), ft_vec_bis.end());
	describe_vector(std_vec, ft_vec);
}

void element_access_test(int size)
{
	title("Element Access Size", size);
	std::vector<int> std_vec;	
	ft::Vector<int> ft_vec;	

	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(i);
		ft_vec.push_back(i);
	}

	std::stringstream std_ss;
	std::stringstream ft_ss;
	for (int i = 0; i < size; i++)
	{
		std_ss << "[" << i << "]: " << std_vec.at(i) << " ";
		ft_ss << "[" << i << "]: " << ft_vec.at(i) << " ";
	}

	title("At :");
	check(&std_ss, &ft_ss, 0);

	for (int i = 0; i < size; i++)
	{
		std_ss << "[" << i << "]: " << std_vec[i] << " ";
		ft_ss << "[" << i << "]: " << ft_vec[i] << " ";
	}
	title("Operator [] :");
	check(&std_ss, &ft_ss, 0);

	if (size > 0)
	{
		title("Front :");
		std_ss << "front: " << std_vec.front();
		ft_ss << "front: " << ft_vec.front();
		check(&std_ss, &ft_ss, 0);

		title("Back :");
		std_ss << "back: " << std_vec.back();
		ft_ss << "back: " << ft_vec.back();
		check(&std_ss, &ft_ss, 0);
	}
}

void element_access_test_str(int size)
{
	std::string str = "str_global";
	title("Element Access (Str) Size", size);
	std::vector<std::string> std_vec;	
	ft::Vector<std::string> ft_vec;	

	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(str);
		ft_vec.push_back(str);
	}

	std::stringstream std_ss;
	std::stringstream ft_ss;
	for (int i = 0; i < size; i++)
	{
		std_ss << "[" << i << "]: " << std_vec.at(i) << " ";
		ft_ss << "[" << i << "]: " << ft_vec.at(i) << " ";
	}

	title("At :");
	check(&std_ss, &ft_ss, 0);

	for (int i = 0; i < size; i++)
	{
		std_ss << "[" << i << "]: " << std_vec[i] << " ";
		ft_ss << "[" << i << "]: " << ft_vec[i] << " ";
	}
	title("Operator [] :");
	check(&std_ss, &ft_ss, 0);

	if (size > 0)
	{
		title("Front :");
		std_ss << "front: " << std_vec.front();
		ft_ss << "front: " << ft_vec.front();
		check(&std_ss, &ft_ss, 0);

		title("Back :");
		std_ss << "back: " << std_vec.back();
		ft_ss << "back: " << ft_vec.back();
		check(&std_ss, &ft_ss, 0);
	}
}

void element_access_test_class(int size)
{
	Testclass c;
	title("Element Access (Class) Size", size);
	std::vector<Testclass> std_vec;	
	ft::Vector<Testclass> ft_vec;	

	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(c);
		ft_vec.push_back(c);
	}

	std::stringstream std_ss;
	std::stringstream ft_ss;
	for (int i = 0; i < size; i++)
	{
		std_ss << "[" << i << "]: " << std_vec.at(i) << " ";
		ft_ss << "[" << i << "]: " << ft_vec.at(i) << " ";
	}

	title("At :");
	check(&std_ss, &ft_ss, 0);

	for (int i = 0; i < size; i++)
	{
		std_ss << "[" << i << "]: " << std_vec[i] << " ";
		ft_ss << "[" << i << "]: " << ft_vec[i] << " ";
	}
	title("Operator [] :");
	check(&std_ss, &ft_ss, 0);

	if (size > 0)
	{
		title("Front :");
		std_ss << "front: " << std_vec.front();
		ft_ss << "front: " << ft_vec.front();
		check(&std_ss, &ft_ss, 0);

		title("Back :");
		std_ss << "back: " << std_vec.back();
		ft_ss << "back: " << ft_vec.back();
		check(&std_ss, &ft_ss, 0);
	}
}

void iterator_test(int size)
{
	title("Iterator Size", size);
	std::vector<int> std_vec;	
	ft::Vector<int> ft_vec;	

	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(i);
		ft_vec.push_back(i);
	}

	std::stringstream std_ss;
	std::stringstream ft_ss;
	
	title("Begin - End :");
	for (std::vector<int>::iterator itr = std_vec.begin(); itr != std_vec.end(); itr++)
		std_ss << *itr << " ";
	for (ft::Vector<int>::iterator itr = ft_vec.begin(); itr != ft_vec.end(); itr++)
		ft_ss << *itr << " ";
	check(&std_ss, &ft_ss, 0);
	
	title("Const Begin - Const End :");
	for (std::vector<int>::const_iterator itr = std_vec.begin(); itr != std_vec.end(); itr++)
		std_ss << *itr << " ";
	for (ft::Vector<int>::const_iterator itr = ft_vec.begin(); itr != ft_vec.end(); itr++)
		ft_ss << *itr << " ";
	check(&std_ss, &ft_ss, 0);
	
	title("Reverse Begin - Reverse End :");
	for (std::vector<int>::reverse_iterator itr = std_vec.rbegin(); itr != std_vec.rend(); itr++)
		std_ss << *itr << " ";
	for (ft::Vector<int>::reverse_iterator itr = ft_vec.rbegin(); itr != ft_vec.rend(); itr++)
		ft_ss << *itr << " ";
	check(&std_ss, &ft_ss, 0);
	
	title("Const Reverse Begin - Const Reverse End :");
	for (std::vector<int>::const_reverse_iterator itr = std_vec.rbegin(); itr != std_vec.rend(); itr++)
		std_ss << *itr << " ";
	for (ft::Vector<int>::const_reverse_iterator itr = ft_vec.rbegin(); itr != ft_vec.rend(); itr++)
		ft_ss << *itr << " ";
	check(&std_ss, &ft_ss, 0);

	std::vector<int>::iterator itr_std = std_vec.begin();
	ft::Vector<int>::iterator itr_ft = ft_vec.begin();
	if (size > 2)
	{
		title("Iterator operator+ :");
		std_ss << *(itr_std + 1);
		ft_ss << *(itr_ft + 1);
		check(&std_ss, &ft_ss, 0);
		
		title("Iterator operator+= :");
		itr_std += 1;
		itr_ft += 1;
		std_ss << *itr_std;
		ft_ss << *itr_ft;
		check(&std_ss, &ft_ss, 0);
		
		title("Iterator operator- :");
		std_ss << *(itr_std - 1);
		ft_ss << *(itr_ft - 1);
		check(&std_ss, &ft_ss, 0);
		
		title("Iterator operator-= :");
		itr_std -= 1;
		itr_ft -= 1;
		std_ss << *itr_std;
		ft_ss << *itr_ft;
		check(&std_ss, &ft_ss, 0);
	}

	title("Iterator operator< :");
	std_ss << (std_vec.begin() < std_vec.end());
	ft_ss << (ft_vec.begin() < ft_vec.end());
	check(&std_ss, &ft_ss, 0);

	title("Iterator operator<= :");
	std_ss << (std_vec.begin() <= std_vec.end());
	ft_ss << (ft_vec.begin() <= ft_vec.end());
	check(&std_ss, &ft_ss, 0);

	title("Iterator operator> :");
	std_ss << (std_vec.begin() > std_vec.end());
	ft_ss << (ft_vec.begin() > ft_vec.end());
	check(&std_ss, &ft_ss, 0);

	title("Iterator operator>= :");
	std_ss << (std_vec.begin() >= std_vec.end());
	ft_ss << (ft_vec.begin() >= ft_vec.end());
	check(&std_ss, &ft_ss, 0);
}

void iterator_test_str(int size)
{
	std::string str = "str_global";
	title("Iterator (Str) Size", size);
	std::vector<std::string> std_vec;	
	ft::Vector<std::string> ft_vec;	

	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(str);
		ft_vec.push_back(str);
	}

	std::stringstream std_ss;
	std::stringstream ft_ss;
	
	title("Begin - End :");
	for (std::vector<std::string>::iterator itr = std_vec.begin(); itr != std_vec.end(); itr++)
		std_ss << *itr << " ";
	for (ft::Vector<std::string>::iterator itr = ft_vec.begin(); itr != ft_vec.end(); itr++)
		ft_ss << *itr << " ";
	check(&std_ss, &ft_ss, 0);
	
	title("Const Begin - Const End :");
	for (std::vector<std::string>::const_iterator itr = std_vec.begin(); itr != std_vec.end(); itr++)
		std_ss << *itr << " ";
	for (ft::Vector<std::string>::const_iterator itr = ft_vec.begin(); itr != ft_vec.end(); itr++)
		ft_ss << *itr << " ";
	check(&std_ss, &ft_ss, 0);
	
	title("Reverse Begin - Reverse End :");
	for (std::vector<std::string>::reverse_iterator itr = std_vec.rbegin(); itr != std_vec.rend(); itr++)
		std_ss << *itr << " ";
	for (ft::Vector<std::string>::reverse_iterator itr = ft_vec.rbegin(); itr != ft_vec.rend(); itr++)
		ft_ss << *itr << " ";
	check(&std_ss, &ft_ss, 0);
	
	title("Const Reverse Begin - Const Reverse End :");
	for (std::vector<std::string>::const_reverse_iterator itr = std_vec.rbegin(); itr != std_vec.rend(); itr++)
		std_ss << *itr << " ";
	for (ft::Vector<std::string>::const_reverse_iterator itr = ft_vec.rbegin(); itr != ft_vec.rend(); itr++)
		ft_ss << *itr << " ";
	check(&std_ss, &ft_ss, 0);

	std::vector<std::string>::iterator itr_std = std_vec.begin();
	ft::Vector<std::string>::iterator itr_ft = ft_vec.begin();
	if (size > 2)
	{
		title("Iterator operator+ :");
		std_ss << *(itr_std + 1);
		ft_ss << *(itr_ft + 1);
		check(&std_ss, &ft_ss, 0);
		
		title("Iterator operator+= :");
		itr_std += 1;
		itr_ft += 1;
		std_ss << *itr_std;
		ft_ss << *itr_ft;
		check(&std_ss, &ft_ss, 0);
		
		title("Iterator operator- :");
		std_ss << *(itr_std - 1);
		ft_ss << *(itr_ft - 1);
		check(&std_ss, &ft_ss, 0);
		
		title("Iterator operator-= :");
		itr_std -= 1;
		itr_ft -= 1;
		std_ss << *itr_std;
		ft_ss << *itr_ft;
		check(&std_ss, &ft_ss, 0);
	}

	title("Iterator operator< :");
	std_ss << (std_vec.begin() < std_vec.end());
	ft_ss << (ft_vec.begin() < ft_vec.end());
	check(&std_ss, &ft_ss, 0);

	title("Iterator operator<= :");
	std_ss << (std_vec.begin() <= std_vec.end());
	ft_ss << (ft_vec.begin() <= ft_vec.end());
	check(&std_ss, &ft_ss, 0);

	title("Iterator operator> :");
	std_ss << (std_vec.begin() > std_vec.end());
	ft_ss << (ft_vec.begin() > ft_vec.end());
	check(&std_ss, &ft_ss, 0);

	title("Iterator operator>= :");
	std_ss << (std_vec.begin() >= std_vec.end());
	ft_ss << (ft_vec.begin() >= ft_vec.end());
	check(&std_ss, &ft_ss, 0);
}

void iterator_test_class(int size)
{
	Testclass c;
	title("Iterator (Class) Size", size);
	std::vector<Testclass> std_vec;	
	ft::Vector<Testclass> ft_vec;	

	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(c);
		ft_vec.push_back(c);
	}

	std::stringstream std_ss;
	std::stringstream ft_ss;
	
	title("Begin - End :");
	for (std::vector<Testclass>::iterator itr = std_vec.begin(); itr != std_vec.end(); itr++)
		std_ss << *itr << " ";
	for (ft::Vector<Testclass>::iterator itr = ft_vec.begin(); itr != ft_vec.end(); itr++)
		ft_ss << *itr << " ";
	check(&std_ss, &ft_ss, 0);
	
	title("Const Begin - Const End :");
	for (std::vector<Testclass>::const_iterator itr = std_vec.begin(); itr != std_vec.end(); itr++)
		std_ss << *itr << " ";
	for (ft::Vector<Testclass>::const_iterator itr = ft_vec.begin(); itr != ft_vec.end(); itr++)
		ft_ss << *itr << " ";
	check(&std_ss, &ft_ss, 0);
	
	title("Reverse Begin - Reverse End :");
	for (std::vector<Testclass>::reverse_iterator itr = std_vec.rbegin(); itr != std_vec.rend(); itr++)
		std_ss << *itr << " ";
	for (ft::Vector<Testclass>::reverse_iterator itr = ft_vec.rbegin(); itr != ft_vec.rend(); itr++)
		ft_ss << *itr << " ";
	check(&std_ss, &ft_ss, 0);
	
	title("Const Reverse Begin - Const Reverse End :");
	for (std::vector<Testclass>::const_reverse_iterator itr = std_vec.rbegin(); itr != std_vec.rend(); itr++)
		std_ss << *itr << " ";
	for (ft::Vector<Testclass>::const_reverse_iterator itr = ft_vec.rbegin(); itr != ft_vec.rend(); itr++)
		ft_ss << *itr << " ";
	check(&std_ss, &ft_ss, 0);

	std::vector<Testclass>::iterator itr_std = std_vec.begin();
	ft::Vector<Testclass>::iterator itr_ft = ft_vec.begin();
	if (size > 2)
	{
		title("Iterator operator+ :");
		std_ss << *(itr_std + 1);
		ft_ss << *(itr_ft + 1);
		check(&std_ss, &ft_ss, 0);
		
		title("Iterator operator+= :");
		itr_std += 1;
		itr_ft += 1;
		std_ss << *itr_std;
		ft_ss << *itr_ft;
		check(&std_ss, &ft_ss, 0);
		
		title("Iterator operator- :");
		std_ss << *(itr_std - 1);
		ft_ss << *(itr_ft - 1);
		check(&std_ss, &ft_ss, 0);
		
		title("Iterator operator-= :");
		itr_std -= 1;
		itr_ft -= 1;
		std_ss << *itr_std;
		ft_ss << *itr_ft;
		check(&std_ss, &ft_ss, 0);
	}

	title("Iterator operator< :");
	std_ss << (std_vec.begin() < std_vec.end());
	ft_ss << (ft_vec.begin() < ft_vec.end());
	check(&std_ss, &ft_ss, 0);

	title("Iterator operator<= :");
	std_ss << (std_vec.begin() <= std_vec.end());
	ft_ss << (ft_vec.begin() <= ft_vec.end());
	check(&std_ss, &ft_ss, 0);

	title("Iterator operator> :");
	std_ss << (std_vec.begin() > std_vec.end());
	ft_ss << (ft_vec.begin() > ft_vec.end());
	check(&std_ss, &ft_ss, 0);

	title("Iterator operator>= :");
	std_ss << (std_vec.begin() >= std_vec.end());
	ft_ss << (ft_vec.begin() >= ft_vec.end());
	check(&std_ss, &ft_ss, 0);
}

void capacity_test(int size)
{
	title("Capacity Size", size);
	std::vector<int> std_vec;
	ft::Vector<int> ft_vec;

	std::stringstream std_ss;
	std::stringstream ft_ss;

	title("Empty :");
	std_ss << "empty : " << std_vec.empty() << " fill : "; 
	ft_ss << "empty : " << ft_vec.empty() << " fill : "; 

	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(i);
		ft_vec.push_back(i);
	}

	std_ss << std_vec.empty(); 
	ft_ss << ft_vec.empty(); 
	check(&std_ss, &ft_ss, 0);

	title("Size :");
	std_ss << "size : " << std_vec.size(); 
	ft_ss << "size : " << ft_vec.size(); 
	check(&std_ss, &ft_ss, 0);

	title("Max Size :");
	std_ss << "max_size : " << std_vec.max_size(); 
	ft_ss << "max_size : " << ft_vec.max_size(); 
	check(&std_ss, &ft_ss, 0);

	title("Capacity :");
	std_ss << "capacity : " << std_vec.capacity(); 
	ft_ss << "capacity : " << ft_vec.capacity(); 
	check(&std_ss, &ft_ss, 0);

	title("Reserve + Capacity :");
	std_vec.reserve(2 * size);
	ft_vec.reserve(2 * size);
	std_ss << "capacity : " << std_vec.capacity(); 
	ft_ss << "capacity : " << ft_vec.capacity(); 
	check(&std_ss, &ft_ss, 0);
}

void capacity_test_str(int size)
{
	std::string str = "str_global";
	title("Capacity (Str) Size", size);
	std::vector<std::string> std_vec;
	ft::Vector<std::string> ft_vec;

	std::stringstream std_ss;
	std::stringstream ft_ss;

	title("Empty :");
	std_ss << "empty : " << std_vec.empty() << " fill : "; 
	ft_ss << "empty : " << ft_vec.empty() << " fill : "; 

	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(str);
		ft_vec.push_back(str);
	}

	std_ss << std_vec.empty(); 
	ft_ss << ft_vec.empty(); 
	check(&std_ss, &ft_ss, 0);

	title("Size :");
	std_ss << "size : " << std_vec.size(); 
	ft_ss << "size : " << ft_vec.size(); 
	check(&std_ss, &ft_ss, 0);

	title("Max Size :");
	std_ss << "max_size : " << std_vec.max_size(); 
	ft_ss << "max_size : " << ft_vec.max_size(); 
	check(&std_ss, &ft_ss, 0);

	title("Capacity :");
	std_ss << "capacity : " << std_vec.capacity(); 
	ft_ss << "capacity : " << ft_vec.capacity(); 
	check(&std_ss, &ft_ss, 0);

	title("Reserve + Capacity :");
	std_vec.reserve(2 * size);
	ft_vec.reserve(2 * size);
	std_ss << "capacity : " << std_vec.capacity(); 
	ft_ss << "capacity : " << ft_vec.capacity(); 
	check(&std_ss, &ft_ss, 0);
}

void capacity_test_class(int size)
{
	Testclass c;
	title("Capacity (Class) Size", size);
	std::vector<Testclass> std_vec;
	ft::Vector<Testclass> ft_vec;

	std::stringstream std_ss;
	std::stringstream ft_ss;

	title("Empty :");
	std_ss << "empty : " << std_vec.empty() << " fill : "; 
	ft_ss << "empty : " << ft_vec.empty() << " fill : "; 

	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(c);
		ft_vec.push_back(c);
	}

	std_ss << std_vec.empty(); 
	ft_ss << ft_vec.empty(); 
	check(&std_ss, &ft_ss, 0);

	title("Size :");
	std_ss << "size : " << std_vec.size(); 
	ft_ss << "size : " << ft_vec.size(); 
	check(&std_ss, &ft_ss, 0);

	title("Max Size :");
	std_ss << "max_size : " << std_vec.max_size(); 
	ft_ss << "max_size : " << ft_vec.max_size(); 
	check(&std_ss, &ft_ss, 0);

	title("Capacity :");
	std_ss << "capacity : " << std_vec.capacity(); 
	ft_ss << "capacity : " << ft_vec.capacity(); 
	check(&std_ss, &ft_ss, 0);

	title("Reserve + Capacity :");
	std_vec.reserve(2 * size);
	ft_vec.reserve(2 * size);
	std_ss << "capacity : " << std_vec.capacity(); 
	ft_ss << "capacity : " << ft_vec.capacity(); 
	check(&std_ss, &ft_ss, 0);
}

void modifiers_test(int size) 
{
	title("Modifiers Size", size);
	std::vector<int> std_vec;
	ft::Vector<int> ft_vec;
	std::vector<int> std_vec_bis;
	ft::Vector<int> ft_vec_bis;

	std::stringstream std_ss;
	std::stringstream ft_ss;

	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(i);
		ft_vec.push_back(i);
		std_vec_bis.push_back(i);
		ft_vec_bis.push_back(i);
	}

	title("Clear :");
	std_ss << "empty = (" << std_vec.empty() << ") -> clear -> empty = (";
	ft_ss << "empty = (" << ft_vec.empty() << ") -> clear -> empty = (";
	std_vec.clear();
	ft_vec.clear();
	std_ss << std_vec.empty() << ")";
	ft_ss << ft_vec.empty() << ")";
	check(&std_ss, &ft_ss, 0);

	title("Initial :");
	describe_vector(std_vec, ft_vec);
	describe_vector(std_vec_bis, ft_vec_bis);

	title("Insert (begin(), value) :");
	std_vec.insert(std_vec.begin(), size);
	ft_vec.insert(ft_vec.begin(), size);
	describe_vector(std_vec, ft_vec);

	title("Insert (end(), value) :");
	std_vec.insert(std_vec.end(), size + 1);
	ft_vec.insert(ft_vec.end(), size + 1);
	describe_vector(std_vec, ft_vec);

	title("Insert (begin(), count, value) :");
	std_vec.insert(std_vec.begin(), size, size + 2);
	ft_vec.insert(ft_vec.begin(), size, size + 2);
	describe_vector(std_vec, ft_vec);

	title("Insert (end(), count, value) :");
	std_vec.insert(std_vec.end(), size, size + 3);
	ft_vec.insert(ft_vec.end(), size, size + 3);
	describe_vector(std_vec, ft_vec);

	title("Insert (begin(), first, last) :");
	std_vec.insert(std_vec.begin(), size, size + 2);
	ft_vec.insert(ft_vec.begin(), size, size + 2);
	describe_vector(std_vec, ft_vec);

	title("Insert (end(), first, last) :");
	std_vec.insert(std_vec.end(), std_vec_bis.begin(), std_vec_bis.end());
	ft_vec.insert(ft_vec.end(), ft_vec_bis.begin(), ft_vec_bis.end());
	describe_vector(std_vec, ft_vec);

	title("Erase (begin()) :");
	std_vec.erase(std_vec.begin());
	ft_vec.erase(ft_vec.begin());
	describe_vector(std_vec, ft_vec);

	title("Erase (--end()) :");
	std_vec.erase(--std_vec.end());
	ft_vec.erase(--ft_vec.end());
	describe_vector(std_vec, ft_vec);

	title("Erase (begin(), end()) :");
	std_vec.erase(std_vec.begin(), std_vec.end());
	ft_vec.erase(ft_vec.begin(), ft_vec.end());
	describe_vector(std_vec, ft_vec);

	title("Push_back :");
	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(i);
		ft_vec.push_back(i);
	}
	describe_vector(std_vec, ft_vec);
	
	if (size >= 2)
	{
		title("Pop_back x 2 :");
		std_vec.pop_back();
		ft_vec.pop_back();
		std_vec.pop_back();
		ft_vec.pop_back();
		describe_vector(std_vec, ft_vec);
	}

	title("Resize (Up sized) :");
	std_vec.resize(size, size * 2);
	ft_vec.resize(size, size * 2);
	describe_vector(std_vec, ft_vec);

	title("Resize (Down sized) :");
	std_vec.resize(size / 2, size * 3);
	ft_vec.resize(size / 2, size * 3);
	describe_vector(std_vec, ft_vec);

	title("Swap (before):");
	describe_vector(std_vec, ft_vec);
	describe_vector(std_vec_bis, ft_vec_bis);

	std_vec.swap(std_vec_bis);
	ft_vec.swap(ft_vec_bis);

	title("Swap (after):");
	describe_vector(std_vec, ft_vec);
	describe_vector(std_vec_bis, ft_vec_bis);
}

void modifiers_test_str(int size) 
{
	std::string str = "str_global";
	title("Modifiers (Str) Size", size);
	std::vector<std::string> std_vec;
	ft::Vector<std::string> ft_vec;
	std::vector<std::string> std_vec_bis;
	ft::Vector<std::string> ft_vec_bis;

	std::stringstream std_ss;
	std::stringstream ft_ss;

	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(str);
		ft_vec.push_back(str);
		std_vec_bis.push_back(str);
		ft_vec_bis.push_back(str);
	}

	title("Clear :");
	std_ss << "empty = (" << std_vec.empty() << ") -> clear -> empty = (";
	ft_ss << "empty = (" << ft_vec.empty() << ") -> clear -> empty = (";
	std_vec.clear();
	ft_vec.clear();
	std_ss << std_vec.empty() << ")";
	ft_ss << ft_vec.empty() << ")";
	check(&std_ss, &ft_ss, 0);

	title("Initial :");
	describe_vector(std_vec, ft_vec);
	describe_vector(std_vec_bis, ft_vec_bis);

	title("Insert (begin(), value) :");
	std_vec.insert(std_vec.begin(), str);
	ft_vec.insert(ft_vec.begin(), str);
	describe_vector(std_vec, ft_vec);

	title("Insert (end(), value) :");
	std_vec.insert(std_vec.end(), str);
	ft_vec.insert(ft_vec.end(), str);
	describe_vector(std_vec, ft_vec);

	title("Insert (begin(), count, value) :");
	std_vec.insert(std_vec.begin(), size, str);
	ft_vec.insert(ft_vec.begin(), size, str);
	describe_vector(std_vec, ft_vec);

	title("Insert (end(), count, value) :");
	std_vec.insert(std_vec.end(), size, str);
	ft_vec.insert(ft_vec.end(), size, str);
	describe_vector(std_vec, ft_vec);

	title("Insert (begin(), first, last) :");
	std_vec.insert(std_vec.begin(), size, str);
	ft_vec.insert(ft_vec.begin(), size, str);
	describe_vector(std_vec, ft_vec);

	title("Insert (end(), first, last) :");
	std_vec.insert(std_vec.end(), std_vec_bis.begin(), std_vec_bis.end());
	ft_vec.insert(ft_vec.end(), ft_vec_bis.begin(), ft_vec_bis.end());
	describe_vector(std_vec, ft_vec);

	title("Erase (begin()) :");
	std_vec.erase(std_vec.begin());
	ft_vec.erase(ft_vec.begin());
	describe_vector(std_vec, ft_vec);

	title("Erase (--end()) :");
	std_vec.erase(--std_vec.end());
	ft_vec.erase(--ft_vec.end());
	describe_vector(std_vec, ft_vec);

	title("Erase (begin(), end()) :");
	std_vec.erase(std_vec.begin(), std_vec.end());
	ft_vec.erase(ft_vec.begin(), ft_vec.end());
	describe_vector(std_vec, ft_vec);

	title("Push_back :");
	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(str);
		ft_vec.push_back(str);
	}
	describe_vector(std_vec, ft_vec);
	
	if (size >= 2)
	{
		title("Pop_back x 2 :");
		std_vec.pop_back();
		ft_vec.pop_back();
		std_vec.pop_back();
		ft_vec.pop_back();
		describe_vector(std_vec, ft_vec);
	}

	title("Resize (Up sized) :");
	std_vec.resize(size, str);
	ft_vec.resize(size, str);
	describe_vector(std_vec, ft_vec);

	title("Resize (Down sized) :");
	std_vec.resize(size / 2, str);
	ft_vec.resize(size / 2, str);
	describe_vector(std_vec, ft_vec);

	title("Swap (before):");
	describe_vector(std_vec, ft_vec);
	describe_vector(std_vec_bis, ft_vec_bis);

	std_vec.swap(std_vec_bis);
	ft_vec.swap(ft_vec_bis);

	title("Swap (after):");
	describe_vector(std_vec, ft_vec);
	describe_vector(std_vec_bis, ft_vec_bis);
}

void modifiers_test_class(int size) 
{
	Testclass c;
	title("Modifiers (Class) Size", size);
	std::vector<Testclass> std_vec;
	ft::Vector<Testclass> ft_vec;
	std::vector<Testclass> std_vec_bis;
	ft::Vector<Testclass> ft_vec_bis;

	std::stringstream std_ss;
	std::stringstream ft_ss;

	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(c);
		ft_vec.push_back(c);
		std_vec_bis.push_back(c);
		ft_vec_bis.push_back(c);
	}

	title("Clear :");
	std_ss << "empty = (" << std_vec.empty() << ") -> clear -> empty = (";
	ft_ss << "empty = (" << ft_vec.empty() << ") -> clear -> empty = (";
	std_vec.clear();
	ft_vec.clear();
	std_ss << std_vec.empty() << ")";
	ft_ss << ft_vec.empty() << ")";
	check(&std_ss, &ft_ss, 0);

	title("Initial :");
	describe_vector(std_vec, ft_vec);
	describe_vector(std_vec_bis, ft_vec_bis);

	title("Insert (begin(), value) :");
	std_vec.insert(std_vec.begin(), c);
	ft_vec.insert(ft_vec.begin(), c);
	describe_vector(std_vec, ft_vec);

	title("Insert (end(), value) :");
	std_vec.insert(std_vec.end(), c);
	ft_vec.insert(ft_vec.end(), c);
	describe_vector(std_vec, ft_vec);

	title("Insert (begin(), count, value) :");
	std_vec.insert(std_vec.begin(), size, c);
	ft_vec.insert(ft_vec.begin(), size, c);
	describe_vector(std_vec, ft_vec);

	title("Insert (end(), count, value) :");
	std_vec.insert(std_vec.end(), size, c);
	ft_vec.insert(ft_vec.end(), size, c);
	describe_vector(std_vec, ft_vec);

	title("Insert (begin(), first, last) :");
	std_vec.insert(std_vec.begin(), size, c);
	ft_vec.insert(ft_vec.begin(), size, c);
	describe_vector(std_vec, ft_vec);

	title("Insert (end(), first, last) :");
	std_vec.insert(std_vec.end(), std_vec_bis.begin(), std_vec_bis.end());
	ft_vec.insert(ft_vec.end(), ft_vec_bis.begin(), ft_vec_bis.end());
	describe_vector(std_vec, ft_vec);

	title("Erase (begin()) :");
	std_vec.erase(std_vec.begin());
	ft_vec.erase(ft_vec.begin());
	describe_vector(std_vec, ft_vec);

	title("Erase (--end()) :");
	std_vec.erase(--std_vec.end());
	ft_vec.erase(--ft_vec.end());
	describe_vector(std_vec, ft_vec);

	title("Erase (begin(), end()) :");
	std_vec.erase(std_vec.begin(), std_vec.end());
	ft_vec.erase(ft_vec.begin(), ft_vec.end());
	describe_vector(std_vec, ft_vec);

	title("Push_back :");
	for (int i = 0; i < size; i++)
	{
		std_vec.push_back(c);
		ft_vec.push_back(c);
	}
	describe_vector(std_vec, ft_vec);
	
	if (size >= 2)
	{
		title("Pop_back x 2 :");
		std_vec.pop_back();
		ft_vec.pop_back();
		std_vec.pop_back();
		ft_vec.pop_back();
		describe_vector(std_vec, ft_vec);
	}

	title("Resize (Up sized) :");
	std_vec.resize(size, c);
	ft_vec.resize(size, c);
	describe_vector(std_vec, ft_vec);

	title("Resize (Down sized) :");
	std_vec.resize(size / 2, c);
	ft_vec.resize(size / 2, c);
	describe_vector(std_vec, ft_vec);

	title("Swap (before):");
	describe_vector(std_vec, ft_vec);
	describe_vector(std_vec_bis, ft_vec_bis);

	std_vec.swap(std_vec_bis);
	ft_vec.swap(ft_vec_bis);

	title("Swap (after):");
	describe_vector(std_vec, ft_vec);
	describe_vector(std_vec_bis, ft_vec_bis);
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

void operator_test_str(int size)
{
	std::string str = "str_global";
	title("Operator (Str) Size", size);

	std::vector<std::string> std_vector;
	std::vector<std::string> std_vector_bis;
	ft::Vector<std::string> ft_vector;
	ft::Vector<std::string> ft_vector_bis;

	for (int i = 0; i < size; i++)
	{
		std_vector.push_back(str);
		std_vector_bis.push_back(str);
		ft_vector.push_back(str);
		ft_vector_bis.push_back(str);
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

void operator_test_class(int size)
{
	Testclass c;
	title("Operator (Class) Size", size);

	std::vector<Testclass> std_vector;
	std::vector<Testclass> std_vector_bis;
	ft::Vector<Testclass> ft_vector;
	ft::Vector<Testclass> ft_vector_bis;

	for (int i = 0; i < size; i++)
	{
		std_vector.push_back(c);
		std_vector_bis.push_back(c);
		ft_vector.push_back(c);
		ft_vector_bis.push_back(c);
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
# ifndef SIZE
    constructor_test(1000); // OK Sur linux (juste chiant a afficher)
	constructor_test(10);
	constructor_test(5);
	constructor_test(2);
	constructor_test(1);
	constructor_test(0);

    constructor_test_str(1000); // OK Sur linux (juste chiant a afficher)
	constructor_test_str(10);
	constructor_test_str(5);
	constructor_test_str(2);
	constructor_test_str(1);
	constructor_test_str(0);

    constructor_test_class(1000); // OK Sur linux (juste chiant a afficher)
	constructor_test_class(10);
	constructor_test_class(5);
	constructor_test_class(2);
	constructor_test_class(1);
	constructor_test_class(0);
# else
	constructor_test(SIZE);
# endif
#endif

#if TEST_VECTOR == 0 || TEST_VECTOR == 2
# ifndef SIZE
    element_access_test(1000); // OK Sur linux (juste chiant a afficher)
	element_access_test(10);
	element_access_test(5);
	element_access_test(2);
	element_access_test(1);
	element_access_test(0);

    element_access_test_str(1000); // OK Sur linux (juste chiant a afficher)
	element_access_test_str(10);
	element_access_test_str(5);
	element_access_test_str(2);
	element_access_test_str(1);
	element_access_test_str(0);

    element_access_test_class(1000); // OK Sur linux (juste chiant a afficher)
	element_access_test_class(10);
	element_access_test_class(5);
	element_access_test_class(2);
	element_access_test_class(1);
	element_access_test_class(0);
# else
	element_access_test(SIZE);
# endif
#endif

#if TEST_VECTOR == 0 || TEST_VECTOR == 3
# ifndef SIZE
    iterator_test(1000); // OK Sur linux (juste chiant a afficher)
	iterator_test(10);
	iterator_test(5);
	iterator_test(2);
	iterator_test(1);
	iterator_test(0);

    iterator_test_str(1000); // OK Sur linux (juste chiant a afficher)
	iterator_test_str(10);
	iterator_test_str(5);
	iterator_test_str(2);
	iterator_test_str(1);
	iterator_test_str(0);

    iterator_test_class(1000); // OK Sur linux (juste chiant a afficher)
	iterator_test_class(10);
	iterator_test_class(5);
	iterator_test_class(2);
	iterator_test_class(1);
	iterator_test_class(0);
# else
	iterator_test(SIZE);
# endif
#endif

#if TEST_VECTOR == 0 || TEST_VECTOR == 4
	// Autant de test pour demontrer que les tailles allouees sont les memes
# ifndef SIZE
    capacity_test(1000); // OK Sur linux (juste chiant a afficher)
	capacity_test(257);
	capacity_test(255);
	capacity_test(64);
	capacity_test(16);
	capacity_test(10);
	capacity_test(5);
	capacity_test(2);
	capacity_test(1);
	capacity_test(0);

    capacity_test_str(1000); // OK Sur linux (juste chiant a afficher)
	capacity_test_str(257);
	capacity_test_str(255);
	capacity_test_str(64);
	capacity_test_str(16);
	capacity_test_str(10);
	capacity_test_str(5);
	capacity_test_str(2);
	capacity_test_str(1);
	capacity_test_str(0);
	
    capacity_test_class(1000); // OK Sur linux (juste chiant a afficher)
	capacity_test_class(257);
	capacity_test_class(255);
	capacity_test_class(64);
	capacity_test_class(16);
	capacity_test_class(10);
	capacity_test_class(5);
	capacity_test_class(2);
	capacity_test_class(1);
	capacity_test_class(0);
# else
	capacity_test(SIZE);
# endif
#endif

#if TEST_VECTOR == 0 || TEST_VECTOR == 5
# ifndef SIZE
    modifiers_test(1000); // OK Sur linux (juste chiant a afficher)
	modifiers_test(10);
	modifiers_test(5);
	modifiers_test(2);
	modifiers_test(1);
	modifiers_test(0);

    modifiers_test_str(1000); // OK Sur linux (juste chiant a afficher)
	modifiers_test_str(10);
	modifiers_test_str(5);
	modifiers_test_str(2);
	modifiers_test_str(1);
	modifiers_test_str(0);

    modifiers_test_class(1000); // OK Sur linux (juste chiant a afficher)
	modifiers_test_class(10);
	modifiers_test_class(5);
	modifiers_test_class(2);
	modifiers_test_class(1);
	modifiers_test_class(0);
# else
	modifiers_test(SIZE);
# endif
#endif

#if TEST_VECTOR == 0 || TEST_VECTOR == 6
# ifndef SIZE
    operator_test(1000); // OK Sur linux (juste chiant a afficher)
	operator_test(10);
	operator_test(5);
	operator_test(2);
	operator_test(1);
	operator_test(0);

    operator_test_str(1000); // OK Sur linux (juste chiant a afficher)
	operator_test_str(10);
	operator_test_str(5);
	operator_test_str(2);
	operator_test_str(1);
	operator_test_str(0);

    operator_test_class(1000); // OK Sur linux (juste chiant a afficher)
	operator_test_class(10);
	operator_test_class(5);
	operator_test_class(2);
	operator_test_class(1);
	operator_test_class(0);
# else
	operator_test(SIZE);
# endif
#endif

    end_test();
}