#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <Iterator.hpp>

namespace ft
{
	template< class T >
	class Node
	{

	};

	template< class Allocator >
	class Vector<bool, Allocator>
	{
		public:
			// typedef

			// Iterator invalidation ??

			// constructors

			// element access

			// capacity

			// modifiers

			// TODO
	};

	template< class T, class Allocator = std::allocator<T> >
	class Vector
	{
		private:
			typedef Node<T> _node;
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
			typedef typename VectorIterator< T, _node > iterator;
			typedef typename ConstVectorIterator< T, _node > const_iterator;
			typedef typename ReverseIterator<iterator> reverse_iterator;
			typedef typename ReverseIterator<const_iterator> const_reverse_iterator;

			// Iterator invalidation ??

			// constructors
			Vector();
			explicit Vector(const Allocator &alloc);
			explicit Vector(size_type count, cont T &value = T(), const Allocator &alloc = Allocator());
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

