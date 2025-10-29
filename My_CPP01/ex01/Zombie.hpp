#ifndef ZOMBIE_HPP_
# define ZOMBIE_HPP_

# include <string>

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);
		void	announce(void) const;
		void	set_name(std::string name);

	private:
		std::string	name;
};

#endif