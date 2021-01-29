#ifndef MAP_HPP
# define MAP_HPP

# include "Iterator.hpp"

namespace ft
{
	template < typename Key, typename T >
	class Mtree
	{
		public :
			std::pair< const Key, T >	*value;
			Mtree						*parent;
			Mtree						*left;
			Mtree						*right;
			bool						color;

			Mtree() : value(NULL), parent(NULL), left(NULL), right(NULL) {};
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
			void p_erase_node(node_type *ptr, const key_type &key);
			iterator p_insert_node(const value_type &value, node_type *ptr);
			// Recursive delete
			void p_deallocate_tree(node_type *node);

		public:

			// TODO Remove
			void debug_leaf(node_type *ptr);
			void debug_tree();
			void grapher(Mtree<Key, T> *item, int current_level, bool side, int *dirswap);
			void put_tree(int i = 10);
			void call(Mtree<Key, T> *root, int current_level, bool side, int *dirswap, int maxsize);
			int btree_level_count(Mtree<Key, T> *root);
			void btree_apply_by_level(Mtree<Key, T> *root, int maxsize);

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

			// -------------------------------- Non-member functions --------------------------------
			bool operator==(const Map &rhs);
			bool operator!=(const Map &rhs);
			bool operator<(const Map &rhs);
			bool operator<=(const Map &rhs);
			bool operator>(const Map &rhs);
			bool operator>=(const Map &rhs);
	};

	// -------------------------------- Member functions --------------------------------
	template< class Key, class T, class Compare, class Allocator >
	Map<Key, T, Compare, Allocator>::Map(const Compare &comp, const Allocator &alloc)
	: _data(NULL), _size(0), _alloc(alloc), _comp(comp), _end(new node_type()), _rend(new node_type()) {}

	template< class Key, class T, class Compare, class Allocator >
	template <class InputIterator>
	Map<Key, T, Compare, Allocator>::Map(InputIterator first, InputIterator last, const key_compare &comp, const allocator_type &alloc)
	: _data(NULL), _size(0), _alloc(alloc), _comp(comp), _end(new node_type()), _rend(new node_type())
	{
		for (; first != last; first++)
			insert(*(*first));
	}

	template< class Key, class T, class Compare, class Allocator >
	Map<Key, T, Compare, Allocator>::Map(const Map &x) : _data(NULL), _size(0), _alloc(x._alloc),_comp(x._comp),  _end(new node_type()), _rend(new node_type())
	{
		insert(x.begin(), x.end());
	}

	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::p_deallocate_tree(node_type *node)
	{
		if (node == NULL || node == _end || node == _rend)
			return;
		p_deallocate_tree(node->left);
		p_deallocate_tree(node->right);
		_alloc.destroy(node->value);
		_alloc.deallocate(node->value, 1);
		delete node;
	}

	template< class Key, class T, class Compare, class Allocator >
	Map<Key, T, Compare, Allocator>::~Map()
	{
		p_deallocate_tree(_data);
		delete _rend;
		delete _end;
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
		return (size() == 0 ? iterator(_rend) : iterator(_end->parent));
	}

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::const_reverse_iterator Map<Key, T, Compare, Allocator>::rbegin() const
	{
		return (size() == 0 ? iterator(_rend) : iterator(_end->parent));
	}

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::reverse_iterator Map<Key, T, Compare, Allocator>::rend()
	{
		return (iterator(_rend));
	}

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::const_reverse_iterator Map<Key, T, Compare, Allocator>::rend() const
	{
		return (iterator(_rend));
	}

	// -------------------------------- Capacity --------------------------------
	template< class Key, class T, class Compare, class Allocator >
	bool Map<Key, T, Compare, Allocator>::empty() const { return (_size == 0); }

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::size_type Map<Key, T, Compare, Allocator>::size() const { return (_size); }

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::size_type Map<Key, T, Compare, Allocator>::max_size() const
	{
		return (std::numeric_limits<size_type>::max() / (sizeof(Mtree<Key, T>) - sizeof(void*) + sizeof(std::pair<Key, T>)));
	}

	// -------------------------------- Element acces --------------------------------
	template< class Key, class T, class Compare, class Allocator >
	T &Map<Key, T, Compare, Allocator>::operator[]( const Key &key )
	{
		Mtree<Key, T> *temp;

		temp = _data;
		while (temp && temp != _end && temp != _rend)
		{
			if (temp->value->first == key)
				return (temp->value->second);
			else if (key_comp()(temp->value->first, key))
				temp = temp->right;
			else
				temp = temp->left;
		}
		insert(std::pair<Key, T>(key, T()));
		return (operator[](key));
	}

	// -------------------------------- Modifiers --------------------------------
	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::debug_leaf(node_type *ptr)
	{
		if (ptr->left != NULL&& ptr->left != _rend)
			debug_leaf(ptr->left);
		std::cout << "{ " << ptr->value->first << " : " << ptr->value->second << " }\n";
		if (ptr->right != NULL && ptr->right != _end)
			debug_leaf(ptr->right);
	}

	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::debug_tree()
	{
		debug_leaf(_data);
	}

	template< class Key, class T, class Compare, class Allocator >
	typename Map<Key, T, Compare, Allocator>::iterator Map<Key, T, Compare, Allocator>::p_insert_node(const value_type &value, node_type *ptr)
	{
		value_compare tmp_cmp = value_comp();
		if (_data == NULL)
		{
			_data = new node_type();
			_data->value = _alloc.allocate(1);
			_data->parent = NULL;
			_alloc.construct(_data->value, std::pair< Key, T >(value.first, value.second));
			_data->left = this->_rend;
			_data->right = this->_end;
			this->_rend->parent = _data;
			this->_end->parent = _data;
			_size++;
		}
		else if (value.first == ptr->value->first) {} // Skip if existing key
		else if (tmp_cmp(value, *ptr->value))
		{
			if (ptr->left != NULL && ptr->left != this->_rend)
				p_insert_node(value, ptr->left);
			else
			{
				if (ptr->left == this->_rend)
				{
					ptr->left = new node_type();
					ptr->left->value = _alloc.allocate(1);
					ptr->left->parent = ptr;
					_alloc.construct(ptr->left->value, std::pair< Key, T >(value.first, value.second));
					ptr->left->left = this->_rend;
					this->_rend->parent = ptr->left;
				}
				else
				{
					ptr->left = new node_type();
					ptr->left->value = _alloc.allocate(1);
					ptr->left->parent = ptr;
					_alloc.construct(ptr->left->value, std::pair< Key, T >(value.first, value.second));
				}
				_size++;
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
					ptr->right = new node_type();
					ptr->right->value = _alloc.allocate(1);
					ptr->right->parent = ptr;
					_alloc.construct(ptr->right->value, std::pair< Key, T >(value.first, value.second));
					ptr->right->right = this->_end;
					this->_end->parent = ptr->right;
				}
				else
				{
					ptr->right = new node_type();
					ptr->right->value = _alloc.allocate(1);
					ptr->right->parent = ptr;
					_alloc.construct(ptr->right->value, std::pair< Key, T >(value.first, value.second));
				}
				_size++;
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
	template< class InputIterator >
	void Map<Key, T, Compare, Allocator>::insert(InputIterator first, InputIterator last)
	{
		// marche pas
		for (; first != last; first++)
			insert(*(*first));
	}

	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::p_erase_node(node_type *ptr, const key_type &key)
	{
		if (ptr == NULL || ptr == _end || ptr == _rend)
			return ;
		if (ptr->value->first == key)
		{
			node_type *tmp_parent = ptr->parent;
			bool right;
			node_type *tmp_left = ptr->left;
			node_type *tmp_right = ptr->right;
			node_type *tmp = tmp_right;
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
			_alloc.destroy(ptr->value);
			_alloc.deallocate(ptr->value, 1);
			delete ptr;
			_size--;
			if (!stop)
			{
				if (tmp_right && tmp_right != _end)
				{
					tmp = tmp_right;
					while (tmp->left && tmp->left != _rend)
						tmp = tmp->left;
					if (!(tmp == tmp_right))
					{
						if (tmp == tmp->parent->right)
							tmp->parent->right = tmp->right;
						else
							tmp->parent->left = tmp->right;
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
						_end->parent = tmp_parent;
						tmp_parent->right = _end;
					}
					else
					{
						_rend->parent = tmp_parent;
						tmp_parent->left = _rend;
					}
				}
				if (tmp_left)
					tmp_left->parent = tmp;
				if (tmp_right)
					tmp_right->parent = tmp;
			}
		}
		else if (key_comp()(key, ptr->value->first))
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
		for (; first != last; first++)
			erase(first);
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
			if (temp->value->first == key)
			{
				iterator itr = temp;
				return (itr);
			}
			else if (key_comp()(temp->value->first, key))
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
		return (std::pair<iterator, iterator>(find(key), ++find(key)));
	}

	template< class Key, class T, class Compare, class Allocator >
	std::pair<	typename Map<Key, T, Compare, Allocator>::const_iterator,
				typename Map<Key, T, Compare, Allocator>::const_iterator> Map<Key, T, Compare, Allocator>::equal_range(const Key &key) const
	{
		return (std::pair<iterator, iterator>(find(key), ++find(key)));
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
			if (*itr_l != *itr_r)
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
			if (*itr_l != *itr_r)
				return (true);
			itr_l++;
			itr_r++;
		}
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
			if (*itr_l < *itr_r)
				return (true);
			if (*itr_l > *itr_r)
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
			if (*itr_l > *itr_r)
				return (true);
			else if (*itr_l < *itr_r)
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
			if (*itr_l > *itr_r)
				return (true);
			if (*itr_l < *itr_r)
				return (false);
			itr_l++;
			itr_r++;
		}
		return (true);
	}

	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::grapher(Mtree<Key, T> *item, int current_level, bool side, int *dirswap)
	{
		std::string color = current_level % 2 ? "\033[1;31m" : "\033[1;97m";
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
			ss << item->value->first << "(begin)◗";
		else if (rbegin() == iterator(item))
			ss << item->value->first << "(rbegin)◗";
		else
			ss << item->value->first << "◗";
		ss << reset << std::endl;
		std::cout << ss.str();
	}

	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::put_tree(int i)
	{
		if (empty())
			std::cout << "Put tree : (empty map)" << std::endl;
		else
			btree_apply_by_level(_data, i);
	}

	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::call(Mtree<Key, T> *root, int current_level, bool side, int *dirswap, int maxsize)
	{
		if (current_level < maxsize)
		{
			if (root->right)
			{
				if (side != 1 && current_level != 0)
					dirswap[current_level - 1] = 1;
				else if (current_level != 0)
					dirswap[current_level - 1] = 0;
				call(root->right, current_level + 1, 1, dirswap, maxsize);
			}
			if (root != NULL)
				grapher(root, current_level, side, dirswap);
			if (root->left)
			{
				if (side != 0 && current_level != 0)
					dirswap[current_level - 1] = 1;
				else if (current_level != 0)
					dirswap[current_level - 1] = 0;
				call(root->left, current_level + 1, 0, dirswap, maxsize);
			}
		}
	}

	template< class Key, class T, class Compare, class Allocator >
	int	Map<Key, T, Compare, Allocator>::btree_level_count(Mtree<Key, T> *root)
	{
		int	count;

		count = 0;
		if (!root)
			return (0);
		if (root->left)
			count = std::max(count, btree_level_count(root->left));
		if (root->right)
			count = std::max(count, btree_level_count(root->right));
		return (count + 1);
	}

	template< class Key, class T, class Compare, class Allocator >
	void Map<Key, T, Compare, Allocator>::btree_apply_by_level(Mtree<Key, T> *root, int maxsize)
	{
		int i[maxsize];
		for (int j = 0; j < maxsize - 1; j++)
		{
			i[j] = 0;
		}
		if (!root)
			return ;
		call(root, 0, 0, i, maxsize);
	}
};

#endif