#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& obj);
        ScavTrap& operator=(const ScavTrap& obj);
        ~ScavTrap();
        void    guardGate();
        void	attack(const std::string& target);
        void	beRepaired(unsigned int amount);
};
#endif