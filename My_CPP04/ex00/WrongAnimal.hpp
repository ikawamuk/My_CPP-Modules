#ifndef WRONGWrongAnimal_HPP_
# define WRONGWrongAnimal_HPP_

#include <string>

class WrongAnimal
{
	public:
		WrongAnimal(const std::string& type = "WrongAnimal");
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal&	operator=(const WrongAnimal& rhs);
		virtual ~WrongAnimal();
		void	makeSound(void) const;
		const std::string&	getType(void) const;

	protected:
		std::string	type_;
};

#endif
