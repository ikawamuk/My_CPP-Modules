#ifndef ICE_HPP_
# define ICE_HPP_

#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice(void);
		Ice(const Ice& other);
		Ice&	operator=(const Ice& rhs);
		~Ice();
		AMateria*	clone() const;

	private:
		std::string	type_name(void) const;
		void		put_message(const std::string& name) const;
};

#endif
