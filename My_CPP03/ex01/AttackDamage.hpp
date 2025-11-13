#ifndef ATTACKDAMAGE_HPP_
# define ATTACKDAMAGE_HPP_

#include <ostream>
#include "NumericParameter.hpp"

class AttackDamage: public NumericParameter
{
	public:
		explicit AttackDamage(void);
		explicit AttackDamage(int value);
		explicit AttackDamage(unsigned int value);
		explicit AttackDamage(long value);
		explicit AttackDamage(unsigned long value);
		AttackDamage(const AttackDamage& other);
		~AttackDamage();
		AttackDamage&	operator=(const AttackDamage& rhs);
		using NumericParameter::value;

	private:
		using NumericParameter::operator+=;
		using NumericParameter::operator-=;
		using NumericParameter::operator--;
};

#endif
