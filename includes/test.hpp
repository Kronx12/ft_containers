#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <iterator>

class Span
{

	public:

		Span();
		Span(unsigned int n);
		Span( Span const & src );
		~Span();

		Span &		operator=( Span const & rhs );

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
					throw Span::MaxSizeOfVectorException();
			}
		}
		long shortestSpan();
		long longestSpan();

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

#endif /* ************************************************************ SPAN_H */