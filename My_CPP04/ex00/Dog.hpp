#ifndef DOG_HPP_
# define DOG_HPP_

#include "Animal.hpp"
#include <string>

class Dog: public Animal
{
	public:
		Dog(const std::string& type = "Dog");
		Dog(const Dog& other);
		Dog&	operator=(const Dog& rhs);
		virtual ~Dog();
		void	makeSound(void) const;
};

#endif
