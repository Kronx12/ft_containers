#ifndef TESTER_HPP
# define TESTER_HPP

# include "List.hpp"
# include <list>
# include "Stack.hpp"
# include <stack>
# include "Queue.hpp"
# include <queue>
# include "Map.hpp"
# include <map>
# include "Vector.hpp"
# include <vector>

# include <sstream>
static int g_test = 0;
static int g_valid = 0;

class Testclass
{
	public:
		std::string str;
		Testclass()
		{
			str = "string_ICI";
		};
		Testclass(std::string strcp)
		{
			str = strcp;
		};
		~Testclass(){};
};

inline std::ostream &operator<<(std::ostream &o, Testclass const &rhs)
{
	o << rhs.str;
	return o;
};

inline bool operator< (const Testclass& lhs, const Testclass& rhs){ return (lhs.str < rhs.str); };
inline bool operator> (const Testclass& lhs, const Testclass& rhs){ return (lhs.str > rhs.str); };
inline bool operator==(const Testclass& lhs, const Testclass& rhs){ return (lhs.str == rhs.str); };
inline bool operator!=(const Testclass& lhs, const Testclass& rhs){ return (lhs.str != rhs.str); };
inline bool operator<= (const Testclass& lhs, const Testclass& rhs){ return (lhs.str <= rhs.str); };
inline bool operator>= (const Testclass& lhs, const Testclass& rhs){ return (lhs.str >= rhs.str); };

void title(std::string title);
void title(std::string title, int size);
void check(std::stringstream *ss_std, std::stringstream *ss_ft, int flag);
void end_test();

template < class T >
void describe_vector(std::vector<T> std_vector, ft::Vector<T> ft_vector)
{
	std::stringstream ss_std;
	std::stringstream ss_ft;

	ss_std << "- ";
	ss_ft << "- ";

	int i = 0;
	if (std_vector.empty())
		ss_std << "(empty)";
	else
		for (std::vector<int>::iterator itr = std_vector.begin(); itr != std_vector.end(); itr++)
		{
			ss_std << i << ":[" << *itr << "] ";
			i++;
		}
	i = 0;
	if (ft_vector.empty())
		ss_ft << "(empty)";
	else
		for (ft::Vector<int>::iterator itr = ft_vector.begin(); itr != ft_vector.end(); itr++)
		{
			ss_ft << i << ":[" << *itr << "] ";
			i++;
		}
	check(&ss_std, &ss_ft, 0);
}

template < class T >
void describe_vector(ft::Vector<T> std_vector, ft::Vector<T> ft_vector)
{
	std::stringstream ss_std;
	std::stringstream ss_ft;

	ss_std << "- ";
	ss_ft << "- ";

	int i = 0;
	if (std_vector.empty())
		ss_std << "(empty)";
	else
		for (ft::Vector<int>::iterator itr = std_vector.begin(); itr != std_vector.end(); itr++)
		{
			ss_std << i << ":[" << *itr << "] ";
			i++;
		}
	i = 0;
	if (ft_vector.empty())
		ss_ft << "(empty)";
	else
		for (ft::Vector<int>::iterator itr = ft_vector.begin(); itr != ft_vector.end(); itr++)
		{
			ss_ft << i << ":[" << *itr << "] ";
			i++;
		}
	check(&ss_std, &ss_ft, 1);
}

template < class T >
void describe_stack(std::stack<T> std_stack, ft::Stack<T> ft_stack)
{
	std::stringstream ss_std;
	std::stringstream ss_ft;

	ss_std << "- ";
	ss_ft << "- ";

	int i = 0;
	if (std_stack.empty())
		ss_std << "(empty)";
	else
		while (!std_stack.empty())
		{
			ss_std << i << ":[" << std_stack.top() << "] ";
			std_stack.pop();
			i++;
		}

	i = 0;
	if (ft_stack.empty())
		ss_ft << "(empty)";
	else
		while (!ft_stack.empty())
		{
			ss_ft << i << ":[" << ft_stack.top() << "] ";
			ft_stack.pop();
			i++;
		}
	check(&ss_std, &ss_ft, 0);
}

template < class T >
void describe_queue(std::queue<T> std_queue, ft::Queue<T> ft_queue)
{
	std::stringstream ss_std;
	std::stringstream ss_ft;

	ss_std << "- ";
	ss_ft << "- ";

	int i = 0;
	if (std_queue.empty())
		ss_std << "(empty)";
	else
		while (!std_queue.empty())
		{
			ss_std << i << ":[" << std_queue.front() << "] ";
			std_queue.pop();
			i++;
		}

	i = 0;
	if (ft_queue.empty())
		ss_ft << "(empty)";
	else
		while (!ft_queue.empty())
		{
			ss_ft << i << ":[" << ft_queue.front() << "] ";
			ft_queue.pop();
			i++;
		}
	check(&ss_std, &ss_ft, 0);
}

template < class T >
void describe_list(std::list<T> std_lst, ft::List<T> ft_lst)
{
	std::stringstream ss_std;
	std::stringstream ss_ft;

	ss_std << "- ";
	ss_ft << "- ";

	int i = 0;
	if (std_lst.empty())
		ss_std << "(empty)";
	else
		for (typename std::list<T>::iterator itr = std_lst.begin(); itr != std_lst.end(); itr++)
		{
			ss_std << i << ":[" << *itr << "] ";
			i++;
		}
	i = 0;
	if (ft_lst.empty())
		ss_ft << "(empty)";
	else
		for (typename ft::List<T>::iterator itr = ft_lst.begin(); itr != ft_lst.end(); itr++)
		{
			ss_ft << i << ":[" << *itr << "] ";
			i++;
		}
	check(&ss_std, &ss_ft, 0);
}

template < class T >
void const_describe_list(const std::list<T> std_lst, const ft::List<T> ft_lst)
{
	std::stringstream ss_std;
	std::stringstream ss_ft;

	ss_std << "- ";
	ss_ft << "- ";

	int i = 0;
	if (std_lst.empty())
		ss_std << "(empty)";
	else
		for (typename std::list<T>::const_iterator itr = std_lst.begin(); itr != std_lst.end(); itr++)
		{
			ss_std << i << ":[" << *itr << "] ";
			i++;
		}

	i = 0;
	if (ft_lst.empty())
		ss_ft << "(empty)";
	else
		for (typename ft::List<T>::const_iterator itr = ft_lst.begin(); itr != ft_lst.end(); itr++)
		{
			ss_ft << i << ":[" << *itr << "] ";
			i++;
		}
	check(&ss_std, &ss_ft, 0);
}

template < class T >
void reverse_describe_list(std::list<T> std_lst, ft::List<T> ft_lst)
{
	std::stringstream ss_std;
	std::stringstream ss_ft;

	ss_std << "- ";
	ss_ft << "- ";

	int i = 0;
	if (std_lst.empty())
		ss_std << "(empty)";
	else
		for (typename std::list<T>::reverse_iterator itr = std_lst.rbegin(); itr != std_lst.rend(); itr++)
		{
			ss_std << i << ":[" << *itr << "] ";
			i++;
		}

	i = 0;
	if (ft_lst.empty())
		ss_ft << "(empty)";
	else
		for (typename ft::List<T>::reverse_iterator itr = ft_lst.rbegin(); itr != ft_lst.rend(); itr++)
		{
			ss_ft << i << ":[" << *itr << "] ";
			i++;
		}
	check(&ss_std, &ss_ft, 0);
}

template < class T >
void const_reverse_describe_list(const std::list<T> std_lst, const ft::List<T> ft_lst)
{
	std::stringstream ss_std;
	std::stringstream ss_ft;

	ss_std << "- ";
	ss_ft << "- ";

	int i = 0;
	if (std_lst.empty())
		ss_std << "(empty)";
	else
		for (typename std::list<T>::const_reverse_iterator itr = std_lst.rbegin(); itr != std_lst.rend(); itr++)
		{
			ss_std << i << ":[" << *itr << "] ";
			i++;
		}

	i = 0;
	if (ft_lst.empty())
		ss_ft << "(empty)";
	else {
		for (typename ft::List<T>::const_reverse_iterator itr = ft_lst.rbegin(); itr != ft_lst.rend(); itr++)
		{
			ss_ft << i << ":[" << *itr << "] ";
			i++;
		}
	}
	check(&ss_std, &ss_ft, 0);
}

#endif