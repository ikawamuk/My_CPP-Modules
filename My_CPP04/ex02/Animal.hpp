#ifndef ANIMAL_HPP_
# define ANIMAL_HPP_

#include <string>
#include "print_color.hpp"

class Animal
{
	public:
		Animal(void);
		Animal(const Animal& other);
		Animal&	operator=(const Animal& rhs);
		virtual ~Animal();
		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;

	protected:
		Animal(const std::string& type);

	private:
		std::string	type_;
};

#endif
