#ifndef Span2_HPP
# define Span2_HPP

# include <iostream>
# include <string>
# include <vector>
# include <iterator>

class Span2
{

	public:

		Span2();
		Span2(unsigned int n);
		Span2( Span2 const & src );
		~Span2();

		Span2 &		operator=( Span2 const & rhs );

		unsigned int getSize() const;
		void addNumber(int nb);
		template<typename T>
		void addMultiple(const T& cont)
		{
			T b;
			b = const_cast<T&>(cont);
			typename T::iterator itr;
			int i(0);

			for (itr = b.begin(); itr != b.end(); itr++)
			{
				i++;
				if (this->size > this->arr.size())
					this->arr.push_back(*itr);
				else
					throw Span2::MaxSizeOfVectorException();
			}
		}
		long shortestSpan2();
		long longestSpan2();

	class MaxSizeOfVectorException : public std::exception
	{
		public:
			virtual const char* what () const throw();
	};

	class NoValueException : public std::exception
	{
		public:
			virtual const char* what () const throw();
	};

	private:
		std::vector<int> arr;
		const unsigned int size;

};

#endif /* ************************************************************ Span2_H */