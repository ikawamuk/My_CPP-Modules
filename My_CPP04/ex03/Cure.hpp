#ifndef CURE_HPP_
# define CURE_HPP_

#include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure(void);
		Cure(const Cure& other);
		Cure&	operator=(const Cure& rhs);
		~Cure();
		AMateria*	clone() const;

	private:
		std::string	type_name(void) const;
		void		put_message(const std::string& name) const;
};

#endif
