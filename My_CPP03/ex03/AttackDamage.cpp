#include "AttackDamage.hpp"

AttackDamage::AttackDamage(void)
:NumericParameter()
{}

AttackDamage::AttackDamage(int value)
:NumericParameter(value)
{}

AttackDamage::AttackDamage(unsigned int value)
:NumericParameter(value)
{}

AttackDamage::AttackDamage(long value)
:NumericParameter(value)
{}

AttackDamage::AttackDamage(unsigned long value)
:NumericParameter(value)
{}


AttackDamage::AttackDamage(const AttackDamage& other)
:NumericParameter(other)
{}

AttackDamage::~AttackDamage()
{}

AttackDamage&	AttackDamage::operator=(const AttackDamage& rhs)
{
	if (this != &rhs)
		NumericParameter::operator=(rhs);
	return (*this);
}
