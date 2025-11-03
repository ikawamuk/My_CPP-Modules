#ifndef WRONGWrongCat_HPP_
# define WRONGWrongCat_HPP_

#include "WrongAnimal.hpp"
#include <string>

class WrongCat: public WrongAnimal
{
	public:
		WrongCat(const std::string& type = "WrongCat");
		WrongCat(const WrongCat& other);
		WrongCat&	operator=(const WrongCat& rhs);
		virtual ~WrongCat();
		void	makeSound(void) const;
};

#endif
