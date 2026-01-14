#ifndef FIXED_HPP_
# define FIXED_HPP_

#include <fstream>
#include <iostream>
#include <climits>

#if !(LONG_MAX > INT_MAX)
	#include <stdint.h>
	typedef long			int64_t;
	typedef unsigned long	uint64_t;
#endif

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed(const int value);
		Fixed(const float value);
		Fixed&	operator=(const Fixed& rhs);
		Fixed&	operator+=(const Fixed& rhs);
		Fixed&	operator-=(const Fixed& rhs);
		Fixed&	operator*=(const Fixed& rhs);
		Fixed&	operator/=(const Fixed& rhs);
		Fixed&	operator=(const int int_value);
		Fixed&	operator=(const float float_value);
		bool operator! (void) const;
		bool operator> (const Fixed& rhs) const;
		bool operator< (const Fixed& rhs) const;
		bool operator>= (const Fixed& rhs) const;
		bool operator<= (const Fixed& rhs) const;
		bool operator== (const Fixed& rhs) const;
		bool operator!= (const Fixed& rhs) const;
		Fixed operator+(const Fixed& rhs) const;
		Fixed operator-(const Fixed& rhs) const;
		Fixed operator*(const Fixed& rhs) const;
		Fixed operator/(const Fixed& rhs) const;
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed&	min(Fixed& f1, Fixed& f2);
		static Fixed&	max(Fixed& f1, Fixed& f2);
		static const Fixed&	min(const Fixed& f1, const Fixed& f2);
		static const Fixed&	max(const Fixed& f1, const Fixed& f2);

	private:
		int					value_;
		static const int	FRACTIONAL_BITS = 8;
};

std::ostream&	operator<<(std::ostream&, const Fixed&);

#endif
