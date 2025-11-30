#ifndef AMATERIA_HPP_
# define AMATERIA_HPP_

#include <string>
class ICharacter;

class AMateria
{
	public:
		AMateria(const std::string& type);
		AMateria(const AMateria& other);
		virtual ~AMateria();
		const std::string&	getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);

	protected:
		AMateria(void);
		AMateria&			operator=(const AMateria& rhs);
		virtual std::string	type_name(void) const = 0;
		virtual void		put_message(const std::string& name) const = 0;

	private:
		std::string	type_;
};

#endif
