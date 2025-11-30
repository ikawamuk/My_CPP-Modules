#ifndef CHARACTER_HPP_
# define CHARACTER_HPP_

#include "ICharacter.hpp"
#include "Floor.hpp"

class Character: public ICharacter
{
	public:
		explicit Character(const std::string& name);
		Character(const Character& other);
		Character&	operator=(const Character& rhs);
		~Character();
		const std::string&	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);

	private:
		std::string			name_;
		static const int	SLOT_SIZE = 4;
		AMateria			*inventory_[SLOT_SIZE];
		static Floor		floor;
		Character(void);
		void	delete_inventory(void);
		void	copy_inventory(const Character& src);
};

#endif
