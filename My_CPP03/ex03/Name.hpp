#ifndef NAME_HPP_
# define NAME_HPP_

#include <string>

class Name
{
	public:
		explicit Name(const std::string& value = "Unknown");
		Name(const Name& other);
		~Name();
		Name&	operator=(const Name& rhs);
		const std::string&	value(void) const;

	private:
		std::string value_;
		static std::string	validate(const std::string& value);
};

std::ostream&	operator<<(std::ostream& os, const Name& name);

#endif
