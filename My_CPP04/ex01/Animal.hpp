#ifndef ANIMAL_HPP_
# define ANIMAL_HPP_

#include <string>

class Animal
{
	public:
		Animal(const std::string& type = "Animal");
		Animal(const Animal& other);
		Animal&	operator=(const Animal& rhs);
		virtual ~Animal();
		virtual void	makeSound(void) const;
		const std::string&	getType(void) const;

	protected:
		std::string	type_;
};

#endif
