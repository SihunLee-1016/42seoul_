#include "FragTrap.hpp"
FragTrap::FragTrap(void)
{
    this->Hit_points = 100;
    this->Energy_points = 100;
    this->attack_dmg = 30;
    std::cout << this->name << "FT : initialized" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    this->name = name;
    this->Hit_points = 100;
    this->Energy_points = 100;
    this->attack_dmg = 30;
    std::cout << this->name << "FT : initialized.w.name" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj)
{
    this->name = obj.name;
    this->Hit_points = obj.Hit_points;
    this->Energy_points = obj.Energy_points;
    this->attack_dmg = obj.attack_dmg;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
    this->name = obj.name;
    this->Hit_points = obj.Hit_points;
    this->Energy_points = obj.Energy_points;
    this->attack_dmg = obj.attack_dmg;
}

FragTrap::~FragTrap()
{
    std::cout << this->name << "FT : Destroied" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FT : HighFive Guys!" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
    if (this->Energy_points < 1)
    {
        std::cout << "FT :Attack : Run out of Energy point" << std::endl;
        return ;
    }
    this->takeDamge(1);
    std::cout << target << "FT : Attacked " << "// hit_p left : " << this->Hit_points << " // Energy left :" << this->Energy_points << std::endl;
}

void	FragTrap::takeDamge(unsigned int amount)
{
    this->Hit_points -= amount;
    this->Energy_points--;
}

void	FragTrap::beRepaired(unsigned int amount)
{
    if (this->Energy_points < 1)
    {
        std::cout << "FT : Repair : Run out of Energy point" << std::endl;
        return ;
    }
    this->Hit_points += amount;
    this->Energy_points--;
    std::cout << "FT : Repaired // hit_p left : "<< this->Hit_points << " // Energy left :" << this->Energy_points << std::endl;
}

void    FragTrap::status(void)
{
    std::cout << "Hp : " << this->Hit_points << "Ep : " << this->Energy_points << std::endl;
}