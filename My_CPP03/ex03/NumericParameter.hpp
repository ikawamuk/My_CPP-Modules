#ifndef NUMERICPARAMETER_HPP_
# define NUMERICPARAMETER_HPP_

#include <ostream>

class NumericParameter
{
	public:
		explicit NumericParameter(void);
		explicit NumericParameter(int value);
		explicit NumericParameter(unsigned int value);
		explicit NumericParameter(long value);
		explicit NumericParameter(unsigned long value);
		NumericParameter(const NumericParameter& other);
		~NumericParameter();
		NumericParameter&	operator=(const NumericParameter& rhs);
		NumericParameter&	operator+=(unsigned long amount);
		NumericParameter&	operator-=(unsigned long amount);
		NumericParameter&	operator--(void);
		NumericParameter	operator--(int);
		operator			bool(void) const;
		bool				operator!(void) const;
		unsigned int		value(void) const;

	private:
		unsigned int	value_;
		static unsigned int	validate_signed(long value);
		static unsigned int	validate_unsigned(unsigned long value);
};

std::ostream&	operator<<(std::ostream& os, const NumericParameter& numeric_parameter);
long			operator-(const NumericParameter& lhs, const NumericParameter& rhs);

#endif
