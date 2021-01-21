#ifndef MAP_HPP
# define MAP_HPP

# include <map>
# include "MapIterator.hpp"

namespace ft
{
	template < typename Key, typename T >
	class Map_list
	{
		public :
			Key			key;
			T			value;
			Map_list	*parent;
			Map_list	*left;
			Map_list	*right;
			Map_list(const Key& k, const T& val) : key(k), value(val), left(NULL), right(NULL), parent(NULL) {};
			Map_list(Map_list *parent, const Key& k, const T& val) : key(k), value(val), left(NULL), right(NULL), parent(parent) {};
			Map_list() : key(Key()), value(T()), left(NULL), right(NULL), parent(NULL) {};
	};


	template < class Key, class T, class Compare = std::less<Key> >
	class Map
	{
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef typename std::size_t value_type;
			typedef typename std::pair<const Key, T> size_type;
			typedef typename std::ptrdiff_t difference_type;
			typedef typename Compare::key_compare key_compare;
			typedef typename std::allocator<value_type> allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef Iterator<value_type, Map_list> iterator;
			typedef ConstIterator<value_type, Map_list> const_iterator;
			typedef ReverseIterator<iterator> reverse_iterator;
			typedef ReverseIterator<const_iterator> const_reverse_iterator;
	
		// Member functions
		explicit Map( const Compare& comp, const Allocator& alloc = allocator_type() );
		~Map();
		Map<Key, T, Compare>& operator=( const Map<Key, T, Compare>& other );
		allocator_type get_allocator() const;

		// Iterators
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;

		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		// Capacity
		bool empty() const;
		size_type size() const;
		size_type max_size() const;

		// Element acces
		T& operator[]( const Key& key );

		// Modifiers
		std::pair<iterator,bool> insert( const value_type& value );
		template< class InputIt >
		void insert( InputIt first, InputIt last );
	
		void erase( iterator pos );
		void erase( iterator first, iterator last );
		size_type erase( const key_type& key );

		void clear();
		void swap( map& other );

		// Observers
		key_compare key_comp() const;
		std::map::value_compare value_comp() const;

		// Operations
		iterator find( const Key& key );
		const_iterator find( const Key& key ) const;
		size_type count( const Key& key ) const;
		iterator lower_bound( const Key& key );
		const_iterator lower_bound( const Key& key ) const;
		iterator upper_bound( const Key& key );
		const_iterator upper_bound( const Key& key ) const;
		std::pair<iterator,iterator> equal_range( const Key& key );
		std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;	

		// Allocator
		allocator_type get_allocator() const;

		// Non-member functions
		template< class Key, class T, class Compare, class Alloc >
		bool operator==( const std::map<Key,T,Compare,Alloc>& lhs,
		const std::map<Key,T,Compare,Alloc>& rhs );
		template< class Key, class T, class Compare, class Alloc >
		bool operator!=( const std::map<Key,T,Compare,Alloc>& lhs,
		const std::map<Key,T,Compare,Alloc>& rhs );
		template< class Key, class T, class Compare, class Alloc >
		bool operator<( const std::map<Key,T,Compare,Alloc>& lhs,
		const std::map<Key,T,Compare,Alloc>& rhs );
		template< class Key, class T, class Compare, class Alloc >
		bool operator<=( const std::map<Key,T,Compare,Alloc>& lhs,
		const std::map<Key,T,Compare,Alloc>& rhs );
		template< class Key, class T, class Compare, class Alloc >
		bool operator>( const std::map<Key,T,Compare,Alloc>& lhs,
		const std::map<Key,T,Compare,Alloc>& rhs );
		template< class Key, class T, class Compare, class Alloc >
		bool operator>=( const std::map<Key,T,Compare,Alloc>& lhs,
		const std::map<Key,T,Compare,Alloc>& rhs );
	};
	
	//-------------------------- CONSTRUCTOR --------------------------
	template< class Key, class T, class Compare >
	Map<Key, T, Compare>::Map(const Compare&, const allocator_type& alloc)
	{
		;
	}


	//-------------------------- ... --------------------------
}

#endif