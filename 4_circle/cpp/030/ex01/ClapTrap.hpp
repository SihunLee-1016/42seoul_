#include <iostream>
#include <string.h>

class ClapTrap
{
	private:
	std::string	name;
	int	Hit_points;
	unsigned int	Energy_points;
	unsigned int	Attak_dmg;

		
	public:
		ClapTrap(std::string str);
		ClapTrap(int hp, int ep, int dmg);
		~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamge(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	status(void);
};