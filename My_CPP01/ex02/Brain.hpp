#ifndef BRAIN_HPP_
# define BRAIN_HPP_

# include <string>

class Brain
{
	public:
		Brain(std::string str = "HI THIS IS BRAIN");
		void	print_memory(void) const;
		void	print_value(void) const;

	private:
		std::string		string;
		std::string*	stringPTR;
		std::string&	stringREF;
};

#endif