#ifndef NAME_HPP_
# define NAME_HPP_

#include <iostream>

class Name
{
	public:
		explicit Name(std::string name = "No name");
		Name(const Name& other);
		~Name();
		Name&	operator=(const Name& rhs);
		std::string	value(void) const;

	private:
		std::string	value_;
};

std::ostream&	operator<<(std::ostream& os, const Name& name);

#endif
