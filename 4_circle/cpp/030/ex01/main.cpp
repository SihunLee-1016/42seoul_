#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
    ClapTrap a("Tom");
    ScavTrap c("SCAV");

    std::cout << std::endl;
    std::cout << std::endl;

    a.attack("TOM");
    a.attack("TOM");
    a.attack("TOM");

    std::cout << std::endl;
    std::cout << std::endl;

    c.guardGate();

    c.attack("TOM");
    c.beRepaired(5);
    c.attack("TOM");
    c.attack("TOM");
    c.attack("TOM");
    c.attack("TOM");
    c.attack("TOM");
    std::cout << std::endl;
    std::cout << std::endl;
    c.attack("TOM");
    c.attack("TOM");
    c.ClapTrap::status();
    std::cout << std::endl;
    std::cout << std::endl;
    c.guardGate();
}