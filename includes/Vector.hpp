#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <Iterator.hpp>

namespace ft
{
	template< class T, class Allocator = std::allocator<T> >
	class Vector
	{
		public:
			// typedef
			typedef T value_type;
			typedef Allocator allocator_type;
			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef typename Allocator::reference reference;
			typedef typename Allocator::const_reference const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			typedef VectorIterator< T > iterator;
			typedef ConstVectorIterator< T > const_iterator;
			typedef ReverseIterator< iterator > reverse_iterator;
			typedef ReverseIterator< const_iterator > const_reverse_iterator;

		private:
			pointer _data;
			size_type _size;
			size_type _capacity;
			allocator_type _alloc;

			void realloc(size_type len);

			template <class InputIterator>
			void constructor_helper(const InputIterator& first, const InputIterator& last, void *);
			template <class InputIterator>
			void constructor_helper(const InputIterator& count, const InputIterator& value, int);

			template <class InputIterator>
			void assign_helper(const InputIterator& first, const InputIterator& last, void *);
			template <class InputIterator>
			void assign_helper(const InputIterator& count, const InputIterator& value, int);

			template <class InputIterator>
			void insert_helper(iterator pos, const InputIterator& first, const InputIterator& last, void *);
			template <class InputIterator>
			void insert_helper(iterator pos, const InputIterator& count, const InputIterator& value, int);
	
		public:
			// constructors
			Vector();
			explicit Vector(const Allocator &alloc);
			explicit Vector(size_type count, const T &value = T(), const Allocator &alloc = Allocator());
			template< class InputIterator >
			Vector(InputIterator first, InputIterator last, const Allocator &alloc = Allocator());
			Vector(const Vector &other);

			Vector &operator=(const Vector &other); 

			void assign(size_type count, const T &value);
			template<class InputIterator>
			void assign(InputIterator first, InputIterator last);

			~Vector(); 

			// element access
			reference at(size_type pos); // TODO TEST
			const_reference at(size_type pos) const; // TODO TEST
			
			reference operator[](size_type pos);// TODO TEST
			const_reference operator[](size_type pos) const;// TODO TEST

			reference front();// TODO TEST
			const_reference front() const;// TODO TEST

			reference back();// TODO TEST
			const_reference back() const;// TODO TEST
//--
			// iterator
			iterator begin();// TODO TEST
			const_iterator begin() const;// TODO TEST

			iterator end();// TODO TEST
			const_iterator end() const;// TODO TEST

			iterator rbegin();// TODO TEST
			const_iterator rbegin() const;// TODO TEST
			
			iterator rend();// TODO TEST
			const_iterator rend() const;// TODO TEST
//--
			// capacity
			bool empty() const;// TODO TEST
			size_type size() const;// TODO TEST
			size_type max_size() const;// TODO TEST
			void reserve(size_type new_cap);// TODO TEST
			size_type capacity() const;// TODO TEST
//--
			// modifiers
			void clear();// TODO TEST
//--
			iterator insert(iterator pos, const T &value);// TODO TEST
			void insert(iterator pos, size_type count, const T &value);// TODO TEST
			template< class InputIterator >
			void insert(iterator pos, InputIterator first, InputIterator last);// TODO TEST

			iterator erase(iterator pos);// TODO TEST
			iterator erase(iterator first, iterator last);// TODO TEST

			void push_back(const T &value);// TODO TEST
			void pop_back();// TODO TEST

			void resize(size_type count, T value = T());// TODO TEST

			void swap(Vector &other);// TODO TEST
	};

	// private:
	template< class T, class Allocator >
	void Vector<T, Allocator>::realloc(size_type len)
	{
		len = len == 0 || len == 1 ? len + 1 : len;
		pointer tmp = _alloc.allocate(len);

		for (size_type i = 0; i < _size && i < len; i++)
			tmp[i] = _data[i];
		_alloc.deallocate(_data, _capacity);
		_data = tmp;
		_capacity = len;
	}

	template< class T, class Allocator >
	template <class InputIterator>
	void Vector<T, Allocator>::constructor_helper(const InputIterator& first, const InputIterator& last, void *)
	{
		InputIterator & first_itr = const_cast<InputIterator&>(first);
		InputIterator from(first_itr);
		_size = 0;
		_capacity = 0;
		_data = NULL;
		for (;from != last; from++)
			push_back(*from);
	}
	
	template< class T, class Allocator >
	template <class InputIterator>
	void Vector<T, Allocator>::constructor_helper(const InputIterator& count, const InputIterator& value, int)
	{
		_size = 0;
		_capacity = 0;
		_data = NULL;
		size_type size = count;
		for (size_type i = 0; i < size; i++)
			push_back(value);
	}

	template< class T, class Allocator >
	template <class InputIterator>
	void Vector<T, Allocator>::assign_helper(const InputIterator& first, const InputIterator& last, void *)
	{
		InputIterator & first_itr = const_cast<InputIterator&>(first);
		InputIterator from(first_itr);
		clear();
		for (; from != last; from++)
			push_back(*from);
	}

	template< class T, class Allocator >
	template <class InputIterator>
	void Vector<T, Allocator>::assign_helper(const InputIterator& count, const InputIterator& value, int)
	{
		clear();
		size_type size = count;
		for (size_type i = 0; i < size; i++)
			push_back(value);
	}

	template< class T, class Allocator >
	template <class InputIterator>
	void Vector<T, Allocator>::insert_helper(iterator pos, const InputIterator& first, const InputIterator& last, void *)
	{
		Vector<T> tmp;
		InputIterator & first_itr = const_cast<InputIterator&>(first);
		InputIterator from(first_itr);

		for (iterator itr = begin(); itr != pos; itr++)
			tmp.push_back(*itr);
		for (;from != last; from++)
			tmp.push_back(*from);
		for (iterator itr = pos; itr != end(); itr++)
			tmp.push_back(*itr);
		swap(tmp);
	}

	template< class T, class Allocator >
	template <class InputIterator>
	void Vector<T, Allocator>::insert_helper(iterator pos, const InputIterator& count, const InputIterator& value, int)
	{
		Vector<T> tmp;

		for (iterator itr = begin(); itr != pos; itr++)
			tmp.push_back(*itr);
		for (int i = 0; i < count; i++)
			tmp.push_back(value);
		for (iterator itr = pos; itr != end(); itr++)
			tmp.push_back(*itr);
		swap(tmp);
	}

	// constructors:
	template< class T, class Allocator >
	Vector<T, Allocator>::Vector() : _data(NULL), _size(0), _capacity(0), _alloc(allocator_type()) {}
	
	template< class T, class Allocator >
	Vector<T, Allocator>::Vector(const Allocator &alloc) : _data(NULL), _size(0), _capacity(0), _alloc(alloc) {}
	
	template< class T, class Allocator >
	Vector<T, Allocator>::Vector(size_type count, const T &value, const Allocator &alloc) : _alloc(alloc)
	{
		_size = 0;
		_capacity = 0;
		_data = NULL;
		_alloc = alloc;
		for (std::size_t i = 0; i < count; i++)
			push_back(value);
	}
	
	template< class T, class Allocator >
	template< class InputIterator >
	Vector<T, Allocator>::Vector(InputIterator first, InputIterator last, const Allocator &alloc) : _alloc(alloc)
	{
		constructor_helper(first, last, typename ft::is_integral<InputIterator>::type());
	}
	
	template< class T, class Allocator >
	Vector<T, Allocator>::Vector(const Vector &other)
	{
		_size = 0;
		_capacity = 0;
		_data = NULL;
		_alloc = other._alloc;
		for (iterator itr = other.begin(); itr != other.end(); itr++)
			push_back(*itr);
	}

	template< class T, class Allocator >
	Vector<T, Allocator> &Vector<T, Allocator>::operator=(const Vector &other)
	{
		if (this == &other) return(*this);
		this->~Vector();
		return *new(this) Vector(other);
	}

	template< class T, class Allocator >
	void Vector<T, Allocator>::assign(size_type count, const T &value)
	{
		clear();
		for (size_type i = 0; i < count; i++)
			push_back(value);
	}

	template< class T, class Allocator >
	template<class InputIterator>
	void Vector<T, Allocator>::assign(InputIterator first, InputIterator last)
	{
		assign_helper(first, last, typename ft::is_integral<InputIterator>::type());
	}

	template< class T, class Allocator >
	Vector<T, Allocator>::~Vector()
	{
		_alloc.deallocate(_data, _size);
	}

	// element access
	template< class T, class Allocator >
	typename Vector<T, Allocator>::reference Vector<T, Allocator>::at(size_type pos)
	{
		if (pos >= 0 && pos < _size)
			return (_data[pos]);
		throw std::out_of_range("");
	}
	template< class T, class Allocator >
	typename Vector<T, Allocator>::const_reference Vector<T, Allocator>::at(size_type pos) const
	{
		if (pos >= 0 && pos < _size)
			return (_data[pos]);
		throw std::out_of_range("");
	}
		
	template< class T, class Allocator >
	typename Vector<T, Allocator>::reference Vector<T, Allocator>::operator[](size_type pos) { return (_data[pos]); }
	template< class T, class Allocator >
	typename Vector<T, Allocator>::const_reference Vector<T, Allocator>::operator[](size_type pos) const { return (_data[pos]); }

	template< class T, class Allocator >
	typename Vector<T, Allocator>::reference Vector<T, Allocator>::front() { return (_data[0]); }
	template< class T, class Allocator >
	typename Vector<T, Allocator>::const_reference Vector<T, Allocator>::front() const { return (_data[0]); }

	template< class T, class Allocator >
	typename Vector<T, Allocator>::reference Vector<T, Allocator>::back() { return (_data[_size - 1]); }
	template< class T, class Allocator >
	typename Vector<T, Allocator>::const_reference Vector<T, Allocator>::back() const { return (_data[_size - 1]); }

	// iterator
	template< class T, class Allocator >
	typename Vector<T, Allocator>::iterator Vector<T, Allocator>::begin() { return (iterator(_data, _size, 0)); }
	template< class T, class Allocator >
	typename Vector<T, Allocator>::const_iterator Vector<T, Allocator>::begin() const { return (const_iterator(_data, _size, 0)); }

	template< class T, class Allocator >
	typename Vector<T, Allocator>::iterator Vector<T, Allocator>::end() { return (iterator(_data, _size, _size)); }
	template< class T, class Allocator >
	typename Vector<T, Allocator>::const_iterator Vector<T, Allocator>::end() const { return (const_iterator(_data, _size, _size)); }

	template< class T, class Allocator >
	typename Vector<T, Allocator>::iterator Vector<T, Allocator>::rbegin() { return (reverse_iterator(_data, _size, _size - 1)); }
	template< class T, class Allocator >
	typename Vector<T, Allocator>::const_iterator Vector<T, Allocator>::rbegin() const { return (const_reverse_iterator(_data, _size, _size - 1)); }
			
	template< class T, class Allocator >
	typename Vector<T, Allocator>::iterator Vector<T, Allocator>::rend() { return (reverse_iterator(_data, _size, -1)); }
	template< class T, class Allocator >
	typename Vector<T, Allocator>::const_iterator Vector<T, Allocator>::rend() const { return (const_reverse_iterator(_data, _size, -1)); }

	template< class T, class Allocator >
	bool Vector<T, Allocator>::empty() const { return (_size <= 0); }

	template< class T, class Allocator >
	typename Vector<T, Allocator>::size_type Vector<T, Allocator>::size() const { return (_size); }

	template< class T, class Allocator >
	typename Vector<T, Allocator>::size_type Vector<T, Allocator>::max_size() const { return (std::numeric_limits<size_type>::max() / sizeof(T)); }

	template< class T, class Allocator >
	void Vector<T, Allocator>::reserve(size_type new_cap)
	{
		if (new_cap > max_size())
			throw std::length_error("");
		realloc(new_cap);
	}

	template< class T, class Allocator >
	typename Vector<T, Allocator>::size_type Vector<T, Allocator>::capacity() const
	{
		return (_capacity);
	}

	// modifiers
	template< class T, class Allocator >
	void Vector<T, Allocator>::clear()
	{
		_alloc.deallocate(_data, _size);
		_size = 0;
		_data = NULL;
		_capacity = 0;
	}
	
	template< class T, class Allocator >
	typename Vector<T, Allocator>::iterator Vector<T, Allocator>::insert(iterator pos, const T &value)
	{
		Vector<T> tmp;
		
		for (iterator itr = begin(); itr != pos; itr++)
			tmp.push_back(*itr);
		tmp.push_back(value);
		for (iterator itr = pos; itr != end(); itr++)
			tmp.push_back(*itr);
		swap(tmp);
		return (iterator(pos, _data));
	}

	template< class T, class Allocator >
	void Vector<T, Allocator>::insert(iterator pos, size_type count, const T &value)
	{
		Vector<T> tmp;

		for (iterator itr = begin(); itr != pos; itr++)
			tmp.push_back(*itr);
		for (int i = 0; i < count; i++)
			pos = insert(pos, value);
		for (iterator itr = pos; itr != end(); itr++)
			tmp.push_back(*itr);
		swap(tmp);
		return (iterator(pos, _data));
	}

	template< class T, class Allocator >
	template< class InputIterator >
	void Vector<T, Allocator>::insert(iterator pos, InputIterator first, InputIterator last)
	{
		insert_helper(pos, first, last, typename ft::is_integral<InputIterator>::type());
	}

	template< class T, class Allocator >
	typename Vector<T, Allocator>::iterator Vector<T, Allocator>::erase(iterator pos)
	{
		iterator ret(pos);
		iterator copy(pos);
		while (pos != end())
		{
			pos++;
			*copy = *pos;
			copy++;
		}
		_size--;
		return (iterator(ret, _data));
	}

	template< class T, class Allocator >
	typename Vector<T, Allocator>::iterator Vector<T, Allocator>::erase(iterator first, iterator last)
	{
		iterator cpy_last(first);
		size_type size_tmp = _size - (last._index - first._index);
		T tmp;

		while (last != end())
		{
			tmp = *last;
			*last = *first;
			*first = tmp;
			last++;
			first++;
		}
		_size = size_tmp;
		return (cpy_last);
	}

	template< class T, class Allocator >
	void Vector<T, Allocator>::push_back(const T &value)
	{
		if (_size >= _capacity)
			reserve(_capacity + _capacity / 2 + _capacity % 2);
		_data[_size] = value;
		_size++;
	}
	
	template< class T, class Allocator >
	void Vector<T, Allocator>::pop_back()
	{
		if (!empty())
			_size--;
	}

	template< class T, class Allocator >
	void Vector<T, Allocator>::resize(size_type count, T value)
	{
		realloc(count);
		for (size_type i = 0; i < count; i++)
			_data[i] = value;
	}

	template< class T, class Allocator >
	void Vector<T, Allocator>::swap(Vector<T, Allocator> &other)
	{
		pointer tmp_data = other._data;
		size_type tmp_size = other._size;
		size_type tmp_capacity = other._capacity;
		allocator_type tmp_alloc = other._alloc;

		other._data = _data;
		other._size = _size;
		other._capacity = _capacity;
		other._alloc = _alloc;

		_data = tmp_data;
		_size = tmp_size;
		_capacity = tmp_capacity;
		_alloc = tmp_alloc;
	}

	template< class T, class Alloc >
	bool operator!=(Vector<T, Alloc> &lhs, Vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (true);
		for (std::size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return (true);
		return (false);
	}

	template< class T, class Alloc >
	bool operator>(Vector<T, Alloc> &lhs, Vector<T, Alloc> &rhs)
	{
		if (lhs.size() > rhs.size())
			return (true);
		else if (lhs.size() < rhs.size())
			return (false);
		for (std::size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] > rhs[i])
				return (true);
			else if (lhs[i] < rhs[i])
				return (false);
		return (false);
	}

	template< class T, class Alloc >
	bool operator>=(Vector<T, Alloc> &lhs, Vector<T, Alloc> &rhs)
	{
		if (lhs.size() > rhs.size())
			return (true);
		else if (lhs.size() < rhs.size())
			return (false);
		for (std::size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] > rhs[i])
				return (true);
			else if (lhs[i] < rhs[i])
				return (false);
		return (true);
	}

	template< class T, class Alloc >
	bool operator<(Vector<T, Alloc> &lhs, Vector<T, Alloc> &rhs)
	{
		if (lhs.size() < rhs.size())
			return (true);
		else if (lhs.size() > rhs.size())
			return (false);
		for (std::size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] < rhs[i])
				return (true);
			else if (lhs[i] > rhs[i])
				return (false);
		return (false);
	}

	template< class T, class Alloc >
	bool operator<=(Vector<T, Alloc> &lhs, Vector<T, Alloc> &rhs)
	{
		if (lhs.size() < rhs.size())
			return (true);
		else if (lhs.size() > rhs.size())
			return (false);
		for (std::size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] < rhs[i])
				return (true);
			else if (lhs[i] > rhs[i])
				return (false);
		return (true);
	}
}

#endif

