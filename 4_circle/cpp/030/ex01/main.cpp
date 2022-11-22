#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
    ClapTrap a("Tom");
    ClapTrap b("Bob");

    a.attack("Tom");
    a.attack("Tom");
    a.attack("Tom");
    a.attack("Tom");
    a.attack("Tom");
    a.attack("Tom");
    a.attack("Tom");
    a.attack("Tom");
    a.attack("Tom");
    a.attack("Tom");
    a.attack("Tom");
    a.beRepaired(1);
    a.status();
}