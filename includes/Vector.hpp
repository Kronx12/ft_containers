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
			typedef VectorIterator< T, T* > iterator;
			typedef ConstVectorIterator< T, T* > const_iterator;
			typedef ReverseIterator<iterator> reverse_iterator;
			typedef ReverseIterator<const_iterator> const_reverse_iterator;

		private:
			pointer _data;
			size_type _size;
			size_type _capacity;
			allocator_type _alloc;

			void realloc(size_type len);

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
			reference at(size_type pos);
			const_reference at(size_type pos) const;
			
			reference operator[](size_type pos);
			const_reference operator[](size_type pos) const;

			reference front();
			const_reference front() const;

			reference back();
			const_reference back() const;

			// iterator
			iterator begin();
			const_iterator begin() const;

			iterator end();
			const_iterator end() const;

			iterator regin();
			const_iterator rbegin() const;
			
			iterator rend();
			const_iterator rend() const;

			// capacity
			bool empty() const;
			size_type size() const;
			size_type max_size() const;
			void reserve(size_type new_cap);
			size_type capacity() const;

			// modifiers
			void clear();

			iterator insert(iterator pos, const T &value);
			void insert(iterator pos, size_type count, const T &value);
			template< class InputIterator >
			void insert(iterator pos, InputIterator first, InputIterator last);

			iterator erase(iterator pos);
			iterator erase(iterator first, iterator last);

			void push_back(const T &value);
			void pop_back();

			void resize(size_type count);
			void resize(size_type count, T value = T());

			void swap(Vector &other);
	};

	// private:
	template< class T, class Allocator >
	void Vector<T, Allocator>::realloc(size_type len)
	{
		pointer tmp = _alloc.allocate(len);

		for (size_type i = 0; i < (len < _size) ? len : _size; i++)
			tmp[i] = _data[i];
		_alloc.deallocate(_data);
		_data = tmp;
		_capacity = len;
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
		for (int i = 0; i < count; i++)
			push_back(value);
	}
	
	template< class T, class Allocator >
	template< class InputIterator >
	Vector<T, Allocator>::Vector(InputIterator first, InputIterator last, const Allocator &alloc) : _alloc(alloc)
	{
		_size = 0;
		_capacity = 0;
		_data = NULL;
		for (;first != last; first++)
			push_back(*first);
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
		clear();
		for (; first != last; first++)
			push_back(*first);
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
			return (_data[pos]); // TODO With invalid index
		throw std::out_of_range("");
	}
	template< class T, class Allocator >
	typename Vector<T, Allocator>::const_reference Vector<T, Allocator>::at(size_type pos) const
	{
		if (pos >= 0 && pos < _size)
			return (_data[pos]); // TODO With invalid index
		throw std::out_of_range("");
	}
		
	template< class T, class Allocator >
	typename Vector<T, Allocator>::reference Vector<T, Allocator>::operator[](size_type pos)
	{
		if (pos >= 0 && pos < _size)
			return (_data[pos]); // TODO With invalid index
	}
	template< class T, class Allocator >
	typename Vector<T, Allocator>::const_reference Vector<T, Allocator>::operator[](size_type pos) const
	{
		if (pos >= 0 && pos < _size)
			return (_data[pos]); // TODO With invalid index
	}

	template< class T, class Allocator >
	typename Vector<T, Allocator>::reference Vector<T, Allocator>::front()
	{

	}
	template< class T, class Allocator >
	typename Vector<T, Allocator>::const_reference Vector<T, Allocator>::front() const
	{

	}

	template< class T, class Allocator >
	typename Vector<T, Allocator>::reference Vector<T, Allocator>::back()
	{

	}
	template< class T, class Allocator >
	typename Vector<T, Allocator>::const_reference Vector<T, Allocator>::back() const
	{

	}

	template< class T, class Allocator >
	void Vector<T, Allocator>::push_back(const T &value)
	{
		if (_size >= _capacity)
			realloc(_capacity + _capacity / 2);
		_data[_size++] = value;
	}

	// TODO non-member functions
	template< class T, class Alloc >
	void swap(Vector<T, Alloc> &lhs, Vector<T, Alloc> &rhs);
	template< class T, class Alloc >
	void operator==(Vector<T, Alloc> &lhs, Vector<T, Alloc> &rhs);
	template< class T, class Alloc >
	void operator!=(Vector<T, Alloc> &lhs, Vector<T, Alloc> &rhs);
	template< class T, class Alloc >
	void operator>(Vector<T, Alloc> &lhs, Vector<T, Alloc> &rhs);
	template< class T, class Alloc >
	void operator>=(Vector<T, Alloc> &lhs, Vector<T, Alloc> &rhs);
	template< class T, class Alloc >
	void operator<=(Vector<T, Alloc> &lhs, Vector<T, Alloc> &rhs);
	template< class T, class Alloc >
	void operator<=(Vector<T, Alloc> &lhs, Vector<T, Alloc> &rhs);
}

#endif

