#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int main()
{
    ClapTrap a("Tom");
    FragTrap b("Steve");

    b.highFivesGuys();


    b.attack("Steve");
    b.attack("Steve");
    b.attack("Steve");
    b.attack("Steve");
    b.attack("Steve");
    b.beRepaired(5);

}