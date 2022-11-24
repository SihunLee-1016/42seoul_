#include <iostream>
#include <string.h>

class ClapTrap
{
	private:
	std::string	name;
	int	Hit_points;
	unsigned int	Energy_points;
	unsigned int	attack_dmg;

		
	public:
		ClapTrap(void);
		ClapTrap(std::string str);
		ClapTrap (const ClapTrap &obj);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &obj);
		void	attack(const std::string& target);
		void	takeDamge(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	status(void);
};