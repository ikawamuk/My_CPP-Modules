#ifndef DOG_HPP_
# define DOG_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	public:
		Dog(void);
		Dog(const Dog& other);
		Dog&	operator=(const Dog& rhs);
		~Dog();
		void	makeSound(void) const;
		void	think(const std::string& idea);

	private:
		Brain*	brain_p_;
};

#endif
