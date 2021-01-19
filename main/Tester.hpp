#ifndef TESTER_HPP
#define TESTER_HPP

#include "List.hpp"
#include <list>

#include <sstream>

void title(std::string title);
void title(std::string title, int size);
void check(std::stringstream *ss_std, std::stringstream *ss_ft);

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
	check(&ss_std, &ss_ft);
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
	check(&ss_std, &ss_ft);
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
	check(&ss_std, &ss_ft);
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
	check(&ss_std, &ss_ft);
}

#endif