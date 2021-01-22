#ifndef MAP_HPP
# define MAP_HPP

# include "Iterator.hpp"

namespace ft
{
	template < typename Key, typename T >
	class Mtree
	{
		public :
			Key		key;
			T		value;
			Mtree	*parent;
			Mtree	*left;
			Mtree	*right;
			Mtree(const Key& k, const T& val) : key(k), value(val), left(NULL), right(NULL), parent(NULL) {};
			Mtree(Mtree *parent, const Key& k, const T& val) : key(k), value(val), left(NULL), right(NULL), parent(parent) {};
			Mtree() : key(Key()), value(T()), left(NULL), right(NULL), parent(NULL) {};
	};

	template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key,T> > >
	class Map
	{
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef typename std::pair<const key_type, mapped_type> value_type;
			typedef typename Compare::key_compare key_compare;
			//typedef typename value_comp value_compare;
			typedef Allocator allocator_type;
			typedef typename Allocator::reference reference;
			typedef typename Allocator::const_reference const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			typedef MapIterator<key_type, Mtree<Key, T> > iterator;
			typedef ConstMapIterator<key_type, Mtree<Key, T> > const_iterator;
			typedef ReverseIterator<iterator> reverse_iterator;
			typedef ReverseIterator<const_iterator> const_reverse_iterator;
			typedef typename std::ptrdiff_t difference_type;
			typedef typename std::pair<const key_type, mapped_type> size_type;
	
		private:
			pointer _data;
			size_type _size;
			size_type _capacity;
			allocator_type _alloc;
			Mtree<Key, T> *_tree;


			void realloc(size_type len);

		public:
	// Member functions
		explicit Map( const Compare& comp, const Allocator& alloc = allocator_type() );
//--
		template <class InputIterator>
		Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
		Map(const Map& x);
		~Map();
		Map& operator=( const Map& other );

	// Iterators
		// iterator begin();
		// const_iterator begin() const;
		// iterator end();
		// const_iterator end() const;

		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;
		// reverse_iterator rend();
		// const_reverse_iterator rend() const;

	// Capacity
		// bool empty() const;
		// size_type size() const;
		// size_type max_size() const;

	// Element acces
		// T& operator[]( const Key& key );

	// Modifiers
		// std::pair<iterator,bool> insert( const value_type& value );
		// template< class InputIt >
		// void insert( InputIt first, InputIt last );
	
		// void erase( iterator pos );
		// void erase( iterator first, iterator last );
		// size_type erase( const key_type& key );

		// void clear();
		// void swap( map& other );

	// Observers
		// key_compare key_comp() const;
		// std::map::value_compare value_comp() const;

		// Operations
		// iterator find( const Key& key );
		// const_iterator find( const Key& key ) const;
		// size_type count( const Key& key ) const;
		// iterator lower_bound( const Key& key );
		// const_iterator lower_bound( const Key& key ) const;
		// iterator upper_bound( const Key& key );
		// const_iterator upper_bound( const Key& key ) const;
		// std::pair<iterator,iterator> equal_range( const Key& key );
		// std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;	

	// Non-member functions
		// template< class Key, class T, class Compare, class Alloc >
		// bool operator==( const std::map<Key,T,Compare,Alloc>& lhs,
		// const std::map<Key,T,Compare,Alloc>& rhs );
		// template< class Key, class T, class Compare, class Alloc >
		// bool operator!=( const std::map<Key,T,Compare,Alloc>& lhs,
		// const std::map<Key,T,Compare,Alloc>& rhs );
		// template< class Key, class T, class Compare, class Alloc >
		// bool operator<( const std::map<Key,T,Compare,Alloc>& lhs,
		// const std::map<Key,T,Compare,Alloc>& rhs );
		// template< class Key, class T, class Compare, class Alloc >
		// bool operator<=( const std::map<Key,T,Compare,Alloc>& lhs,
		// const std::map<Key,T,Compare,Alloc>& rhs );
		// template< class Key, class T, class Compare, class Alloc >
		// bool operator>( const std::map<Key,T,Compare,Alloc>& lhs,
		// const std::map<Key,T,Compare,Alloc>& rhs );
		// template< class Key, class T, class Compare, class Alloc >
		// bool operator>=( const std::map<Key,T,Compare,Alloc>& lhs,
		// const std::map<Key,T,Compare,Alloc>& rhs );
	};

	//-------------------------- Private --------------------------
	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::realloc(size_type len)
	{
		pointer tmp = _alloc.allocate(len);

		for (size_type i = 0; i < (len < _size) ? len : _size; i++)
			tmp[i] = _data[i];
		_alloc.deallocate(_data);
		_data = tmp;
		_capacity = len;
	}


	//-------------------------- CONSTRUCTOR --------------------------
	template< class Key, class T, class Compare, class Allocator >
	Map<Key, T, Compare, Allocator>::Map(const Compare&, const allocator_type&)
	: _data(NULL), _size(0), _capacity(0), _alloc(allocator_type()), _tree(new Mtree<Key, T>()) {}

	// template< class Key, class T, class Compare, class Allocator >
	// template< class InputIterator >
	// Map<Key, T, Compare, Allocator>::Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	// {
	// 	;
	// }

	// template< class Key, class T, class Compare, class Allocator >
	// Map<Key, T, Compare, Allocator>::Map(const Map& x)
	// {
	// 	;
	// }

	template< class Key, class T, class Compare, class Allocator >
	Map<Key, T, Compare, Allocator> &Map<Key, T, Compare, Allocator>::operator=(Map const & rhs)
	{
        if (this == &rhs) return(*this);
		this->~Map();
        return *new(this) Map(rhs);
	}


	//-------------------------- ... --------------------------
}

#endif