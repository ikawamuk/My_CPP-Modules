#ifndef WRONGANIMAL_HPP_
# define WRONGANIMAL_HPP_

#include <string>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal&	operator=(const WrongAnimal& rhs);
		~WrongAnimal();
		void	makeSound(void) const;
		std::string		getType(void) const;

	protected:
		WrongAnimal(const std::string& type);

	private:
		std::string	type_;
		
};

#endif
