#ifndef BRAIN_HPP_
# define BRAIN_HPP_

#include <string>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain& other);
		Brain&	operator=(const Brain& rhs);
		virtual ~Brain();

	private:
		static const int	IDEAS_SIZE = 100;
		std::string			ideas_[IDEAS_SIZE];
};

#endif
