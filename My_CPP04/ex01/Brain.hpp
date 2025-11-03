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
	
	public:
		const std::string	(&ideas(void) const)[IDEAS_SIZE];
		void				set_ideas(const std::string* ideas);
		void				set_an_idea(const std::string idea, int index);
};

#endif
