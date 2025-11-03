#ifndef CAT_HPP_
# define CAT_HPP_

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class Cat: public AAnimal
{
	public:
		Cat(const std::string& type = "Cat");
		Cat(const Cat& other);
		Cat&	operator=(const Cat& rhs);
		virtual ~Cat();
		void	makeSound(void) const;

	private:
		Brain*	brain_;
};

#endif
