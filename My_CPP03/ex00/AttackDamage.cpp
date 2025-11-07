#include "AttackDamage.hpp"
#include <limits>
#include <stdexcept>

Attackdamage::Attackdamage(unsigned int value)
:value_(value)
{}

Attackdamage::Attackdamage(const Attackdamage& other)
:value_(other.value_)
{}

Attackdamage::~Attackdamage()
{}

Attackdamage& Attackdamage::operator=(const Attackdamage& rhs)
{
	if (this != &rhs)
		value_ = rhs.value_;
	return (*this);
}

unsigned int	Attackdamage::value(void) const
{
	return (value_);
}

std::ostream&	operator<<(std::ostream& os, const Attackdamage& attack_damage)
{
	os << attack_damage.value();
	return (os);
}
