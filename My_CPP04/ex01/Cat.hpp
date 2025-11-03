#ifndef CAT_HPP_
# define CAT_HPP_

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat: public Animal
{
	public:
		Cat(const std::string& type = "Cat");
		Cat(const Cat& other);
		Cat&	operator=(const Cat& rhs);
		virtual ~Cat();
		void	makeSound(void) const;
		Brain&	brain(void);

	private:
		Brain*	brain_;
};

#endif
