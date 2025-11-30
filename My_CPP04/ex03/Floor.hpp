#ifndef FLOOR_HPP_
# define FLOOR_HPP_

#include "AMateria.hpp"

class Floor
{
	public:
		Floor(void);
		~Floor();
		void	drop(AMateria* new_one);
		void	clear(void);

	private:
		static const int	STOCK_SIZE = 128;
		AMateria*			stock_[STOCK_SIZE];
		int					current_idx_;
		Floor(const Floor& other);
		Floor&	operator=(const Floor& rhs);
};

#endif