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

	template < typename It >
	class ReverseIterator : public It
	{
		public:
			using typename It::link_type;
			using typename It::link_pointer;
			using typename It::value_type;
			using typename It::pointer;
			using typename It::const_pointer;
			using typename It::reference;
			using typename It::const_reference;
		
		
			ReverseIterator() : It(){};
			ReverseIterator(It const & it) : It(it){};
			ReverseIterator(ReverseIterator const & rhs)
			{
				this->current = rhs.current;
			};
			~ReverseIterator(){};
			ReverseIterator &operator=( ReverseIterator const & rhs )
			{
				this->current = rhs->current;
			}

			ReverseIterator &operator++()
			{
				this->current = this->current->previous;
				return(*this);
			}
			ReverseIterator operator++(int)
			{
				ReverseIterator tmp(*this);
				this->current = this->current->previous;
				return(tmp);
			}

			virtual ReverseIterator &operator--()
			{
				this->current = this->current->next;
				return(*this);
			}
			virtual ReverseIterator operator--(int)
			{
				ReverseIterator tmp(*this);
				this->current = this->current->next;
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
			Iterator(link_pointer li)
			{
				this->current = li;
			};

			Iterator( Iterator const & rhs ) : current(rhs.current){};
			Iterator( ConstIterator<T, L> const & rhs ) : current(rhs.current){};
			~Iterator(){};
			Iterator &operator=( Iterator const & rhs )
			{
				if (this == &rhs) return(*this);
        		this->~Iterator();
        		return *new(this) Iterator(rhs);
			}
			Iterator &operator=( ConstIterator<T, L> const & rhs )
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
			bool operator==(const Iterator & rhs)
			{
				return (this->current == rhs.current);
			}
			bool operator!=(const Iterator & rhs)
			{
				return (current != rhs.current);
			}
			bool operator==(const ConstIterator<T, L> & rhs)
			{
				return (this->current == rhs.current);
			}
			bool operator!=(const ConstIterator<T, L> & rhs)
			{
				return (current != rhs.current);
			}
			reference operator*()
			{
				return(this->current->value);
			}
			reference operator->()
			{
				return(this->current->value);
			}

			//Output Category ?????????????????????????? WHAT DO?

			//Forward Specific Category
			Iterator()
			{
				current = NULL;
			};

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

			bool isIter(){return(1);};
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
			ConstIterator(link_pointer li)
			{
				this->current = li;
			};

			ConstIterator( ConstIterator const & rhs ) : current(rhs.current){};
			ConstIterator( Iterator<T, L> const & rhs ) : current(rhs.current){};
			~ConstIterator(){};
			ConstIterator &operator=( ConstIterator const & rhs )
			{
				if (this == &rhs) return(*this);
        		this->~ConstIterator();
        		return *new(this) ConstIterator(rhs);
			}

			ConstIterator &operator=( Iterator<T, L> const & rhs )
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
			bool operator==(const ConstIterator & rhs)
			{
				return (this->current == rhs.current);
			}
			bool operator!=(const ConstIterator & rhs)
			{
				return (current != rhs.current);
			}
			bool operator==(const Iterator<T, L> & rhs)
			{
				return (this->current == rhs.current);
			}
			bool operator!=(const Iterator<T, L> & rhs)
			{
				return (current != rhs.current);
			}
			reference operator*() const
			{
				return(this->current->value);
			}
			reference operator->() const
			{
				return(this->current->value);
			}

			//Output Category ?????????????????????????? WHAT DO?

			//Forward Specific Category
			ConstIterator()
			{
				current = NULL;
			};

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

			bool isIter(){return(1);};
	};

}

#endif