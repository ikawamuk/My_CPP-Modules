#ifndef WEAPON_HPP_
# define WEAPON_HPP_

# include <string>

class Weapon
{
	public:
		Weapon(std::string str);
		const std::string&	getType(void) const;
		void				setType(std::string newType);

	private:
		Weapon(void);

		std::string	type;
};

#endif