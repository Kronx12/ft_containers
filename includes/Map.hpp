#ifndef MAP_HPP
#define MAP_HPP

#include <map>

namespace ft
{
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
		// member classes
			class value_compare( Compare c );

		public:
		// member functions
		explicit map( const Compare& comp, const Allocator& alloc = Allocator() );

		// element acces

	
	};
}

#endif