#ifndef WRONGCAT_HPP_
# define WRONGCAT_HPP_

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat& other);
		WrongCat&	operator=(const WrongCat& rhs);
		~WrongCat();
		void	makeSound(void) const;
};

#endif
