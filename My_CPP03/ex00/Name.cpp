#include "Name.hpp"
#include <limits>
#include <string>
#include <stdexcept>

Name::Name(std::string value)
:value_(value)
{}

Name::Name(const Name& other)
:value_(other.value_)
{}

Name::~Name()
{}

Name& Name::operator=(const Name& rhs)
{
	if (this != &rhs)
		value_ = rhs.value_;
	return (*this);
}

std::string	Name::value(void) const
{
	return (value_);
}

std::ostream&	operator<<(std::ostream& os, const Name& name)
{
	os << name.value();
	return (os);
}
