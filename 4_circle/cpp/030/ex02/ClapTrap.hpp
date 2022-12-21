#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <iostream>
#include <string.h>

class ClapTrap
{
	protected:
	std::string	name;
	unsigned int	Hit_points;
	unsigned int	Energy_points;
	unsigned int	attack_dmg;

		
	public:
		ClapTrap(void);
		ClapTrap(std::string str);
		ClapTrap(const ClapTrap& obj);
		ClapTrap &operator=(const ClapTrap &obj);
		~ClapTrap();
		virtual void	attack(const std::string& target);
		virtual void	takeDamge(unsigned int amount);
		virtual void	beRepaired(unsigned int amount);
		virtual void	status(void);
};
#endif