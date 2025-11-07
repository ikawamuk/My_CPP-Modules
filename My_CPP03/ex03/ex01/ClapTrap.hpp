#ifndef CLAPTRAP_HPP_
# define CLAPTRAP_HPP_

# include <string>

static const char* const RESET  = "\x1b[0m";
static const char* const RED    = "\x1b[31m";
static const char* const GREEN  = "\x1b[32m";
static const char* const YELLOW = "\x1b[33m";
static const char* const BLUE   = "\x1b[34m";

class ClapTrap
{
	public:
		ClapTrap(const std::string& name = "John TraDefaulta", \
				unsigned int hit_points = 10, \
				unsigned int energy_points = 10, \
				unsigned int attack_damage = 0);
		ClapTrap(const ClapTrap& other);
		ClapTrap&	operator=(const ClapTrap& rhs);
		virtual ~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected:
		const std::string&	name(void);
		unsigned int					hit_points(void) const;
		unsigned int					energy_points(void) const;
		unsigned int					attack_damage(void) const;
		void				set_hit_points(unsigned int hit_points);
		void				set_energy_points(unsigned int energy_points);
		bool				can_take_action(void) const;

	private:
		std::string	name_;
		int			hit_points_;
		int			energy_points_;
		int			attack_damage_;
		
};

#endif
