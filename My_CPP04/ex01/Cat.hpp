#ifndef CAT_HPP_
# define CAT_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	public:
		Cat(void);
		Cat(const Cat& other);
		Cat&	operator=(const Cat& rhs);
		~Cat();
		void	makeSound(void) const;
		void	think(const std::string& idea);

	private:
		Brain*	brain_p_;
};

#endif
