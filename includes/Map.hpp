#ifndef MAP_HPP
# define MAP_HPP

# include "Iterator.hpp"

# define C_BLACK 0
# define C_RED 1

namespace ft
{
	template < typename Key, typename T >
	class Mtree
	{
		public :
			std::pair< const Key, T >	value;
			Mtree						*parent;
			Mtree						*left;
			Mtree						*right;
			bool						color;

			Mtree() : parent(NULL), left(NULL), right(NULL), color(C_RED) {};
			Mtree(std::pair< const Key, T >	pvalue) : value(pvalue), parent(NULL), left(NULL), right(NULL), color(C_RED) {};
	};

	template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key,T> > >
	class Map
	{
		public:

			// -------------------------------- TYPEDEFS --------------------------------
			typedef Key key_type;
			typedef T mapped_type;
			typedef typename std::pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			typedef Allocator allocator_type;
			typedef typename Allocator::reference reference;
			typedef typename Allocator::const_reference const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			typedef typename allocator_type::template rebind< Mtree<Key, T> >::other node_alloc;
			typedef MapIterator<value_type, Mtree<Key, T> > iterator;
			typedef ConstMapIterator<value_type, Mtree<Key, T> > const_iterator;
			typedef ReverseIterator<iterator> reverse_iterator;
			typedef ReverseIterator<const_iterator> const_reverse_iterator;
			typedef typename std::ptrdiff_t difference_type;
			typedef size_t size_type;

			// --------------------------------  CLASSE  --------------------------------
			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class Map;

				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;

				protected:
					key_compare _comp;
					value_compare(key_compare comp) : _comp(comp) {}

				public:
					bool operator()(const value_type &__x, const value_type &__y) const { return _comp(__x.first, __y.first); }	
			};

		private:
			typedef Mtree<Key, T> node_type;

			node_type *_data;
			size_type _size;
			allocator_type _alloc;
			key_compare _comp;
			node_type *_end;
			node_type *_rend;

			// Recursive inserter
			int p_btree_level_count(Mtree<Key, T> *root);
			void p_checkrb(node_type *end);
			void p_deallocate_tree(node_type *node);
			void p_erase_node(node_type *ptr, const key_type &key);
			void p_btree_apply_by_level(Mtree<Key, T> *root, int maxsize);
			void p_grapher(Mtree<Key, T> *item, int current_level, bool side, int *dirswap);
			void p_call(Mtree<Key, T> *root, int current_level, bool side, int *dirswap, int maxsize);
			void p_zigzig(node_type *P, node_type *C, node_type *G, node_type *PS);
			void p_swap(node_type *P, node_type *C, node_type *G, node_type *PS);
			void p_zigzag(node_type *P, node_type *C, node_type *G);
			iterator p_insert_node(const value_type &value, node_type *ptr);
			const value_type p_ptr_to_ref(const value_type *value);

		public:
			void put_tree(int i = 50);

			// -------------------------------- Member functions --------------------------------
			explicit Map(const Compare &comp = key_compare(), const Allocator &alloc = allocator_type());

			template <class InputIterator>
			Map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
			Map(const Map &x);
			
			~Map();
			
			Map &operator=( const Map &other );

			// -------------------------------- Iterators --------------------------------
			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;

			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;

			// -------------------------------- Capacity --------------------------------
			bool empty() const;
			size_type size() const;
			size_type max_size() const;

			// -------------------------------- Element acces --------------------------------
			T &operator[]( const Key &key );

			// -------------------------------- Modifiers --------------------------------
			std::pair<iterator,bool> insert( const value_type &value );
			iterator insert(iterator position, const value_type& val);

			template< class InputIterator >
			void insert(InputIterator first, InputIterator last);
			void erase(iterator pos);
			void erase(iterator first, iterator last);
			size_type erase(const key_type &key);
			void clear();
			void swap(Map &other);

			// -------------------------------- Observers --------------------------------
			key_compare key_comp() const;
			value_compare value_comp() const;

			// -------------------------------- Operations --------------------------------
			iterator find(const Key &key);
			const_iterator find(const Key &key) const;
			size_type count(const Key &key) const;
			iterator lower_bound(const Key &key);
			const_iterator lower_bound(const Key &key) const;
			iterator upper_bound(const Key &key);
			const_iterator upper_bound(const Key &key) const;
			std::pair<iterator,iterator> equal_range(const Key &key);
			std::pair<const_iterator,const_iterator> equal_range(const Key &key) const;	
	};

	// -------------------------------- Member functions --------------------------------
	template< class Key, class T, class Compare, class Allocator >
	Map<Key, T, Compare, Allocator>::Map(const Compare &comp, const Allocator &alloc)
		: _data(NULL), _size(0), _alloc(alloc), _comp(comp)
	{
		_end = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(_end, node_type());

		_rend = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(_rend, node_type());
		 
		_end->color = C_BLACK;
		_rend->color = C_BLACK;
	}

	template< class Key, class T, class Compare, class Allocator >
	template <class InputIterator>
	Map<Key, T, Compare, Allocator>::Map(InputIterator first, InputIterator last, const key_compare &comp, const allocator_type &alloc)
	: _data(NULL), _size(0), _alloc(alloc), _comp(comp)
	{
		_end = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(_end, node_type());

		_rend = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(_rend, node_type());

		for (; first != last; first++)
		{
			std::pair<Key, T> tmp(first->first, first->second);
			insert(tmp);
		}
	}

	template< class Key, class T, class Compare, class Allocator >
	Map<Key, T, Compare, Allocator>::Map(const Map &x) : _data(NULL), _size(0), _alloc(x._alloc),_comp(x._comp)
	{
		_end = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(_end, node_type());

		_rend = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(_rend, node_type());

		insert(x.begin(), x.end());
	}

	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::p_deallocate_tree(node_type *node)
	{
		if (node == NULL || node == _end || node == _rend)
			return;
		p_deallocate_tree(node->left);
		p_deallocate_tree(node->right);
		node_alloc(_alloc).destroy(node);
		node_alloc(_alloc).deallocate(node, 1);
	}

	template< class Key, class T, class Compare, class Allocator >
	Map<Key, T, Compare, Allocator>::~Map()
	{
		p_deallocate_tree(_data);
		node_alloc(_alloc).destroy(_end);
		node_alloc(_alloc).deallocate(_end, 1);
		node_alloc(_alloc).destroy(_rend);
		node_alloc(_alloc).deallocate(_rend, 1);
	}
			
	template< class Key, class T, class Compare, class Allocator >
	Map<Key, T, Compare, Allocator> &Map<Key, T, Compare, Allocator>::operator=(const Map &other)
	{
		if (this == &other) return(*this);
		this->~Map();
		return *new(this) Map(other);
	}

	// -------------------------------- Iterators --------------------------------
	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::iterator Map<Key, T, Compare, Allocator>::begin()
	{
		return (size() == 0 ? iterator(_end) : iterator(_rend->parent));
	}
	
	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::const_iterator Map<Key, T, Compare, Allocator>::begin() const
	{
		return (size() == 0 ? iterator(_end) : iterator(_rend->parent));
	}

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::iterator Map<Key, T, Compare, Allocator>::end()
	{
		return (iterator(_end));
	}

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::const_iterator Map<Key, T, Compare, Allocator>::end() const
	{
		return (iterator(_end));
	}

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::reverse_iterator Map<Key, T, Compare, Allocator>::rbegin()
	{
		return (size() == 0 ? reverse_iterator(_rend) : reverse_iterator(_end->parent));
	}

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::const_reverse_iterator Map<Key, T, Compare, Allocator>::rbegin() const
	{
		return (size() == 0 ? reverse_iterator(_rend) : reverse_iterator(_end->parent));
	}

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::reverse_iterator Map<Key, T, Compare, Allocator>::rend()
	{
		return (reverse_iterator(_rend));
	}

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::const_reverse_iterator Map<Key, T, Compare, Allocator>::rend() const
	{
		return (reverse_iterator(_rend));
	}

	// -------------------------------- Capacity --------------------------------
	template< class Key, class T, class Compare, class Allocator >
	bool Map<Key, T, Compare, Allocator>::empty() const { return (_size == 0); }

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::size_type Map<Key, T, Compare, Allocator>::size() const { return (_size); }

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::size_type Map<Key, T, Compare, Allocator>::max_size() const
	{
		return (std::numeric_limits<size_type>::max() / sizeof(Mtree<Key, T>));
	}

	// -------------------------------- Element acces --------------------------------
	template< class Key, class T, class Compare, class Allocator >
	T &Map<Key, T, Compare, Allocator>::operator[]( const Key &key )
	{
		Mtree<Key, T> *temp;

		temp = _data;
		while (temp && temp != _end && temp != _rend)
		{
			if (temp->value.first == key)
				return (temp->value.second);
			else if (key_comp()(temp->value.first, key))
				temp = temp->right;
			else
				temp = temp->left;
		}
		insert(std::pair<Key, T>(key, T()));
		return (operator[](key));
	}

	// -------------------------------- Modifiers --------------------------------

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::iterator Map<Key, T, Compare, Allocator>::p_insert_node(const value_type &value, node_type *ptr)
	{
		value_compare tmp_cmp = value_comp();
		if (_data == NULL)
		{
			_data = node_alloc(_alloc).allocate(1);
			node_alloc(_alloc).construct(_data, node_type(value_type(value.first, value.second)));
			_data->color = C_BLACK;
			_data->parent = NULL;
			_data->left = this->_rend;
			_data->right = this->_end;
			this->_rend->parent = _data;
			this->_end->parent = _data;
			_size++;
		}
		else if (value.first == ptr->value.first) {} // Skip if existing key
		else if (tmp_cmp(value, ptr->value))
		{
			if (ptr->left != NULL && ptr->left != this->_rend)
				p_insert_node(value, ptr->left);
			else
			{
				if (ptr->left == this->_rend)
				{
					ptr->left = node_alloc(_alloc).allocate(1);
					node_alloc(_alloc).construct(ptr->left, node_type(value_type(value.first, value.second)));
					ptr->left->parent = ptr;
					ptr->left->left = this->_rend;
					this->_rend->parent = ptr->left;
				}
				else
				{
					ptr->left = node_alloc(_alloc).allocate(1);
					node_alloc(_alloc).construct(ptr->left, node_type(value_type(value.first, value.second)));
					ptr->left->parent = ptr;
				}
				_size++;
				p_checkrb(ptr->left);
				return (iterator(ptr->left));
			}
		}
		else
		{
			if (ptr->right != NULL && ptr->right != this->_end)
				p_insert_node(value, ptr->right);
			else
			{
				if (ptr->right == this->_end)
				{
					ptr->right = node_alloc(_alloc).allocate(1);
					node_alloc(_alloc).construct(ptr->right, node_type(value_type(value.first, value.second)));
					ptr->right->parent = ptr;
					ptr->right->right = this->_end;
					this->_end->parent = ptr->right;
				}
				else
				{
					ptr->right = node_alloc(_alloc).allocate(1);
					node_alloc(_alloc).construct(ptr->right, node_type(value_type(value.first, value.second)));
					ptr->right->parent = ptr;
				}
				_size++;
				p_checkrb(ptr->right);
				return (iterator(ptr->right));
			}
		}
		return (iterator(_data));
	}
	
	template< class Key, class T, class Compare, class Allocator >
	std::pair<typename Map<Key, T, Compare, Allocator>::iterator, bool> Map<Key, T, Compare, Allocator>::insert(const value_type &value)
	{
		return (std::pair<iterator, bool>(p_insert_node(value, _data), true));
	}

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::iterator Map<Key, T, Compare, Allocator>::insert(iterator position, const value_type &value)
	{
		static_cast<void>(position);
		std::pair<typename Map<Key, T, Compare, Allocator>::iterator, bool> p = insert(value);
		return (p.first);
	}

	template< class Key, class T, class Compare, class Allocator >
	template< class InputIterator >
	void Map<Key, T, Compare, Allocator>::insert(InputIterator first, InputIterator last)
	{
		for (; first != last; first++)
		{
			std::pair<Key, T> tmp(first->first, first->second);
			insert(tmp);
		}
	}

	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::p_erase_node(node_type *ptr, const key_type &key)
	{
		node_type *tmp = NULL;
		if (ptr == NULL || ptr == _end || ptr == _rend)
			return ;
		if (ptr->value.first == key)
		{
			node_type *tmp_parent = ptr->parent;
			bool right;
			node_type *tmp_left = ptr->left;
			node_type *tmp_right = ptr->right;
			tmp = tmp_right;
			bool stop = 0;
			if (ptr->parent)
					right = (ptr == ptr->parent->right);
			if (ptr->left == NULL && ptr->right == NULL)
			{
				if (ptr->parent && ptr->parent->left == ptr)
					ptr->parent->left = NULL;
				else if (ptr->parent)
					ptr->parent->right = NULL;
				stop = 1;
			}
			if (ptr->left == _rend && ptr->right == _end)
			{
				_rend->parent = NULL;
				_end->parent = NULL;
				_data = NULL;
				stop = 1;
			}
			node_alloc(_alloc).destroy(ptr);
			node_alloc(_alloc).deallocate(ptr, 1);
			_size--;
			if (!stop)
			{
				if (tmp_right && tmp_right != _end)
				{
					tmp = tmp_right;
					while (tmp->left && tmp->left != _rend)
						tmp = tmp->left;
					if (tmp != tmp_right)
					{
						if (tmp->parent)
						{
							tmp->parent->left = tmp->right;
							if (tmp->right)
									tmp->right->parent = tmp->parent;
						}
						tmp->right = tmp_right;
					}
					tmp->left = tmp_left;
					if (tmp_parent)
					{
						if (right)
							tmp_parent->right = tmp;
						else
							tmp_parent->left = tmp;
					}
					else
						_data = tmp;
					tmp->parent = tmp_parent;
				}
				else if (tmp_left && tmp_left != _rend)
				{
					tmp = tmp_left;
					tmp->parent = tmp_parent;
					if (!tmp_parent)
						_data = tmp;
					else
					{
						if (right)
							tmp_parent->right = tmp;
						else
							tmp_parent->left = tmp;
					}
					if (tmp_right == _end)
					{
						node_type *tmp2 = tmp;
						while (tmp2->right)
							tmp2 = tmp2->right;
						tmp2->right = _end;
						_end->parent = tmp2;
					}
				}
				else
				{
					if (tmp_right)
					{
						tmp = tmp_parent;
						tmp->right = _end;
					}
					else
					{
						tmp = tmp_parent;
						tmp->left = _rend;
					}
				}
				if (tmp_left && !(tmp == tmp_left))
					tmp_left->parent = tmp;
				if (tmp_right && !(tmp == tmp_right))
					tmp_right->parent = tmp;
			}
		}
		else if (key_comp()(key, ptr->value.first))
			p_erase_node(ptr->left, key);
		else
			p_erase_node(ptr->right, key);
	}
	
	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::erase(iterator pos)
	{
		erase(pos->first);
	}
	
	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::erase(iterator first, iterator last)
	{
		iterator temp;
		while (first != last)
		{
			temp = first;
			temp++;
			erase(first);
			first = temp;
		}
	}
	
	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::size_type Map<Key, T, Compare, Allocator>::erase(const key_type &key)
	{
		size_type tmp_size = _size;
		p_erase_node(_data, key);
		return (tmp_size - _size);
	}
	
	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::clear()
	{
		erase(begin(), end());
	}
	
	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::swap(Map &other)
	{
		Map temp(other);
		other = *this;
		*this = temp;
	}

	// -------------------------------- Observers --------------------------------
	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::key_compare Map<Key, T, Compare, Allocator>::key_comp() const
	{
		return (key_compare(_comp));
	}

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::value_compare Map<Key, T, Compare, Allocator>::value_comp() const
	{
		return (value_compare(key_comp()));
	}

	// -------------------------------- Operations --------------------------------
	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::iterator Map<Key, T, Compare, Allocator>::find(const Key &key)
	{
		Mtree<Key, T> *temp;

		temp = _data;
		while (temp != NULL && temp != _end && temp != _rend)
		{
			if (temp->value.first == key)
			{
				iterator itr = temp;
				return (itr);
			}
			else if (key_comp()(temp->value.first, key))
				temp = temp->right;
			else
				temp = temp->left;
		}
		return (end());
	}

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::const_iterator Map<Key, T, Compare, Allocator>::find(const Key &key) const
	{
		for (iterator itr = begin(); itr != end(); itr++)
			if (itr->first == key)
				return (itr);
		return (end());
	}

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::size_type Map<Key, T, Compare, Allocator>::count(const Key &key) const
	{
		return (find(key) != end());
	}

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::iterator Map<Key, T, Compare, Allocator>::lower_bound(const Key &key)
	{
		for (iterator itr = begin(); itr != end(); itr++)
		{
			if (key_comp()(key, itr->first))
			{
				if (find(key) != end())
					itr--;
				return (itr);
			}
		}
		return (end());
	}

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::const_iterator Map<Key, T, Compare, Allocator>::lower_bound(const Key &key) const
	{
		for (iterator itr = begin(); itr != end(); itr++)
		{
			if (key_comp()(key, itr->first))
			{
				if (find(key) != end())
					itr--;
				return (itr);
			}
		}
		return (end());
	}

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::iterator Map<Key, T, Compare, Allocator>::upper_bound(const Key &key)
	{
		for (iterator itr = begin(); itr != end(); itr++)
			if (key_comp()(key, itr->first))
				return (itr);
		return (end());
	}

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::const_iterator Map<Key, T, Compare, Allocator>::upper_bound(const Key &key) const
	{
		for (iterator itr = begin(); itr != end(); itr++)
			if (key_comp()(key, itr->first))
				return (itr);
		return (end());
	}

	template< class Key, class T, class Compare, class Allocator >
	std::pair<	typename Map<Key, T, Compare, Allocator>::iterator,
				typename Map<Key, T, Compare, Allocator>::iterator> Map<Key, T, Compare, Allocator>::equal_range(const Key &key)
	{
		return (std::pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
	}

	template< class Key, class T, class Compare, class Allocator >
	std::pair<	typename Map<Key, T, Compare, Allocator>::const_iterator,
				typename Map<Key, T, Compare, Allocator>::const_iterator> Map<Key, T, Compare, Allocator>::equal_range(const Key &key) const
	{
		return (std::pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key)));
	}

	// -------------------------------- Non-member functions --------------------------------
	template< class Key, class T, class Compare, class Allocator >
	bool operator==(Map<Key, T, Compare, Allocator> &lhs, Map<Key, T, Compare, Allocator> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);

		typename ft::Map<Key, T, Compare, Allocator>::iterator itr_l = lhs.begin();
		typename ft::Map<Key, T, Compare, Allocator>::iterator itr_r = rhs.begin();
		while (itr_l != lhs.end() && itr_r != rhs.end())
		{
			if (itr_l->first != itr_r->first)
				return (false);
			itr_l++;
			itr_r++;
		}
		return (true);
	}

	template< class Key, class T, class Compare, class Allocator >
	bool operator!=(Map<Key, T, Compare, Allocator> &lhs, Map<Key, T, Compare, Allocator> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (true);

		typename ft::Map<Key, T, Compare, Allocator>::iterator itr_l = lhs.begin();
		typename ft::Map<Key, T, Compare, Allocator>::iterator itr_r = rhs.begin();
		while (itr_l != lhs.end() && itr_r != rhs.end())
		{
			if (itr_l->first != itr_r->first)
				return (true);
			itr_l++;
			itr_r++;
		}
		return (false);
	}

	template< class Key, class T, class Compare, class Allocator >
	bool operator<(Map<Key, T, Compare, Allocator> &lhs, Map<Key, T, Compare, Allocator> &rhs)
	{
		typename ft::Map<Key, T, Compare, Allocator>::iterator itr_l = lhs.begin();
		typename ft::Map<Key, T, Compare, Allocator>::iterator itr_r = rhs.begin();
		while (itr_l != lhs.end() && itr_r != rhs.end())
		{
			if (itr_l->first < itr_r->first)
				return (true);
			else if (itr_l->first > itr_r->first)
				return (false);
			itr_l++;
			itr_r++;
		}
		if (lhs.size() < rhs.size())
			return (true);
		return (false);
	}


	template< class Key, class T, class Compare, class Allocator >
	bool operator<=(Map<Key, T, Compare, Allocator> &lhs, Map<Key, T, Compare, Allocator> &rhs)
	{
		typename ft::Map<Key, T, Compare, Allocator>::iterator itr_l = lhs.begin();
		typename ft::Map<Key, T, Compare, Allocator>::iterator itr_r = rhs.begin();
		if (lhs.empty() && rhs.empty())
			return (true);
		while (itr_l != lhs.end() && itr_r != rhs.end())
		{
			if (itr_l->first < itr_r->first)
				return (true);
			else if (itr_l->first > itr_r->first)
				return (false);
			itr_l++;
			itr_r++;
		}
		return (true);
	}

	template< class Key, class T, class Compare, class Allocator >
	bool operator>(Map<Key, T, Compare, Allocator> &lhs, Map<Key, T, Compare, Allocator> &rhs)
	{
		typename ft::Map<Key, T, Compare, Allocator>::iterator itr_l = lhs.begin();
		typename ft::Map<Key, T, Compare, Allocator>::iterator itr_r = rhs.begin();
		while (itr_l != lhs.end() && itr_r != rhs.end())
		{
			if (itr_l->first > itr_r->first)
				return (true);
			else if (itr_l->first < itr_r->first)
				return (false);
			itr_l++;
			itr_r++;
		}
		return (false);
	}

	template< class Key, class T, class Compare, class Allocator >
	bool operator>=(Map<Key, T, Compare, Allocator> &lhs, Map<Key, T, Compare, Allocator> &rhs)
	{
		typename ft::Map<Key, T, Compare, Allocator>::iterator itr_l = lhs.begin();
		typename ft::Map<Key, T, Compare, Allocator>::iterator itr_r = rhs.begin();
		if (lhs.empty() && rhs.empty())
			return (true);
		while (itr_l != lhs.end() && itr_r != rhs.end())
		{
			if (itr_l->first > itr_r->first)
				return (true);
			if (itr_l->first < itr_r->first)
				return (false);
			itr_l++;
			itr_r++;
		}
		return (true);
	}

	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::p_grapher(Mtree<Key, T> *item, int current_level, bool side, int *dirswap)
	{
		std::string color = item->color ? "\033[1;31m" : "\033[1;97m";
		std::string pipe = "\033[2;37m";
		std::string reset = "\033[0m";
		std::stringstream ss;

		for (int i = 0; i < current_level - 1; i++)
		{
			if (dirswap[i])
				ss << "  " << pipe << "┃" << reset << "  ";
			else
				ss << "     ";
		}
		
		if (!current_level)
			ss << " " << color << "◖";
		else if (!side)
			ss << "  " << pipe << "┗━━━" << reset << color << "◖";
		else
			ss << "  " << pipe << "┏━━━" << reset << color << "◖";

		if (item == _end)
			ss << "(end)◗";
		else if (item == _rend)
			ss << "(rend)◗";
		else if (begin() == iterator(item))
			ss << item->value.first << ":" << item->value.second << "(begin)◗";
		else if (rbegin() == iterator(item))
			ss << item->value.first << ":" << item->value.second << "(rbegin)◗";
		else
			ss << item->value.first << ":" << item->value.second << "◗";
		ss << reset << std::endl;
		std::cout << ss.str();
	}

	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::put_tree(int i)
	{
		#if SHOW==1
		if (empty())
			std::cout << "Put tree : (empty map)" << std::endl;
		else
			p_btree_apply_by_level(_data, i);
		#else
			static_cast<void>(i);
		#endif
	}

	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::p_call(Mtree<Key, T> *root, int current_level, bool side, int *dirswap, int maxsize)
	{
		if (current_level < maxsize)
		{
			if (root->right)
			{
				if (side != 1 && current_level != 0)
					dirswap[current_level - 1] = 1;
				else if (current_level != 0)
					dirswap[current_level - 1] = 0;
				p_call(root->right, current_level + 1, 1, dirswap, maxsize);
			}
			if (root != NULL)
				p_grapher(root, current_level, side, dirswap);
			if (root->left)
			{
				if (side != 0 && current_level != 0)
					dirswap[current_level - 1] = 1;
				else if (current_level != 0)
					dirswap[current_level - 1] = 0;
				p_call(root->left, current_level + 1, 0, dirswap, maxsize);
			}
		}
	}

	template< class Key, class T, class Compare, class Allocator >
	int	Map<Key, T, Compare, Allocator>::p_btree_level_count(Mtree<Key, T> *root)
	{
		int	count;

		count = 0;
		if (!root)
			return (0);
		if (root->left)
			count = std::max(count, p_btree_level_count(root->left));
		if (root->right)
			count = std::max(count, p_btree_level_count(root->right));
		return (count + 1);
	}

	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::p_btree_apply_by_level(Mtree<Key, T> *root, int maxsize)
	{
		int i[maxsize];
		for (int j = 0; j < maxsize - 1; j++)
		{
			i[j] = 0;
		}
		if (!root)
			return ;
		p_call(root, 0, 0, i, maxsize);
	}

	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::p_zigzag(node_type *P, node_type *C, node_type *G)
	{
		//first swap;
		C->parent = G;
		P->parent = C;
		if (C == P->left)
		{
			G->right = C;
			P->left = C->right;
			if (C->right)
				C->right->parent = P;
			C->right = P;
		}
		else
		{
			G->left = C;
			P->right = C->left;
			if (C->left)
				C->left->parent = P;
			C->left = P;
		}

		//second swap
		C->parent = G->parent;
		if (C == G->right)
		{
			if (G->parent)
			{
				if (G == G->parent->left)
					G->parent->left = C;
				else
					G->parent->right = C;
			}
			else
				_data = C;
			G->right = C->left;
			if (C->left)
				C->left->parent = G;
			C->left = G;
		}
		else
		{
			if (G->parent)
			{
				if (G == G->parent->left)
					G->parent->left = C;
				else
					G->parent->right = C;
			}
			else
				_data = C;
			G->left = C->right;
			if (C->right)
				C->right->parent = G;
			C->right = G;
		}
		G->parent = C;
		//color swap + base color swap
		if (C->color != G->color)
		{
			C->color = G->color;
			G->color = !G->color;
		}
		_data->color = C_BLACK;
	}
	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::p_zigzig(node_type *P, node_type *C, node_type *G, node_type *PS)
	{
		P->parent = G->parent;
		if (P == G->right)
		{
			if (G->parent)
			{
				if (G == G->parent->left)
					G->parent->left = P;
				else
					G->parent->right = P;
			}
			else
				_data = P;
			G->right = P->left;
			if (P->left)
				P->left->parent = G;
			P->left = G;
		}
		else
		{
			if (G->parent)
			{
				if (G == G->parent->left)
					G->parent->left = P;
				else
					G->parent->right = P;
			}
			else
				_data = P;
			G->left = P->right;
			if (P->right)
				P->right->parent = G;
			P->right = G;
		}
		G->parent = P;
		if (P->color != G->color)
		{
			P->color = G->color;
			G->color = !G->color;
		}
		_data->color = C_BLACK;
		(void)C;
		(void)PS;
	}

	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::p_swap(node_type *P, node_type *C, node_type *G, node_type *PS)
	{
		P->color = C_BLACK; 
		G->color = C_RED;
		PS->color = C_BLACK;
		_data->color = C_BLACK;
		(void)C;
	}

	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::p_checkrb(node_type *end)
	{
		node_type *P;
		node_type *C;
		node_type *G;
		node_type *PS;

		while (1 && end)
		{
			G = NULL;
			PS = NULL;
			P = end->parent;
			if (P)
				G = P->parent;
			C = end;
			if (G && P == G->right)
				PS = G->left;
			else if (G)
				PS = G->right;
			if (G && P->color == C_RED && C->color == C_RED)
			{
				if (!PS || PS->color == C_BLACK)
				{
					if (P == G->right)
					{
						if (C == P->left)
							p_zigzag(P, C, G);
						else
							p_zigzig(P, C, G, PS);
					}
					else
					{
						if (C == P->right)
							p_zigzag(P, C, G);
						else
							p_zigzig(P, C, G, PS);
					}
				}
				else
				{
					p_swap(P, C, G, PS);
				}
			}
			if (!end->parent || !end->parent->parent)
				break;
			end = end->parent;
		}
	}
};

#endif
