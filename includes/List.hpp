#ifndef LIST_HPP
# define LIST_HPP

# include "Iterator.hpp"

namespace ft
{
	template < typename T >
	class Link
	{
		public :
			T		value;
			Link	*next;
			Link	*previous;
			Link(const T& val) : value(val), next(NULL), previous(NULL) {};
			Link(Link *pre, const T& val, Link *_next) : value(val), next(_next), previous(pre) {};
			Link() : value(T()), next(NULL), previous(NULL) {};
	};

	template < class T, class Alloc = std::allocator<T> >
	class List
	{
		public:
			typedef T value_type;
			typedef typename std::allocator<value_type> allocator_type;
			typedef typename allocator_type::template rebind< Link<T> >::other node_alloc;
			typedef size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			// # created for ListIterator #
		private:
			typedef Link<value_type> link_type;
			typedef link_type* link_pointer;
		public:
			typedef ListIterator<value_type, link_type> iterator;
			typedef ConstListIterator<value_type, link_type> const_iterator;
			typedef ReverseIterator<iterator> reverse_iterator;
			typedef ReverseIterator<const_iterator> const_reverse_iterator;

		private:
			Link<T> *_end;
			Link<T> *_begin;
			Link<T> *_rend;
			size_t _size;
			allocator_type _alloc;

			template <class InputIterator>
			void constructor_assign_helper(InputIterator & first, InputIterator & last, void *);
			template <class InputIterator>
			void constructor_assign_helper(InputIterator & first, InputIterator & last, int);
			template <class InputIterator>
			void insert_helper(ft::List<T, Alloc>::iterator pos, const InputIterator& first, const InputIterator& last, void *);
			template <class InputIterator>
			void insert_helper(ft::List<T, Alloc>::iterator pos, const InputIterator& first, const InputIterator& last, int);

		public:
//--
			explicit List (const allocator_type& alloc = allocator_type());
			explicit List (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			template < class InputIterator >
			List (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			List (const List& x);
			~List();
			List<T, Alloc> &operator=( List const & rhs );
//---
			//Iterators;
			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;

			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;
//---
			//Capacity
			bool empty() const;
			size_type size() const;
			size_type max_size() const;
//---
			//Element access
			reference front();
			const_reference front() const;
			reference back();
			const_reference back() const;
//---
			//Modifiers
			void assign(size_type n, const value_type& val);
			template < typename InputIterator >
			void assign(InputIterator first, InputIterator last);
			void push_front(const value_type& val);
			void pop_front();
			void push_back(const value_type& val);
			void pop_back();
//--
			//Modifiers
			template< class InputIterator >
			void insert(iterator pos, InputIterator first, InputIterator last);
			iterator insert(iterator pos, const T &value);
			void insert(iterator pos, size_type count, const T& value);
//--
			//Modifiers2
			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);
			void clear();
			void swap(List &lst);
			void resize(size_type count, T value = T());
//--
			//Operations
			void splice(const_iterator pos, List &other);
			void splice(const_iterator pos, List &other, const_iterator it);
			void splice(const_iterator pos, List &other, const_iterator first, const_iterator last);

//---
			//Operations2
			template< class UnaryPredictate >
			void remove_if(UnaryPredictate p);
			void remove(const T &value);

			template < class Compare >
			void sort(Compare comp);
			void sort();
			void reverse();	
//---
			//Operations3
			template < class Compare >
			void merge(List &other, Compare comp);
			void merge(List &other);

			template < class BinaryPredicate >			
			void unique(BinaryPredicate p);
			void unique();
//--		
		// Operators (en bas)
	};

	//-------------------------- CONSTRUCTOR --------------------------
	template < typename T, class Alloc >
	List<T, Alloc>::List(const List<T, Alloc>::allocator_type& alloc)
		: _size(0), _alloc(alloc)
	{
		_end = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(_end, Link<T>());

		_begin = _end;
		
		_rend = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(_rend, Link<T>(NULL, T(), _end));

		_end->previous = _rend;
	}

	template < typename T, class Alloc >
	List<T, Alloc>::List(size_type n, const value_type& val, const allocator_type& alloc)
		: _size(0), _alloc(alloc)
	{
		_end = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(_end, Link<T>());

		_begin = _end;
		
		_rend = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(_rend, Link<T>(NULL, T(), _end));

		for (size_type i = 0; i < n; i++)
			push_back(val);
	}

	template < typename T, class Alloc >
	template < class InputIterator >
	List<T, Alloc>::List(InputIterator first, InputIterator last, const allocator_type& alloc)
		: _size(0), _alloc(alloc)
	{
		_end = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(_end, Link<T>());

		_begin = _end;
		
		_rend = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(_rend, Link<T>(NULL, T(), _end));

		constructor_assign_helper(first, last, typename ft::is_integral<InputIterator>::type());
	}

	template < typename T, class Alloc >
	List<T, Alloc>::List(const List& x)
		: _size(0), _alloc(x._alloc)
	{
		_end = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(_end, Link<T>());

		_begin = _end;
		
		_rend = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(_rend, Link<T>(NULL, T(), _end));

		for (List<T, Alloc>::const_iterator itr = x.begin(); itr != x.end(); itr++)
			push_back(*itr);
	}

	template < typename T, class Alloc >
	List<T, Alloc> &List<T, Alloc>::operator=(List<T, Alloc> const & rhs) {
        if (this == &rhs) return(*this);
		this->~List();
        return *new(this) List(rhs);
	}

	template < typename T, class Alloc >
	List<T, Alloc>::~List()
	{
		clear();
		node_alloc(_alloc).destroy(_end);
		node_alloc(_alloc).deallocate(_end, 1);
		node_alloc(_alloc).destroy(_rend);
		node_alloc(_alloc).deallocate(_rend, 1);
	}

	//-------------------------- ITERATORS --------------------------
	template < typename T, class Alloc >
	typename List<T, Alloc>::iterator List<T, Alloc>::begin()
	{
		return(iterator(this->_begin));
	}

	template < typename T, class Alloc >
	typename List<T, Alloc>::const_iterator List<T, Alloc>::begin() const
	{
		return(const_iterator(this->_begin));
	}

	template < typename T, class Alloc >
	typename List<T, Alloc>::iterator List<T, Alloc>::end()
	{
		return(iterator(this->_end));
	}

	template < typename T, class Alloc >
	typename List<T, Alloc>::const_iterator List<T, Alloc>::end() const
	{
		return(const_iterator(this->_end));
	}

	//------------------- REVERSE ITERATORS ------------------------
	template < typename T, class Alloc >
	typename List<T, Alloc>::reverse_iterator List<T, Alloc>::rbegin()
	{
		return(reverse_iterator(this->_end->previous));
	}

	template < typename T, class Alloc >
	typename List<T, Alloc>::const_reverse_iterator List<T, Alloc>::rbegin() const
	{
		return(const_reverse_iterator(this->_end->previous));
	}

	template < typename T, class Alloc >
	typename List<T, Alloc>::reverse_iterator List<T, Alloc>::rend()
	{
		return(reverse_iterator(this->_rend));
	}

	template < typename T, class Alloc >
	typename List<T, Alloc>::const_reverse_iterator List<T, Alloc>::rend() const
	{
		return(const_reverse_iterator(this->_rend));
	}

	//-------------------------- CAPACITY --------------------------
	template < typename T, class Alloc >
	bool List<T, Alloc>::empty() const
	{
		return(begin() == end());
	}

	template < typename T, class Alloc >
	typename List<T, Alloc>::size_type List<T, Alloc>::size() const
	{
		return(_size);
	}

	template < typename T, class Alloc >
	typename List<T, Alloc>::size_type List<T, Alloc>::max_size() const
	{
		return (std::numeric_limits<size_type>::max() / sizeof(link_type));
	}

	//-------------------------- ELEMENT ACCESS --------------------------
	template < typename T, class Alloc >
	typename List<T, Alloc>::reference List<T, Alloc>::front()
	{
		return(_begin->value);
	}

	template < typename T, class Alloc >
	typename List<T, Alloc>::const_reference List<T, Alloc>::front() const
	{
		return(_begin->value);
	}

	template < typename T, class Alloc >
	typename List<T, Alloc>::reference List<T, Alloc>::back()
	{

		return(_end->previous->value);
	}

	template < typename T, class Alloc >
	typename List<T, Alloc>::const_reference List<T, Alloc>::back() const
	{
		return(_end->previous->value);
	}

	//-------------------------- MODIFIERS ---------------------------

	template < typename T, class Alloc >
	void List<T, Alloc>::assign(size_type n, const value_type& val)
	{
		clear();
		for (size_type i = 0; i < n; i++)
			push_back(val);
	}

	template < typename T, class Alloc >
	template < typename InputIterator >
	void List<T, Alloc>::assign(InputIterator first, InputIterator last)
	{
		clear();
		constructor_assign_helper(first, last, typename ft::is_integral<InputIterator>::type());
	}

	template < typename T, class Alloc >
	void List<T, Alloc>::push_front(const value_type& val)
	{
		insert(begin(), val);
	}
	
	template < typename T, class Alloc >
	void List<T, Alloc>::pop_front()
	{
		erase(begin());
	}

	template < typename T, class Alloc >
	void List<T, Alloc>::push_back(const value_type& val)
	{
		insert(end(), val);
	}
	
	template < typename T, class Alloc >
	void List<T, Alloc>::pop_back()
	{
		erase(--end());
	}

	template < typename T, class Alloc >
	void List<T, Alloc>::insert(iterator pos, size_type count, const T& value)
	{
		iterator next = pos;
		iterator prev = pos;
		link_pointer n;
		prev--;
		for (size_t i = 0; i < count; i++)
		{
			if (_begin == _end)
			{
				_begin = node_alloc(_alloc).allocate(1);
				node_alloc(_alloc).construct(_begin, Link<T>(_rend, value, _end));
				_end->previous = _begin;
				_rend->next = _begin;
				n = _begin;
			}
			else
			{
				n = node_alloc(_alloc).allocate(1);
				node_alloc(_alloc).construct(n, Link<T>(prev.current, value, next.current));
				prev.current->next = n;
				next.current->previous = n;
				if (pos.current == _begin)
					_begin = n;
				prev++;
			}
			_size++;
		}
	}

	template < typename T, class Alloc >
	template< class InputIterator >
	void List<T, Alloc>::insert(iterator pos, InputIterator first, InputIterator last)
	{
		insert_helper(pos, first, last, typename ft::is_integral<InputIterator>::type());
	}

	template < typename T, class Alloc >
	typename List<T, Alloc>::iterator List<T, Alloc>::insert(iterator pos, const T &value)
	{
		iterator next = pos;
		iterator prev = pos;
		link_pointer n;
		if (_begin == _end)
		{
			_begin = node_alloc(_alloc).allocate(1);
			node_alloc(_alloc).construct(_begin, Link<T>(_rend, value, _end));
			_end->previous = _begin;
			_rend->next = _begin;
			n = _begin;
		}
		else
		{
			prev--;
			n = node_alloc(_alloc).allocate(1);
			node_alloc(_alloc).construct(n, Link<T>(prev.current, value, next.current));
			prev.current->next = n;
			next.current->previous = n;
			if (pos.current == _begin)
				_begin = n;
		}
		_size++;
		return (iterator(n));
	}

	template < typename T, class Alloc >
	typename List<T, Alloc>::iterator List<T, Alloc>::erase(iterator pos)
	{
		iterator ret = pos;
		if (pos.current == _end || pos.current == _rend)
			return (_end);
		if (pos.current == _begin)
			_begin = _begin->next;
		pos.current->previous->next = pos.current->next;
		pos.current->next->previous = pos.current->previous;
		ret++;
		node_alloc(_alloc).destroy(pos.current);
		node_alloc(_alloc).deallocate(pos.current, 1);
		_size--;
		return (ret);
	}

	template < typename T, class Alloc >
	typename List<T, Alloc>::iterator List<T, Alloc>::erase(iterator first, iterator last)
	{
		iterator prev(first.current->previous);
		while (first.current != last.current && first.current != _end && first.current != _rend)
		{
			first++;
			if (first.current->previous == _begin)
			{
				node_alloc(_alloc).destroy(first.current->previous);
				node_alloc(_alloc).deallocate(first.current->previous, 1);	
				_begin = NULL;
			}
			else
			{
				node_alloc(_alloc).destroy(first.current->previous);
				node_alloc(_alloc).deallocate(first.current->previous, 1);	
			}
			_size--;	
		}
		last.current->previous = prev.current;
		prev.current->next = last.current;
		if (_begin == NULL)
			_begin = last.current;
		return (first);
	}

	template < typename T, class Alloc >
	void List<T, Alloc>::clear()
	{
		if (_begin == _end)
		{
			return ;
		}
		erase(begin(), end());
		_begin = _end;
		_end->previous = _rend;
	}

	template < typename T, class Alloc >
	void List<T, Alloc>::swap(List &other) {
		Link<T> *tmp_end = other._end;
		Link<T> *tmp_begin = other._begin;
		Link<T> *tmp_rend = other._rend;
		size_t tmp_size = other._size;

		other._end = _end;
		other._begin = _begin;
		other._rend = _rend;
		other._size = _size;

		_end = tmp_end;
		_begin = tmp_begin;
		_rend = tmp_rend;
		_size = tmp_size;
	}

	template< class T, class Alloc >
	void List<T, Alloc>::resize(size_type count, T value)
	{
		if (size() < count)
		{
			while (size() < count)
				push_back(value);
		}
		else if (size() > count)
		{
			while (size() > count)
				pop_back();
		}
	}

	template < class T, class Alloc >
	void List<T, Alloc>::merge(List<T, Alloc> &other)
	{
		if (this == &other) return;
		ft::List<T, Alloc> tmp;
		iterator itr = begin();
		iterator itr_other = other.begin();
		while (itr.current != _end || itr_other.current != other._end)
			if (itr.current != _end && itr_other.current != other._end)
			{
				if (*itr < *itr_other)
				{
					tmp.push_back(*itr);
					itr++;
				}
				else
				{
					tmp.push_back(*itr_other);
					itr_other++;
				}
			}
			else if (itr.current != _end)
			{
				tmp.push_back(*itr);
				itr++;
			}
			else
			{
				tmp.push_back(*itr_other);
				itr_other++;
			}
		other.clear();
		swap(tmp);
	}

	template < class T, class Alloc >
	template < class Compare >
	void List<T, Alloc>::merge(List<T, Alloc> &other, Compare comp)
	{
		ft::List<T, Alloc> tmp;
		iterator itr = begin();
		iterator itr_other = other.begin();
		while (itr.current != _end || itr_other.current != other._end)
			if (itr.current != _end && itr_other.current != other._end)
			{
				if (!comp(*itr_other, *itr))
				{
					tmp.push_back(*itr);
					itr++;
				}
				else
				{
					tmp.push_back(*itr_other);
					itr_other++;
				}
			}
			else if (itr.current != _end)
			{
				tmp.push_back(*itr);
				itr++;
			}
			else
			{
				tmp.push_back(*itr_other);
				itr_other++;
			}
		swap(tmp);
	}

	template < class T, class Alloc >
	void List<T, Alloc>::splice(List<T, Alloc>::const_iterator pos, List &other)
	{
		insert(pos, other.begin(), other.end());
		other.erase(other.begin(), other.end());
	}

	template < class T, class Alloc >
	void List<T, Alloc>::splice(List<T, Alloc>::const_iterator pos, List &other, List<T, Alloc>::const_iterator it) 
	{
		insert(pos, *it);
		other.erase(it);
	}

	template < class T, class Alloc >
	void List<T, Alloc>::splice(List<T, Alloc>::const_iterator pos, List &other, List<T, Alloc>::const_iterator first, List<T, Alloc>::const_iterator last)
	{
		insert(pos, first, last);
		other.erase(first, last);
	}

	template < class T, class Alloc >
	void List<T, Alloc>::remove(const T &value)
	{
		ft::List<T, Alloc> tmp;
		for (iterator itr = begin(); itr != end(); itr++)
			if (*itr != value)
				tmp.push_back(*itr);
		swap(tmp);
	}
	
	template < class T, class Alloc >
	template < class UnaryPredictate >
	void List<T, Alloc>::remove_if(UnaryPredictate p) 
	{
		ft::List<T, Alloc> tmp;
		for (iterator itr = begin(); itr != end(); itr++)
			if (!p(*itr))
				tmp.push_back(*itr);
		swap(tmp);
	}

	template < class T, class Alloc >
	void List<T, Alloc>::reverse()
	{
		List<T, Alloc> tmp;
		for (iterator itr = begin(); itr != end(); itr++)
			tmp.push_front(*itr);
		swap(tmp);			
	}

	template < class T, class Alloc >
	void List<T, Alloc>::unique() 
	{
		List<T, Alloc> tmp;
		for (iterator itr = begin(); itr != end(); itr++)
			if (tmp.empty() || tmp.back() != *itr)
				tmp.push_back(*itr);
		swap(tmp);
	}

	template < class T, class Alloc >
	template < class BinaryPredicate >
	void List<T, Alloc>::unique(BinaryPredicate p) 
	{
		List<T, Alloc> tmp;
		for (iterator itr = begin(); itr != end(); itr++)
			if (!p(tmp.back(), *itr))
				tmp.push_back(*itr);
		swap(tmp);
	}

	template < class T, class Alloc >
	void List<T, Alloc>::sort()
	{
		bool swap = true;
		while (swap && this->_size > 0)
		{
			swap = false;
			iterator itr_a = begin(), itr_b = begin();
			itr_b++;
			while (itr_b != end())
			{
				if (*itr_a > *itr_b) 
				{
					T tmp = *itr_a;
					*itr_a = *itr_b;
					*itr_b = tmp;
					swap = true;
				}
				itr_a++;
				itr_b++;
			}
		}
	}

	template < class T, class Alloc >
	template < class Compare >
	void List<T, Alloc>::sort(Compare comp)
	{
		bool swap = true;
		while (swap && this->_size > 0)
		{
			swap = false;
			iterator itr_a = begin(), itr_b = begin();
			itr_b++;
			while (itr_b != end())
			{
				if (comp(*itr_b, *itr_a))
				{
					T tmp = *itr_a;
					*itr_a = *itr_b;
					*itr_b = tmp;
					swap = true;
				}
				itr_a++;
				itr_b++;
			}
		}
	}

	//---------------------------------- OPERATORS --------------------------------------------------

	template < typename T, class Alloc >
	bool operator==(List<T, Alloc> &lhs, List<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);

		typename ft::List<T, Alloc>::iterator itr_l = lhs.begin();
		typename ft::List<T, Alloc>::iterator itr_r = rhs.begin();
		while (itr_l != lhs.end() && itr_r != rhs.end())
		{
			if (*itr_l != *itr_r)
				return (false);
			itr_l++;
			itr_r++;
		}
		return (true);
	}

	template < typename T, class Alloc >
	bool operator!=(List<T, Alloc> &lhs, List<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (true);

		typename ft::List<T, Alloc>::iterator itr_l = lhs.begin();
		typename ft::List<T, Alloc>::iterator itr_r = rhs.begin();
		while (itr_l != lhs.end() && itr_r != rhs.end())
		{
			if (*itr_l != *itr_r)
				return (true);
			itr_l++;
			itr_r++;
		}
		return (false);
	}

	template < typename T, class Alloc >
	bool operator<(List<T, Alloc> &lhs, List<T, Alloc> &rhs)
	{
		typename ft::List<T, Alloc>::iterator itr_l = lhs.begin();
		typename ft::List<T, Alloc>::iterator itr_r = rhs.begin();
		while (itr_l != lhs.end() && itr_r != rhs.end())
		{
			if (*itr_l < *itr_r)
				return (true);
			else if (*itr_l > *itr_r)
				return (false);
			itr_l++;
			itr_r++;
		}
		return (false);
	}

	template < typename T, class Alloc >
	bool operator<=(List<T, Alloc> &lhs, List<T, Alloc> &rhs)
	{
		typename ft::List<T, Alloc>::iterator itr_l = lhs.begin();
		typename ft::List<T, Alloc>::iterator itr_r = rhs.begin();
		if (lhs.empty() && rhs.empty())
			return (true);
		while (itr_l != lhs.end() && itr_r != rhs.end())
		{
			if (*itr_l < *itr_r)
				return (true);
			if (*itr_l > *itr_r)
				return (false);
			itr_l++;
			itr_r++;
		}
		return (true);
	}

	template < typename T, class Alloc >
	bool operator>(List<T, Alloc> &lhs, List<T, Alloc> &rhs)
	{
		typename ft::List<T, Alloc>::iterator itr_l = lhs.begin();
		typename ft::List<T, Alloc>::iterator itr_r = rhs.begin();
		while (itr_l != lhs.end() && itr_r != rhs.end())
		{
			if (*itr_l > *itr_r)
				return (true);
			else if (*itr_l < *itr_r)
				return (false);
			itr_l++;
			itr_r++;
		}
		return (false);
	}

	template < typename T, class Alloc >
	bool operator>=(List<T, Alloc> &lhs, List<T, Alloc> &rhs)
	{
		typename ft::List<T, Alloc>::iterator itr_l = lhs.begin();
		typename ft::List<T, Alloc>::iterator itr_r = rhs.begin();
		if (lhs.empty() && rhs.empty())
			return (true);
		while (itr_l != lhs.end() && itr_r != rhs.end())
		{
			if (*itr_l > *itr_r)
				return (true);
			if (*itr_l < *itr_r)
				return (false);
			itr_l++;
			itr_r++;
		}
		return (true);
	}
	
	//----------------------------------OUR OWN PRIVATE STUFF--------------------------------------------------

	template <typename T, class Alloc>
	template <class InputIterator>
	void	List<T, Alloc>::insert_helper(ft::List<T, Alloc>::iterator pos, const InputIterator& first, const InputIterator& last, void *)
	{
		InputIterator & first_itr = const_cast<InputIterator&>(first);
		InputIterator from(first_itr);
		while (from != last)
		{
			pos = insert(pos, from.current->value);
			pos++;
			from.current = from.current->next;
		}
	}

	template <typename T, class Alloc>
	template <class InputIterator>
	void	List<T, Alloc>::insert_helper(ft::List<T, Alloc>::iterator pos, const InputIterator& size, const InputIterator& val, int)
	{
		for (int i = 0; i < size; i++)
			insert(pos, val);
	}

	template <typename T, class Alloc>
	template <class InputIterator>
	void	List<T, Alloc>::constructor_assign_helper(InputIterator & first, InputIterator & last, void *)
	{
		while (first != last)
		{
			push_back(*first);
			first++;
			_size++;
		}
	}

	template <typename T, class Alloc>
	template <class InputIterator>
	void	List<T, Alloc>::constructor_assign_helper(InputIterator & size, InputIterator & val, int)
	{
		clear();
		for (int i = 0; i < size; i++)
			push_back(val);
	}
}

#endif