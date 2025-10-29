#ifndef ZOMBIE_HPP_
# define ZOMBIE_HPP_

# include <string>

class Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void) const;

	private:
		Zombie(void);

		std::string	name;
};

#endif