#ifndef AANIMAL_HPP_
# define AANIMAL_HPP_

#include <string>

class AAnimal
{
	public:
		AAnimal(const std::string& type = "AAnimal");
		AAnimal(const AAnimal& other);
		AAnimal&	operator=(const AAnimal& rhs);
		virtual ~AAnimal();
		virtual void	makeSound(void) const = 0;
		const std::string&	getType(void) const;

	protected:
		std::string	type_;
};

#endif
