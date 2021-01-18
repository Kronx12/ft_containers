#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>
# include <memory>
# include <string>
# include <stack>

# ifdef __linux__
#  include <limits>
# endif

namespace ft
{
	template < typename It >
	class ReverseIterator : public It
	{
		public:
			using typename It::link_type;
			using typename It::link_pointer;
			using typename It::value_type;
			using typename It::pointer;
			using typename It::const_pointer;
			using typename It::reference;
			using typename It::const_reference;
		
		
			ReverseIterator() : It(){};
			ReverseIterator(It const & it) : It(it){};
			ReverseIterator(ReverseIterator const & rhs)
			{
				this->current = rhs.current;
			};
			~ReverseIterator(){};
			ReverseIterator &		operator=( ReverseIterator const & rhs )
			{
				this->current = rhs->current;
			}

			ReverseIterator &operator++()
			{
				this->current = this->current->previous;
				return(*this);
			}
			ReverseIterator operator++(int)
			{
				ReverseIterator tmp(*this);
				this->current = this->current->previous;
				return(tmp);
			}

			virtual ReverseIterator &operator--()
			{
				this->current = this->current->next;
				return(*this);
			}
			virtual ReverseIterator operator--(int)
			{
				ReverseIterator tmp(*this);
				this->current = this->current->next;
				return(tmp);
			}
	};
	
	template < class T, class L >
	class Iterator
	{
		public:
			typedef L link_type;
			typedef link_type* link_pointer;
			typedef T value_type;
			typedef value_type* pointer;
			typedef const value_type* const_pointer;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef const_reference iterator_category;

			link_pointer current;

		public:
			//BASICS
			Iterator(link_pointer li)
			{
				this->current = li;
			};

			Iterator( Iterator const & rhs ) : current(rhs.current){};
			~Iterator(){};
			Iterator &		operator=( Iterator const & rhs )
			{
				this->current = rhs->current;
			}

			//BASICS INCREMENTATION
			Iterator &operator++()
			{
				this->current = this->current->next;
				return(*this);
			}
			Iterator operator++(int)
			{
				Iterator tmp(*this);
				this->current = this->current->next;
				return(tmp);
			}

			//Input Category
			bool operator==(const Iterator & rhs)
			{
				return (this->current == rhs.current);
			}
			bool operator!=(const Iterator & rhs)
			{
				return (current != rhs.current);
			}
			reference operator*()
			{
				return(this->current->value);
			}
			reference operator->()
			{
				return(this->current->value);
			}

			//Output Category ?????????????????????????? WHAT DO?

			//Forward Specific Category
			Iterator()
			{
				current = NULL;
			};

			//Bidirectional Category
			Iterator &operator--()
			{
				this->current = this->current->previous;
				return(*this);
			}
			Iterator operator--(int)
			{
				Iterator tmp(*this);
				this->current = this->current->previous;
				return(tmp);
			}
	};

	template < typename T >
	class Link
	{
		public :
			T		value;
			Link	*next;
			Link	*previous;
			Link(const T& val) : value(val), next(NULL), previous(NULL) {};
			Link(Link *pre, const T& val, Link *_next) :value(val), next(_next), previous(pre) {};
			Link() : value(T()), next(NULL), previous(NULL) {};
	};

	template < class T >
	class List
	{
		public:
			typedef T value_type;
			typedef typename std::allocator<value_type> allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef Link<value_type> link_type;
			typedef link_type* link_pointer;
			typedef Iterator<value_type, link_type> iterator;
			typedef Iterator<const value_type, const link_type> const_iterator;
			typedef ReverseIterator<iterator> reverse_iterator;
			typedef ReverseIterator<const_iterator> const_reverse_iterator;
			typedef std::ptrdiff_t difference_type;
			typedef size_t size_type;

		private:
			Link<T> *_end;
			Link<T> *_begin;
			Link<T> *_rend;
			size_t _size;
			allocator_type _alloc;

			template< class A, class B >
			int grugage(A a, B b) {
				char t[] = {'c', 'h', 's', 't', 'i', 'j', 'l', 'm'};

				for (int i = 0; i < 8; i++)
					if (typeid(a).name()[0] == t[i]) {
						for (int i = 0; i < static_cast<int>(a); i++)
							push_back(b);
						return (1);
					}
				return (0);
			}

		public:
			explicit List (const allocator_type& alloc = allocator_type());
			explicit List (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			template < class InputIterator >
			List (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			List (const List& x);
			~List();
			List<T> &operator=( List const & rhs );
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
			reference back();
//---
			//Modifiers
			void assign(size_type n, const value_type& val);

			template < typename InputIterator >
			void assign(InputIterator first, InputIterator last);
			void push_front(const value_type& val);
			void pop_front();
			void push_back(const value_type& val);
			void pop_back();

			template< class InputIt >
			void insert(iterator pos, InputIt first, InputIt last);
			iterator insert(iterator pos, const T &value);
			void insert(iterator pos, size_type count, const T& value);

			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);
			void swap(List &lst);
			void resize();
			void clear();

			//Operations
			void splice(const_iterator pos, List &other);
			void splice(const_iterator pos, List &other, const_iterator it);
			void splice(const_iterator pos, List &other, const_iterator first, const_iterator last);

			template< class UnaryPredictate >
			void remove_if(UnaryPredictate p);
			void remove(const T &value);

			template < class BinaryPredicate >			
			void unique(BinaryPredicate p);
			void unique();

			template < class Compare >
			void merge(List &other, Compare comp);
			void merge(List &other);

			template < class Compare >
			void sort(Compare comp);
			void sort();
			void reverse();			
	};


	//-------------------------- CONSTRUCTOR --------------------------
	template < typename T >
	List<T>::List(const List<T>::allocator_type& alloc)
		: _end(new Link<T>()), _begin(_end), _rend(new Link<T>(NULL, T(), _end)), _size(0), _alloc(alloc)
	{
		_end->previous = _rend;
	}

	template < typename T >
	List<T>::List(size_type n, const value_type& val, const allocator_type& alloc)
		: _end(new Link<T>()), _begin(_end), _rend(new Link<T>(NULL, T(), _end)), _size(0), _alloc(alloc)
	{
		for (size_type i = 0; i < n; i++)
			push_back(val);
	}

	template < typename T >
	template < class InputIterator >
	List<T>::List(InputIterator first, InputIterator last, const allocator_type& alloc)
		: _end(new Link<T>()), _begin(_end), _rend(new Link<T>(NULL, T(), _end)), _size(0), _alloc(alloc)
	{
		if (grugage(first, last))
			return ;
		insert(begin(), first, last);
	}

	template < typename T >
	List<T>::List(const List& x)
		: _end(new Link<T>()), _begin(_end), _rend(new Link<T>(NULL, T(), _end)), _size(0), _alloc(x._alloc)
	{
		for (List<T>::const_iterator itr = x.begin(); itr != x.end(); itr++)
			push_back(*itr);
	}

	template < typename T >
	List<T> &List<T>::operator=(List<T> const & rhs) {
        if (this == &rhs) return(*this);
		this->~List();
        return *new(this) List(rhs);
	}

	template < typename T >
	List<T>::~List()
	{
		clear();
	}

	//-------------------------- ITERATORS --------------------------
	template < typename T >
	typename List<T>::iterator List<T>::begin()
	{
		return(iterator(this->_begin));
	}

	template < typename T >
	typename List<T>::const_iterator List<T>::begin() const
	{
		return(const_iterator(this->_begin));
	}

	template < typename T >
	typename List<T>::iterator List<T>::end()
	{
		return(iterator(this->_end));
	}

	template < typename T >
	typename List<T>::const_iterator List<T>::end() const
	{
		return(const_iterator(this->_end));
	}

	//------------------- REVERSE ITERATORS ------------------------
	template < typename T >
	typename List<T>::reverse_iterator List<T>::rbegin()
	{
		return(reverse_iterator(this->_end->previous));
	}

	template < typename T >
	typename List<T>::const_reverse_iterator List<T>::rbegin() const
	{
		return(const_reverse_iterator(this->_end->previous));
	}

	template < typename T >
	typename List<T>::reverse_iterator List<T>::rend()
	{
		return(reverse_iterator(this->_rend));
	}

	template < typename T >
	typename List<T>::const_reverse_iterator List<T>::rend() const
	{
		return(const_reverse_iterator(this->_rend));
	}

	//-------------------------- CAPACITY --------------------------
	template < typename T >
	bool List<T>::empty() const
	{
		return(begin() == end());
	}

	template < typename T >
	typename List<T>::size_type List<T>::size() const
	{
		return(_size);
	}

	template < typename T >
	typename List<T>::size_type List<T>::max_size() const
	{
		return (std::numeric_limits<size_type>::max() / sizeof(link_type));
	}

	//-------------------------- ELEMENT ACCESS --------------------------
	template < typename T >
	typename List<T>::reference List<T>::front()
	{
		return(_begin->value);
	}

	template < typename T >
	typename List<T>::reference List<T>::back()
	{
		return(_end->previous->value);
	}

	//-------------------------- MODIFIERS ---------------------------

	template < typename T >
	void List<T>::assign(size_type n, const value_type& val)
	{
		clear();
		for (size_type i = 0; i < n; i++)
			push_back(val);
	}

	template < typename T >
	template < typename InputIterator >
	void List<T>::assign(InputIterator first, InputIterator last)
	{
		List<T> tmp;
		for (;first != last; first++)
			tmp.push_back(*first);
		swap(tmp);
		tmp.~List();
	}

	template < typename T >
	void List<T>::push_front(const value_type& val)
	{
		insert(begin(), val);
	}
	
	template < typename T >
	void List<T>::pop_front()
	{
		erase(begin());
	}

	template < typename T >
	void List<T>::push_back(const value_type& val)
	{
		insert(end(), val);
	}
	
	template < typename T >
	void List<T>::pop_back()
	{
		erase(end());
	}

	template < typename T >
	typename List<T>::iterator List<T>::insert(iterator pos, const T &value)
	{
		iterator next = pos;
		iterator prev = pos;
		link_pointer n;
		if (_begin == _end)
		{
			_begin = new Link<T>(_rend, value, _end);
			_end->previous = _begin;
			_rend->next = _begin;
			n = _begin;
		}
		else
		{
			prev--;
			n = new Link<T>(prev.current, value, next.current);
			prev.current->next = n;
			next.current->previous = n;
		}
		_size++;
		return (iterator(n));
	}

	template < typename T >
	typename List<T>::iterator List<T>::erase(iterator pos)
	{
		iterator ret = pos;
		if (pos.current == _end || pos.current == _rend)
			return (_end);
		if (pos.current == _begin)
			_begin = _begin->next;
		pos.current->previous->next = pos.current->next;
		pos.current->next->previous = pos.current->previous;
		ret++;
		delete (pos.current);
		_size--;
		return (ret);
	}

	template < typename T >
	typename List<T>::iterator List<T>::erase(iterator first, iterator last)
	{
		iterator prev(first.current->previous);
		while (first.current != last.current && first.current != _end && first.current != _rend)
		{
			first++;
			if (first.current->previous == _begin)
			{
				delete(first.current->previous);
				_begin = NULL;
			}
			else
			{
				delete(first.current->previous);
			}
			_size--;	
		}
		last.current->previous = prev.current;
		prev.current->next = last.current;
		if (_begin == NULL)
			_begin = last.current;
		return (first);
	}

	template < typename T >
	void List<T>::clear()
	{
		if (_begin == _end)
		{
			return ;
		}
		erase(begin(), end());
		_begin = _end;
		_end->previous = _rend;
	}

	template < typename T >
	void List<T>::swap(List &other) {
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

	template < class T >
	void List<T>::merge(List<T> &other)
	{
		if (this == &other) return;
		while (other.size() > 0)
			for (iterator itr = begin(); itr != end(); itr++)
				if (*other.begin() < *itr)
				{
					insert(itr, *other.begin());
					other.pop_front();
					break ;
				}
	}

	template < class T >
	template < class Compare >
	void List<T>::merge(List<T> &other, Compare comp)
	{
		if (this == &other) return;
		while (other.size() > 0)
			for (iterator itr = begin(); itr != end(); itr++)
				if (comp(*other.begin(), *itr))
				{
					insert(itr, *other.begin());
					other.pop_front();
					break ;
				}
	}

	template < class T >
	void List<T>::splice(List<T>::const_iterator pos, List &other)
	{
		for (iterator itr = other.begin(); itr != other.end(); itr++)
		{
			insert(pos, *itr);
			other.erase(itr);
			pos++;
		}
	}

	template < class T >
	void List<T>::splice(List<T>::const_iterator pos, List &other, List<T>::const_iterator it) 
	{
		for (; it != other.end(); it++)
		{
			insert(pos, *it);
			other.erase(it);
			pos++;
		}
	}

	template < class T >
	void List<T>::splice(List<T>::const_iterator pos, List &other, List<T>::const_iterator first, List<T>::const_iterator last)
	{
		for (; first != last; first++)
		{
			insert(pos, *first);
			other.erase(first);
			pos++;
		}
	}

	template < class T >
	void List<T>::remove(const T &value)
	{
		for (iterator itr = begin(); itr != end(); itr++)
			if (*itr == value)
				erase(itr);
	}
	
	template < class T >
	template < class UnaryPredictate >
	void List<T>::remove_if(UnaryPredictate p) 
	{
		for (iterator itr = begin(); itr != end(); itr++)
			if (p(*itr))
				erase(itr);
	}

	template < class T >
	void List<T>::reverse()
	{
		List<T> tmp;
		for (iterator itr = begin(); itr != end(); itr++)
			tmp.push_front(*itr);
		swap(tmp);
		tmp.~List();				
	}

	template < class T >
	void List<T>::unique() 
	{
		List<T> tmp;
		for (iterator itr = begin(); itr != end(); itr++)
			if (!(tmp.back() == *itr))
				tmp.push_back(*itr);
		swap(tmp);
		tmp.~List();
	}

	template < class T >
	template < class BinaryPredicate >
	void List<T>::unique(BinaryPredicate p) 
	{
		List<T> tmp;
		for (iterator itr = begin(); itr != end(); itr++)
			if (!p(tmp.back(), *itr))
				tmp.push_back(*itr);
		swap(tmp);
		tmp.~List();
	}

	template < class T >
	void List<T>::sort()
	{
		bool swap = true;
		while (swap)
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

	template < class T >
	template < class Compare >
	void List<T>::sort(Compare comp)
	{
		bool swap = true;
		while (swap)
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
}

#endif