#include "ClapTrap.hpp"
class FragTrap : public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap& obj);
        FragTrap& operator=(const FragTrap& obj);
        ~FragTrap();
        void    highFivesGuys(void);
        void	attack(const std::string& target);
        void	takeDamge(unsigned int amount);
        void	beRepaired(unsigned int amount);
        void    status(void);

};