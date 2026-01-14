#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

// my test

// #include "Fixed.hpp"
// #include <iostream>
// #include <limits>
// int	main(void)
// {
// 	try
// 	{
// 		std::cout << "my test" << std::endl;
// 		Fixed	a;
// 		Fixed	b(0.01f);
// 		Fixed	c(2);
// 		// Fixed	a(std::numeric_limits<int>::max() >> 8);
// 		// Fixed	b(std::numeric_limits<int>::min() >> 8);
// 		// Fixed	c(-1);
// 		std::cout << std::boolalpha;
// 		std::cout << "a is " << a << std::endl;
// 		std::cout << "b is " << b << std::endl;
// 		std::cout << "c is " << c << std::endl;
// 		std::cout << "a > b is " << (a > b) << std::endl;
// 		std::cout << "b >= 0.01f is " << (b >= Fixed(0.01f)) << std::endl;
// 		std::cout << "b + c is " << b + c << std::endl;
// 		std::cout << "b - c is " << b - c << std::endl;
// 		std::cout << "b * c is " << b * c << std::endl;
// 		std::cout << "b / c is " << b / c << std::endl;
// 		std::cout << "c * a is " << c * a << std::endl;
// 		std::cout << "c / a is " << c / a << std::endl;
// 	}
// 	catch (std::exception& e)
// 	{
// 		std:: cerr << "Error: " << e.what() << std::endl;
// 	}
// }
