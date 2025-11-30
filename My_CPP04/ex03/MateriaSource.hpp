#ifndef MATERIASOURCE_HPP_
# define MATERIASOURCE_HPP_

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& other);
		MateriaSource&	operator=(const MateriaSource& rhs);
		~MateriaSource();
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

	private:
		static const int	SLOT_SIZE = 4;
		AMateria			*templates_[SLOT_SIZE];
		void	delete_stock(void);
		void	copy_stock(const MateriaSource& src);
};

#endif
