#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <memory>
# include <iostream>
# include <string>
# include <string.h>
# include <stack>
# include <deque>
# include <string>
# include <iostream>
# include <iomanip>
# include <sstream>

# ifdef __linux__
#  include <limits>
#  include <typeinfo>
# endif

namespace ft
{
	template <class T>	struct is_integral						{ typedef void *	type; };
	template <>         struct is_integral<bool>				{ typedef int		type; };
	template <>         struct is_integral<char>				{ typedef int		type; };
	template <>         struct is_integral<signed char>			{ typedef int		type; };
	template <>         struct is_integral<unsigned char>		{ typedef int		type; };
	template <>         struct is_integral<wchar_t>				{ typedef int		type; };
	// template <>         struct is_integral<char16_t>			{ typedef int		type; };
	// template <>         struct is_integral<char32_t>			{ typedef int		type; };
	template <>         struct is_integral<short>				{ typedef int		type; };
	template <>         struct is_integral<unsigned short>		{ typedef int		type; };
	template <>         struct is_integral<int>					{ typedef int		type; };
	template <>         struct is_integral<unsigned int>		{ typedef int		type; };
	template <>         struct is_integral<long>				{ typedef int		type; };
	template <>         struct is_integral<unsigned long>		{ typedef int		type; };
	template <>         struct is_integral<long long>			{ typedef int		type; };
	template <>         struct is_integral<unsigned long long>	{ typedef int		type; };
	template <>         struct is_integral<__int128_t>			{ typedef int		type; };
	template <>         struct is_integral<__uint128_t>			{ typedef int		type; };

	template < class T, class L >
	class ConstListIterator;
	template< class T >
	class ConstVectorIterator;
	template< class T, class M >
	class ConstMapIterator;

	template < typename It >
	class ReverseIterator : public It
	{
		public:
			using typename It::value_type;
			using typename It::pointer;
			using typename It::const_pointer;
			using typename It::reference;
			using typename It::const_reference;

			ReverseIterator() : It() {}
			ReverseIterator(pointer data, size_t size, size_t index) : It(data, size, index) {}
			template<class Ts>
			ReverseIterator(ReverseIterator<Ts> const &rhs) : It(rhs) {}
			ReverseIterator(It const &it) : It(it) {}
			~ReverseIterator() {}
			ReverseIterator &operator=( ReverseIterator const &rhs )
			{
				if (this == &rhs) return(*this);
				this->~ReverseIterator();
				return *new(this) ReverseIterator(rhs);
			}

			ReverseIterator &operator++()
			{
				It::operator--();
				return(*this);
			}

			ReverseIterator operator++(int)
			{
				ReverseIterator tmp(*this);
				It::operator--(0);
				return(tmp);
			}

			virtual ReverseIterator &operator--()
			{
				It::operator++();
				return(*this);
			}
			virtual ReverseIterator operator--(int)
			{
				ReverseIterator tmp(*this);
				It::operator++(0);
				return(tmp);
			}
	};

	template < class T, class L >
	class ListIterator
	{
		public:
			typedef L link_type;
			typedef link_type* link_pointer;
			typedef T value_type;
			typedef value_type* pointer;
			typedef const value_type* const_pointer;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef const_reference iterator_category;

			link_pointer current;

		public:
			//BASICS
			ListIterator(link_pointer li) : current(li) {}
			ListIterator(ListIterator const &rhs) : current(rhs.current) {}
			ListIterator(ConstListIterator<T, L> const &rhs) : current(rhs.current) {}
			~ListIterator() {}
			ListIterator &operator=(ListIterator const &rhs)
			{
				if (this == &rhs) return(*this);
        		this->~ListIterator();
        		return *new(this) ListIterator(rhs);
			}
			ListIterator &operator=(ConstListIterator<T, L> const &rhs)
			{
				if (this == &rhs) return(*this);
        		this->~ListIterator();
        		return *new(this) ListIterator(rhs);
			}

			//BASICS INCREMENTATION
			ListIterator &operator++()
			{
				this->current = this->current->next;
				return(*this);
			}
			ListIterator operator++(int)
			{
				ListIterator tmp(*this);
				this->current = this->current->next;
				return(tmp);
			}

			//Input Category
			bool operator==(const ListIterator & rhs) { return (this->current == rhs.current); }
			bool operator!=(const ListIterator & rhs) { return (current != rhs.current); }
			bool operator==(const ConstListIterator<T, L> & rhs) { return (this->current == rhs.current); }
			bool operator!=(const ConstListIterator<T, L> & rhs) { return (current != rhs.current); }
			reference operator*() { return(this->current->value); }
			reference operator->() { return(this->current->value); }

			//Output Category ?????????????????????????? WHAT DO?

			//Forward Specific Category
			ListIterator() : current(NULL) {}

			//Bidirectional Category
			ListIterator &operator--()
			{
				this->current = this->current->previous;
				return(*this);
			}
			ListIterator operator--(int)
			{
				ListIterator tmp(*this);
				this->current = this->current->previous;
				return(tmp);
			}
	};

	template < class T, class L >
	class ConstListIterator
	{
		public:
			typedef L link_type;
			typedef link_type* link_pointer;
			typedef T value_type;
			typedef value_type* pointer;
			typedef const value_type* const_pointer;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef const_reference iterator_category;

			link_pointer current;

		public:
			//BASICS
			ConstListIterator(link_pointer li) : current(li) {}
			ConstListIterator(ConstListIterator const &rhs) : current(rhs.current) {}
			ConstListIterator(ListIterator<T, L> const &rhs) : current(rhs.current) {}
			~ConstListIterator() {}
			ConstListIterator &operator=(ConstListIterator const &rhs)
			{
				if (this == &rhs) return(*this);
        		this->~ConstListIterator();
        		return *new(this) ConstListIterator(rhs);
			}

			ConstListIterator &operator=(ListIterator<T, L> const &rhs)
			{
				if (this == &rhs) return(*this);
        		this->~ConstListIterator();
        		return *new(this) ConstListIterator(rhs);
			}

			//BASICS INCREMENTATION
			ConstListIterator &operator++()
			{
				this->current = this->current->next;
				return(*this);
			}
			ConstListIterator operator++(int)
			{
				ConstListIterator tmp(*this);
				this->current = this->current->next;
				return(tmp);
			}

			//Input Category
			bool operator==(const ConstListIterator & rhs) { return (this->current == rhs.current); }
			bool operator!=(const ConstListIterator & rhs) { return (current != rhs.current); }
			bool operator==(const ListIterator<T, L> & rhs) { return (this->current == rhs.current); }
			bool operator!=(const ListIterator<T, L> & rhs) { return (current != rhs.current); }
			reference operator*() const { return(this->current->value); }
			reference operator->() const { return(this->current->value); }

			//Forward Specific Category
			ConstListIterator() { current = NULL; }

			//Bidirectional Category
			ConstListIterator &operator--()
			{
				this->current = this->current->previous;
				return(*this);
			}
			ConstListIterator operator--(int)
			{
				ConstListIterator tmp(*this);
				this->current = this->current->previous;
				return(tmp);
			}
	};

	template< class T >
	class VectorIterator
	{
		public:
			typedef T value_type;
			typedef value_type* pointer;
			typedef const value_type* const_pointer;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef const_reference iterator_category;
			typedef std::size_t size_type;

			pointer _data;
			size_type _size;
			size_type _index;

			VectorIterator(pointer data, size_type size, size_type index) : _data(data), _size(size), _index(index) {}
			VectorIterator(VectorIterator const &rhs) : _data(rhs._data), _size(rhs._size), _index(rhs._index) {}
			VectorIterator(VectorIterator const &rhs, pointer data) : _data(data), _size(rhs._size), _index(rhs._index) {}
			VectorIterator(ConstVectorIterator<T> const &rhs) : _data(rhs._data), _size(rhs._size), _index(rhs._index) {}
			VectorIterator(ConstVectorIterator<T> const &rhs, pointer data) : _data(data), _size(rhs._size), _index(rhs._index) {}
			~VectorIterator() {}

			VectorIterator &operator=(const VectorIterator &rhs)
			{
				if (this == &rhs) return(*this);
        		this->~VectorIterator();
        		return *new(this) VectorIterator(rhs);
			}
			VectorIterator &operator=(const ConstVectorIterator<T> &rhs)
			{
				if (this == &rhs) return(*this);
        		this->~VectorIterator();
        		return *new(this) VectorIterator(rhs);
			}

			//BASICS INCREMENTATION
			VectorIterator &operator++()
			{
				_index++;
				return (*this);
			}
			
			VectorIterator operator++(int)
			{
				VectorIterator tmp(*this);
				++(*this);
				return (tmp);
			}

			//Input Category
			bool operator==(const VectorIterator &rhs) { return (_data == rhs._data && _index == rhs._index); }
			bool operator!=(const VectorIterator &rhs) { return (_data != rhs._data || _index != rhs._index); }
			bool operator==(const ConstVectorIterator<T> &rhs) { return (_data == rhs._data && _index == rhs._index); }
			bool operator!=(const ConstVectorIterator<T> &rhs) { return (_data != rhs._data || _index != rhs._index); }
			reference operator*() { return(_data[_index]); }
			reference operator->() { return(_data[_index]); }

			//Forward Specific Category
			VectorIterator()
			{
				_data = NULL;
				_size = 0;
				_index = 0;
			};

			//Bidirectional Category
			VectorIterator &operator--()
			{
				_index--;
				return (*this);
			}

			VectorIterator operator--(int)
			{
				VectorIterator tmp(*this);
				--(*this);
				return (tmp);
			}	

			// Random Access Category
			bool operator<(const VectorIterator &rhs) { return (_data == rhs._data && _index < rhs._index); }
			bool operator<=(const VectorIterator &rhs) { return (_data == rhs._data && _index <= rhs._index); }
			bool operator>(const VectorIterator &rhs) { return (_data == rhs._data && _index > rhs._index); }
			bool operator>=(const VectorIterator &rhs) { return (_data == rhs._data && _index >= rhs._index); }
			bool operator<(const ConstVectorIterator<T> &rhs) { return (_data == rhs._data && _index < rhs._index); }
			bool operator<=(const ConstVectorIterator<T> &rhs) { return (_data == rhs._data && _index <= rhs._index); }
			bool operator>(const ConstVectorIterator<T> &rhs) { return (_data == rhs._data && _index > rhs._index); }
			bool operator>=(const ConstVectorIterator<T> &rhs) { return (_data == rhs._data && _index >= rhs._index); }

			VectorIterator operator+(std::ptrdiff_t n) { return (VectorIterator(_data, _size, _index + n)); }
			VectorIterator operator-(std::ptrdiff_t n) { return (VectorIterator(_data, _size, _index - n)); }

			VectorIterator &operator+=(const std::ptrdiff_t &rhs) {
    			this->_index += rhs;
	    		return *this;
			}

			VectorIterator &operator-=(const std::ptrdiff_t &rhs) {
    			this->_index -= rhs;
	    		return *this;
			}

			T& operator[](const std::ptrdiff_t& n) {
	    		return (_data[_index + n]);
			}
	};

	template< class T >
	class ConstVectorIterator
	{
		public:
			typedef T value_type;
			typedef value_type* pointer;
			typedef const value_type* const_pointer;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef const_reference iterator_category;
			typedef std::size_t size_type;

			pointer _data;
			size_type _size;
			size_type _index;

			ConstVectorIterator(pointer data, size_type size, size_type index) : _data(data), _size(size), _index(index) {}
			ConstVectorIterator(ConstVectorIterator const &rhs) : _data(rhs._data), _size(rhs._size), _index(rhs._index) {}
			ConstVectorIterator(ConstVectorIterator const &rhs, pointer data) : _data(data), _size(rhs._size), _index(rhs._index) {}
			ConstVectorIterator(VectorIterator<T> const &rhs) : _data(rhs._data), _size(rhs._size), _index(rhs._index) {}
			ConstVectorIterator(VectorIterator<T> const &rhs, pointer data) : _data(data), _size(rhs._size), _index(rhs._index) {}
			~ConstVectorIterator() {}

			ConstVectorIterator &operator=(const ConstVectorIterator &rhs)
			{
				if (this == &rhs) return(*this);
        		this->~ConstVectorIterator();
        		return *new(this) ConstVectorIterator(rhs);
			}
			ConstVectorIterator &operator=(const VectorIterator<T> &rhs)
			{
				if (this == &rhs) return(*this);
        		this->~ConstVectorIterator();
        		return *new(this) ConstVectorIterator(rhs);
			}

			//BASICS INCREMENTATION
			ConstVectorIterator &operator++()
			{
				_index++;
				return (*this);
			}
			ConstVectorIterator operator++(int)
			{
				ConstVectorIterator tmp(*this);
				++(*this);
				return (tmp);
			}

			//Input Category
			bool operator==(const ConstVectorIterator &rhs) { return (_data == rhs._data && _index == rhs._index); }
			bool operator!=(const ConstVectorIterator &rhs) { return (_data != rhs._data || _index != rhs._index); }
			bool operator==(const VectorIterator<T> &rhs) { return (_data == rhs._data && _index == rhs._index); }
			bool operator!=(const VectorIterator<T> &rhs) { return (_data != rhs._data || _index != rhs._index); }

			reference operator*() const { return(_data[_index]); }
			reference operator->() const { return(_data[_index]); }

			//Forward Specific Category
			ConstVectorIterator()
			{
				_data = NULL;
				_size = 0;
				_index = 0;
			};

			//Bidirectional Category
			ConstVectorIterator &operator--()
			{
				_index--;
				return (*this);
			}
			ConstVectorIterator operator--(int)
			{
				ConstVectorIterator tmp(*this);
				--(*this);
				return (tmp);
			}

			//Random Access Category
			bool operator<(const ConstVectorIterator &rhs) { return (_data == rhs._data && _index < rhs._index); }
			bool operator<=(const ConstVectorIterator &rhs) { return (_data == rhs._data && _index <= rhs._index); }
			bool operator>(const ConstVectorIterator &rhs) { return (_data == rhs._data && _index > rhs._index); }
			bool operator>=(const ConstVectorIterator &rhs) { return (_data == rhs._data && _index >= rhs._index); }
			bool operator<(const VectorIterator<T> &rhs) { return (_data == rhs._data && _index < rhs._index); }
			bool operator<=(const VectorIterator<T> &rhs) { return (_data == rhs._data && _index <= rhs._index); }
			bool operator>(const VectorIterator<T> &rhs) { return (_data == rhs._data && _index > rhs._index); }
			bool operator>=(const VectorIterator<T> &rhs) { return (_data == rhs._data && _index >= rhs._index); }

			ConstVectorIterator operator+(std::ptrdiff_t n) { return (ConstVectorIterator(_data, _size, _index + n)); }
			ConstVectorIterator operator-(std::ptrdiff_t n) { return (ConstVectorIterator(_data, _size, _index - n)); }
			
			ConstVectorIterator &operator+=(const std::ptrdiff_t &rhs) {
    			this->_index += rhs;
	    		return *this;
			}

			ConstVectorIterator &operator-=(const std::ptrdiff_t &rhs) {
    			this->_index -= rhs;
	    		return *this;
			}

			T &operator[](const std::ptrdiff_t& n) {
	    		return (_data[_index + n]);
			}
	};

	template < class T, class M >
	class MapIterator
	{
		public:
			typedef M map_type;
			typedef map_type* map_pointer;
			typedef T value_type;
			typedef value_type* pointer;
			typedef const value_type* const_pointer;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef const_reference iterator_category;

			map_pointer _current;

			//BASICS
			~MapIterator() {}
			MapIterator() : _current(NULL) {}
			MapIterator(MapIterator const &rhs) : _current(rhs._current) {}
			MapIterator(ConstMapIterator<T, M> const &rhs) : _current(rhs._current) {}
			MapIterator(map_pointer current) : _current(current) {}

			MapIterator &operator=(MapIterator const &rhs)
			{
				if (this == &rhs) return(*this);
        		this->~MapIterator();
        		return *new(this) MapIterator(rhs);
			}

			MapIterator &operator=(ConstMapIterator<T, M> const &rhs)
			{
				if (this == &rhs) return(*this);
        		this->~MapIterator();
        		return *new(this) MapIterator(rhs);
			}

			//Input Category
			bool operator==(const MapIterator & rhs) { return (_current == rhs._current); }
			bool operator!=(const MapIterator & rhs) { return (_current != rhs._current); }
			bool operator==(const ConstMapIterator<T, M> & rhs) { return (_current == rhs._current); }
			bool operator!=(const ConstMapIterator<T, M> & rhs) { return (_current != rhs._current); }
			T *operator*() { return(&(_current->value)); }
			T *operator->() { return(&(_current->value)); }

			//Bidirectional Category
			MapIterator &operator++()
			{
				if (_current->right) // go droite si tu peux
				{
					_current = _current->right;
					while (_current->left) // go au max en bas a gauche
						_current = _current->left;
				}
				else // remonte tout les passages de droites jusqu'a gauche ou le centre sauf si cest la fin
				{
					while (_current->parent && _current == _current->parent->right) // remonte all droite
						_current = _current->parent;
					_current = _current->parent; // remonte un gauche
				}
				return (*this);
			}

			MapIterator &operator--()
			{
				if (_current->left) // go au au max a droite de la gauche en bas
				{
					_current = _current->left;
					while (_current->right) // en prenant tout les chemins de droite
						_current = _current->right;
				}
				else // remonte tant que pas branche de droite
				{ 
					while (_current->parent && _current == _current->parent->left) // remonte tout les gauches
						_current = _current->parent;
					_current = _current->parent; // remonte un droite// remonte une fois si cest pas le last
				}
				return (*this);
			}

			MapIterator operator++(int)
			{
				MapIterator tmp(*this);
				++(*this);
				return (tmp);
			}

			MapIterator operator--(int)
			{
				MapIterator tmp(*this);
				--(*this);
				return (*this);
			}
	};

	template < class T, class M >
	class ConstMapIterator
	{
		public:
			typedef M map_type;
			typedef map_type* map_pointer;
			typedef T value_type;
			typedef value_type* pointer;
			typedef const value_type* const_pointer;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef const_reference iterator_category;

			map_pointer _current;

			//BASICS
			~ConstMapIterator() {}
			ConstMapIterator() : _current(NULL) {}
			ConstMapIterator(ConstMapIterator const &rhs) : _current(rhs._current) {}
			ConstMapIterator(MapIterator<T, M> const &rhs) : _current(rhs._current) {}
			ConstMapIterator(map_pointer current) : _current(current) {}

			ConstMapIterator &operator=(ConstMapIterator const &rhs)
			{
				if (this == &rhs) return(*this);
        		this->~ConstMapIterator();
        		return *new(this) ConstMapIterator(rhs);
			}

			ConstMapIterator &operator=(MapIterator<T, M> const &rhs)
			{
				if (this == &rhs) return(*this);
        		this->~ConstMapIterator();
        		return *new(this) ConstMapIterator(rhs);
			}

			//Input Category
			bool operator==(const ConstMapIterator & rhs) { return (_current == rhs._current); }
			bool operator!=(const ConstMapIterator & rhs) { return (_current != rhs._current); }
			bool operator==(const MapIterator<T, M> & rhs) { return (_current == rhs._current); }
			bool operator!=(const MapIterator<T, M> & rhs) { return (_current != rhs._current); }
			T *operator*() { return(&(this->_current->value)); }
			T *operator->() { return(&(this->_current->value)); }

			//Bidirectional Category
			ConstMapIterator &operator++()
			{
				if (_current->right) // go droite si tu peux
				{
					_current = _current->right;
					while (_current->left) // go au max en bas a gauche
						_current = _current->left;
				}
				else // remonte tout les passages de droites jusqu'a gauche ou le centre sauf si cest la fin
				{
					while (_current->parent && _current == _current->parent->right) // remonte all droite
						_current = _current->parent;
					_current = _current->parent; // remonte un gauche
				}
				return (*this);
			}

			ConstMapIterator &operator--()
			{
				if (_current->left) // go au au max a droite de la gauche en bas
				{
					_current = _current->left;
					while (_current->right) // en prenant tout les chemins de droite
						_current = _current->right;
				}
				else // remonte tant que pas branche de droite
				{ 
					while (_current->parent && _current == _current->parent->left) // remonte tout les gauches
						_current = _current->parent;
					_current = _current->parent; // remonte un droite// remonte une fois si cest pas le last
				}
				return (*this);
			}

			ConstMapIterator operator++(int)
			{
				ConstMapIterator tmp(*this);
				++(*this);
				return (tmp);
			}

			ConstMapIterator operator--(int)
			{
				ConstMapIterator tmp(*this);
				--(*this);
				return (*this);
			}
	};

	template < typename MapIterator >
	class ReverseMapIterator : public MapIterator
	{
		public:
			using typename MapIterator::value_type;
			using typename MapIterator::pointer;
			using typename MapIterator::const_pointer;
			using typename MapIterator::reference;
			using typename MapIterator::const_reference;

			ReverseMapIterator() : MapIterator() {}
			template<class Ts>
			ReverseMapIterator(ReverseMapIterator<Ts> const &rhs) : MapIterator(rhs) {}
			ReverseMapIterator(MapIterator const &rhs) : MapIterator(rhs) {}
			~ReverseMapIterator() {}

			ReverseMapIterator &operator=( ReverseMapIterator const &rhs )
			{
				if (this == &rhs) return(*this);
				this->~ReverseMapIterator();
				return *new(this) ReverseMapIterator(rhs);
			}

			ReverseMapIterator &operator++()
			{
				MapIterator::operator--();
				return(*this);
			}

			ReverseMapIterator operator++(int)
			{
				ReverseMapIterator tmp(*this);
				MapIterator::operator--(0);
				return(tmp);
			}

			virtual ReverseMapIterator &operator--()
			{
				MapIterator::operator++();
				return(*this);
			}
			virtual ReverseMapIterator operator--(int)
			{
				ReverseMapIterator tmp(*this);
				MapIterator::operator++(0);
				return(tmp);
			}
	};
};

#endif