#include "Name.hpp"
#include <stdexcept>

Name::Name(const std::string& value)
:value_(validate(value))
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

const std::string&	Name::value(void) const
{
	return (value_);
}

std::string	Name::validate(const std::string& value)
{
	if (value.empty())
		throw std::invalid_argument("empty name");
	return (value);
}

std::ostream&	operator<<(std::ostream& os, const Name& name)
{
	os << name.value();
	return (os);
}
