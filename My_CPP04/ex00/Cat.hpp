#ifndef CAT_HPP_
# define CAT_HPP_

#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat(void);
		Cat(const Cat& other);
		Cat&	operator=(const Cat& rhs);
		~Cat();
		void	makeSound(void) const;
};

#endif
