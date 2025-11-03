#ifndef MATERIASOURCE_HPP_
# define MATERIASOURCE_HPP_

#include "AMateria.hpp"
#include <string>

class IMateriaSource
{
	public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource
{

};

#endif
