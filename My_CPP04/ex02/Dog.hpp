#ifndef DOG_HPP_
# define DOG_HPP_

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class Dog: public AAnimal
{
	public:
		Dog(const std::string& type = "Dog");
		Dog(const Dog& other);
		Dog&	operator=(const Dog& rhs);
		virtual ~Dog();
		void	makeSound(void) const;

	private:
		Brain*	brain_;
};

#endif
