#ifndef MAP_HPP
# define MAP_HPP

# include <map>
// # include "Iterator.hpp"

namespace ft
{
	// template < typename T >
	// class Link
	// {
	// 	public :
	// 		T		value;
	// 		Link	*next;
	// 		Link	*previous;
	// 		Link(const T& val) : value(val), next(NULL), previous(NULL) {};
	// 		Link(Link *pre, const T& val, Link *_next) :value(val), next(_next), previous(pre) {};
	// 		Link() : value(T()), next(NULL), previous(NULL) {};
	// };


	template < typename Key, typename T, class Compare = std::less<Key> >
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
			typedef Iterator<value_type, link_type> iterator;
			typedef ConstIterator<value_type, link_type> const_iterator;
			typedef ReverseIterator<iterator> reverse_iterator;
			typedef ReverseIterator<const_iterator> const_reverse_iterator;
	
		protected:
		// Member classes
			class value_compare( Compare c );

		public:
		// Member functions
		explicit Map( const Compare& comp, const Allocator& alloc = Allocator() );
		~Map();
		Map<Key, T, Compare>& operator=( const Map<Key, T, Compare>& other );
		allocator_type get_allocator() const;

		// Element acces
		T& operator[]( const Key& key );

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

		// Modifiers
		void clear();
		std::pair<iterator,bool> insert( const value_type& value );
	
		template< class InputIt >
		void insert( InputIt first, InputIt last );

		void erase( iterator pos );
		void erase( iterator first, iterator last );
		size_type erase( const key_type& key );
	
		void swap( map& other );

		// Lookup
		size_type count( const Key& key ) const;
		iterator find( const Key& key );
		const_iterator find( const Key& key ) const;
		std::pair<iterator,iterator> equal_range( const Key& key );
		std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;
		iterator lower_bound( const Key& key );
		const_iterator lower_bound( const Key& key ) const;
		iterator upper_bound( const Key& key );
		const_iterator upper_bound( const Key& key ) const;

		// Observers
		key_compare key_comp() const;
		std::map::value_compare value_comp() const;


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
}

#endif