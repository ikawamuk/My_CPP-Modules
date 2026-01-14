#ifndef FIXED_HPP_
# define FIXED_HPP_

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed&);
		Fixed&	operator=(const Fixed&);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					value_;
		static const int	FRACTIONAL_BITS = 8;
};

#endif
