#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int main()
{
    ClapTrap a("Tom");
    FragTrap b("Steve");

    b.highFivesGuys();

    std::cout << std::endl;
    std::cout << std::endl;


    b.attack("TOM");
    b.beRepaired(5);
    b.attack("TOM");
    b.attack("TOM");
    b.attack("TOM");
    b.attack("TOM");
    b.attack("TOM");
    std::cout << std::endl;
    std::cout << std::endl;
    b.highFivesGuys();
    b.status();
    std::cout << std::endl;
    std::cout << std::endl;

}