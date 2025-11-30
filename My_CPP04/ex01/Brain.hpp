#ifndef BRAIN_HPP_
# define BRAIN_HPP_

#include <string>
#include "print_color.hpp"

class Brain
{
	public:
		Brain(const std::string& idea = "I have no idea");
		Brain(const Brain& other);
		Brain&				operator=(const Brain& rhs);
		const std::string&	operator[](std::size_t i) const;
		void				add_idea(const std::string& idea);
		const std::string	get_newst_idea(void) const;
		~Brain();

	private:
		enum {IDEAS_SIZE = 100};
		std::string	ideas_[IDEAS_SIZE];
		int			newest_idea_index;
};

#endif
