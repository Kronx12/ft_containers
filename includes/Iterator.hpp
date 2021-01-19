#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
	template <class T> struct isIterator
	{
		// For the compile time comparison.
		typedef char yes[1];
		typedef yes no[2];

		// This helper struct permits us to check two properties of a template argument.
		template <typename U, U u> struct reallyHas;

		// Two overloads for yes: one if for the signature of a normal method, one is for the signature of a const method.
		template <typename C> static yes& test(reallyHas<bool (C::*)(), &C::isIter>* /*unused*/) { }
		template <typename C> static yes& test(reallyHas<bool (C::*)() const, &C::isIter>* /*unused*/) { }

		// The famous C++ sink-hole.
		// Note that sink-hole must be templated too as we are testing test<T>(0).
		template <typename> static no& test(...) { /* dark matter */ }

		// The constant used as a return value for the test.
		enum { value = sizeof(test<T>(0)) == sizeof(yes) };
	};

	//template <class T> bool testisIterator(const T& /*t*/) { return isIterator<T>::value; }

	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };

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
				this->current = rhs->current;
			}
			Iterator &operator=( ConstIterator<T, L> const & rhs )
			{
				this->current = rhs->current;
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
				this->current = rhs->current;
			}

			ConstIterator &operator=( Iterator<T, L> const & rhs )
			{
				this->current = rhs->current;
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
	};

}

#endif