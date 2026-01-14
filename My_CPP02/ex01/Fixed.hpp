#ifndef FIXED_HPP_
# define FIXED_HPP_

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed(const int value);
		Fixed(const float value);
		Fixed&	operator=(const Fixed& other);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					value_;
		static const int	FRACTIONAL_BITS = 8;
};

std::ostream&	operator<<(std::ostream&, const Fixed&);

#endif
