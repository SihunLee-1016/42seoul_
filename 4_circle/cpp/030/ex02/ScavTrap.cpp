#include "ScavTrap.hpp"
ScavTrap::ScavTrap(void)
{
    this->Hit_points = 100;
    this->Energy_points = 50;
    this->attack_dmg = 20;
    std::cout << this->name << "ST : initialized" << std::endl;

}

ScavTrap::ScavTrap(std::string name)
{
    this->name = name;
    this->Hit_points = 100;
    this->Energy_points = 50;
    this->attack_dmg = 20;
    std::cout << this->name << "ST : initialized.w.name" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj)
{
    this->name = obj.name;
    this->Hit_points = obj.Hit_points;
    this->Energy_points = obj.Energy_points;
    this->attack_dmg = obj.attack_dmg;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
    this->name = obj.name;
    this->Hit_points = obj.Hit_points;
    this->Energy_points = obj.Energy_points;
    this->attack_dmg = obj.attack_dmg;
}

ScavTrap::~ScavTrap()
{
    std::cout << this->name << "ST : Destroied" << std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout << "ST : ScavTrap is now in Guard Gate mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
    if (this->Energy_points < 1)
    {
        std::cout << "ST :Attack : Run out of Energy point" << std::endl;
        return ;
    }
    this->takeDamge(1);
    std::cout << target << "ST : Attacked " << "// hit_p left : " << this->Hit_points << " // Energy left :" << this->Energy_points << std::endl;
}

void	ScavTrap::takeDamge(unsigned int amount)
{
    this->Hit_points -= amount;
    this->Energy_points--;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
    if (this->Energy_points < 1)
    {
        std::cout << "ST : Repair : Run out of Energy point" << std::endl;
        return ;
    }
    this->Hit_points += amount;
    this->Energy_points--;
    std::cout << "ST : Repaired // hit_p left : "<< this->Hit_points << " // Energy left :" << this->Energy_points << std::endl;
}

void    ScavTrap::status(void)
{
    std::cout << "Hp : " << this->Hit_points << "Ep : " << this->Energy_points << std::endl;
}