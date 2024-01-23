#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <limits>
# include <cstdlib>
# include <ctime>

class Span
{
	public:
		//Constructors & Destructor
		Span():_array(0), _nb(0) {}
		Span(const size_t n): _array(0), _nb(n) {}
		~Span() {}

		// Assignment operator & Copy
		Span(const Span& copy) { *this = copy; }
		Span& operator=(const Span& src);

		// Member functions
		void	addNumber(const int n);
		size_t	getSpan(const long nb1, const long nb2);
		size_t	shortestSpan();
		size_t	longestSpan();

		// Exceptions
		class InsufficientStorage : public std::exception
		{
			public :
				const char* what() const throw() {
					return ("\033[0;31mError: Not enough storage to add a number.\n\033[0m");
				}
		};

		class NoSpanFound : public std::exception
		{
			public :
				const char* what() const throw() {
					return ("\033[0;31mError: Cannot find shortest/longest span. Check that you have more than one number in span.\n\033[0m");
				}
		};

	private:
		std::vector<long>	_array;
		size_t				_nb;
};

#endif