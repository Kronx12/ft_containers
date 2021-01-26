#ifndef MAP_HPP
# define MAP_HPP

# include "Iterator.hpp"
# include <string.h>

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

			Mtree() {};
			Mtree(const Key& k, const T& val) : key(k), value(val), parent(NULL), left(NULL), right(NULL) {};
			Mtree(Mtree *parent, const Key& k, const T& val, const char *dir) : key(k), value(val), parent(parent), left(NULL), right(NULL)
			{
				if (strcmp(dir, "left"))
					parent->left = *this;
				else
					parent->right = *this;
			};
	};

	template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key,T> > >
	class Map
	{
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef typename std::pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
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
			typedef size_t size_type;
	
		private:
			pointer _data;
			size_type _size;
			size_type _capacity;
			allocator_type _alloc;
			Mtree<Key, T> *_tree;
			Mtree<Key, T> *_end;
			Mtree<Key, T> *_begin;
			Mtree<Key, T> *_rend;
			Mtree<Key, T> *_rbegin;

		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class Map;
			public:
				key_compare _comp;
				value_compare(key_compare c) : _comp(c) {}
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator()(const value_type& __x, const value_type& __y) const
				{return _comp(__x.first, __y.first);}	
		};

			//---------------------------------------------SPECIAL PLACE---------------------------------------------
			key_compare _cmp;
			value_compare _vcmp;

			//-----------------------------------------END OF SPECIAL PLACE-------------------------------------------
			void realloc(size_type len);

		public:
	// Member functions
		explicit Map( const Compare& comp = key_compare(), const Allocator& alloc = allocator_type() );
//--
		// template <class InputIterator>
		// Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
		// Map( const value_type& il, const key_compare& comp = key_compare());
		// Map( const value_type& il, const key_compare& comp, const allocator_type& a);
		// Map(const Map& x);
		~Map(){};
		Map& operator=( const Map& other );
		Map& operator=( const value_type& il);

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
		T& operator[]( const Key& key );

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
		key_compare key_comp() const;
		value_compare value_comp() const;

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

	/*template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::realloc(size_type len)
	{
		pointer tmp = _alloc.allocate(len);

		for (size_type i = 0; i < (len < _size) ? len : _size; i++)
			tmp[i] = _data[i];
		_alloc.deallocate(_data);
		_data = tmp;
		_capacity = len;
	}*/

	template< class Key, class T, class Compare, class Allocator >
	Map<Key, T, Compare, Allocator>::Map(const Map<Key, T, Compare, Allocator>::key_compare& comp, const Map<Key, T, Compare, Allocator>::allocator_type& alloc)
	: _data(NULL), _size(0), _capacity(0), _alloc(alloc), _tree(NULL), _cmp(comp), _vcmp(_cmp)
	{}

	// template< class Key, class T, class Compare, class Allocator >
	// template< class InputIterator >
	// Map<Key, T, Compare, Allocator>::Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	// {
	// 	;
	// }

	// need shallow
	// template< class Key, class T, class Compare, class Allocator >
	// Map<Key, T, Compare, Allocator>::Map(const Map& x) : _data(x->_data), _size(x->_size), _capacity(x->_capacity), _alloc(x->_alloc), _tree(x->_tree)
	// {
	// 	(Value_compare(x->Value_compare->_comp));
	// }

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::key_compare Map<Key, T, Compare, Allocator>::key_comp() const
	{
		return (key_compare(_cmp));
	}

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::value_compare Map<Key, T, Compare, Allocator>::value_comp() const
	{
		return (value_compare(key_comp()));
	}


	template< class Key, class T, class Compare, class Allocator >
	Map<Key, T, Compare, Allocator> &Map<Key, T, Compare, Allocator>::operator=(Map const & rhs)
	{
        if (this == &rhs) return(*this);
		this->~Map();
        return *new(this) Map(rhs);
	}

	template< class Key, class T, class Compare, class Allocator >
	Map<Key, T, Compare, Allocator> &Map<Key, T, Compare, Allocator>::operator=( const value_type& il)
	{
		if (this->_tree)
		{
			Mtree<Key, T> *temp;

			temp = this->_tree;
			while (temp)
			{
				if (this->Value_compare->_comp()(temp->current->key, il.first) < 0)
				{
					if (!temp->current->left)
						new Mtree< Key, T >(this->_tree, il.first, il.second, "left");
					temp = temp->current->left;
				}
				else if (this->Value_compare->_comp()(temp->current->key, il.first) > 0)
				{
					if (!temp->current->right)
						new Mtree< Key, T >(this->_tree, il.first, il.second, "right");
					temp = temp->current->right;
				}
				else
				{
					temp->value = il.second;
					temp = NULL;
				}
			}
		}
		else
			this->_tree = new Mtree< Key, T >(il.first, il.second);
	}


	template< class Key, class T, class Compare, class Allocator >
	T& Map<Key, T, Compare, Allocator>::operator[]( const Key& key )
	{
		Mtree<Key, T> *temp;

		temp = this->_tree;
		while (temp)
		{
			if (temp->key == key)
				return (temp->value);
			else if (key_comp()(temp->key, key) < 0)
				temp = temp->left;
			else if (key_comp()(temp->key, key) > 0)
				temp = temp->right;
		}
		return (temp->value);
	}
}

#endif