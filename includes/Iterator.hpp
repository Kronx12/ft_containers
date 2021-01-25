#ifndef ITERATOR_HPP
# define ITERATOR_HPP

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
	class ConstIterator;
	template< class T >
	class ConstVectorIterator;

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
	class Iterator
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
			Iterator(link_pointer li) : current(li) {}
			Iterator(Iterator const &rhs) : current(rhs.current) {}
			Iterator(ConstIterator<T, L> const &rhs) : current(rhs.current) {}
			~Iterator() {}
			Iterator &operator=(Iterator const &rhs)
			{
				if (this == &rhs) return(*this);
        		this->~Iterator();
        		return *new(this) Iterator(rhs);
			}
			Iterator &operator=(ConstIterator<T, L> const &rhs)
			{
				if (this == &rhs) return(*this);
        		this->~Iterator();
        		return *new(this) Iterator(rhs);
			}

			//BASICS INCREMENTATION
			Iterator &operator++()
			{
				this->current = this->current->next;
				return(*this);
			}
			Iterator operator++(int)
			{
				Iterator tmp(*this);
				this->current = this->current->next;
				return(tmp);
			}

			//Input Category
			bool operator==(const Iterator & rhs) { return (this->current == rhs.current); }
			bool operator!=(const Iterator & rhs) { return (current != rhs.current); }
			bool operator==(const ConstIterator<T, L> & rhs) { return (this->current == rhs.current); }
			bool operator!=(const ConstIterator<T, L> & rhs) { return (current != rhs.current); }
			reference operator*() { return(this->current->value); }
			reference operator->() { return(this->current->value); }

			//Output Category ?????????????????????????? WHAT DO?

			//Forward Specific Category
			Iterator() : current(NULL) {}

			//Bidirectional Category
			Iterator &operator--()
			{
				this->current = this->current->previous;
				return(*this);
			}
			Iterator operator--(int)
			{
				Iterator tmp(*this);
				this->current = this->current->previous;
				return(tmp);
			}
	};

	template < class T, class L >
	class ConstIterator
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
			ConstIterator(link_pointer li) : current(li) {}
			ConstIterator(ConstIterator const &rhs) : current(rhs.current) {}
			ConstIterator(Iterator<T, L> const &rhs) : current(rhs.current) {}
			~ConstIterator() {}
			ConstIterator &operator=(ConstIterator const &rhs)
			{
				if (this == &rhs) return(*this);
        		this->~ConstIterator();
        		return *new(this) ConstIterator(rhs);
			}

			ConstIterator &operator=(Iterator<T, L> const &rhs)
			{
				if (this == &rhs) return(*this);
        		this->~ConstIterator();
        		return *new(this) ConstIterator(rhs);
			}

			//BASICS INCREMENTATION
			ConstIterator &operator++()
			{
				this->current = this->current->next;
				return(*this);
			}
			ConstIterator operator++(int)
			{
				ConstIterator tmp(*this);
				this->current = this->current->next;
				return(tmp);
			}

			//Input Category
			bool operator==(const ConstIterator & rhs) { return (this->current == rhs.current); }
			bool operator!=(const ConstIterator & rhs) { return (current != rhs.current); }
			bool operator==(const Iterator<T, L> & rhs) { return (this->current == rhs.current); }
			bool operator!=(const Iterator<T, L> & rhs) { return (current != rhs.current); }
			reference operator*() const { return(this->current->value); }
			reference operator->() const { return(this->current->value); }

			//Forward Specific Category
			ConstIterator() { current = NULL; }

			//Bidirectional Category
			ConstIterator &operator--()
			{
				this->current = this->current->previous;
				return(*this);
			}
			ConstIterator operator--(int)
			{
				ConstIterator tmp(*this);
				this->current = this->current->previous;
				return(tmp);
			}
	};

	/*
	TODO RandomAccessIterator functions
	*/

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

			VectorIterator &operator=( VectorIterator const & rhs )
			{
				if (this == &rhs) return(*this);
        		this->~VectorIterator();
        		return *new(this) VectorIterator(rhs);
			}
			VectorIterator &operator=( ConstVectorIterator<T> const & rhs )
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
				_index++;
				return (tmp);
			}

			//Input Category
			bool operator==(const VectorIterator & rhs) { return (_data == rhs._data && _index == rhs._index); }
			bool operator!=(const VectorIterator & rhs) { return (!(_data == rhs._data && _index == rhs._index)); }
			bool operator==(const ConstVectorIterator<T> & rhs) { return (_data == rhs._data && _index == rhs._index); }
			bool operator!=(const ConstVectorIterator<T> & rhs) { return (!(_data == rhs._data && _index == rhs._index)); }
			reference operator*() { return(_data[_index]); }
			reference operator->() { return(_data[_index]); }

			// VectorIterator<T> operator+(std::ptrdiff_t ptr) { return (); }

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
				_index--;
				return (tmp);
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

			ConstVectorIterator &operator=( ConstVectorIterator const & rhs )
			{
				if (this == &rhs) return(*this);
        		this->~ConstVectorIterator();
        		return *new(this) ConstVectorIterator(rhs);
			}
			ConstVectorIterator &operator=( VectorIterator<T> const & rhs )
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
				_index++;
				return (tmp);
			}

			//Input Category
			bool operator==(const ConstVectorIterator & rhs) { return (_data == rhs._data && _index == rhs._index); }
			bool operator!=(const ConstVectorIterator & rhs) { return (!(_data == rhs._data && _index == rhs._index)); }
			bool operator==(const VectorIterator<T> & rhs) { return (_data == rhs._data && _index == rhs._index); }
			bool operator!=(const VectorIterator<T> & rhs) { return (!(_data == rhs._data && _index == rhs._index)); }
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
				_index--;
				return (tmp);
			}
	};

	template < class T, class L >
	class MapIterator
	{

	};

	template < class T, class L >
	class ConstMapIterator
	{

	};
}

#endif