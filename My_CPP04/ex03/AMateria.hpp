#ifndef AMATERIA_HPP_
# define AMATERIA_HPP_

#include <string>

class AMateria
{
	protected:
		// some member function
	public:
		AMateria(std::string const & type);
		// some member function
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		// virtual void use(ICharacter& target);
};

#endif
