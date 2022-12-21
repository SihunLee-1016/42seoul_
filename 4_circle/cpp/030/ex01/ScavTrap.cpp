#include "ScavTrap.hpp"
ScavTrap::ScavTrap(void)
{
    this->Hit_points = 100;
    this->Energy_points = 50;
    this->attack_dmg = 20;
    std::cout << this->name << " ST : initialized" << std::endl;

}

ScavTrap::ScavTrap(std::string name)
{
    this->name = name;
    this->Hit_points = 100;
    this->Energy_points = 50;
    this->attack_dmg = 20;
    std::cout << this->name << " ST : initialized.w.name" << std::endl;
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
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << this->name << " ST : Destroied" << std::endl;
}

void    ScavTrap::guardGate()
{
    if (this->Energy_points == 0)
    {
        std::cout << this->name << " ST : Guard : Run out of Energy point" << std::endl;
        return ;
    }
    std::cout << this->name << " ST : ScavTrap is now in Guard Gate mode" << std::endl;
    this->Energy_points--;
}

void	ScavTrap::attack(const std::string& target)
{
    if (this->Energy_points < 1)
    {
        std::cout << this->name << " ST :Attack : Run out of Energy point" << std::endl;
        return ;
    }
    if (this->Hit_points == 0)
    {
        std::cout << this->name << " Attack : Hp is under 0" << std::endl;
        return ;
    }
    this->takeDamge(this->attack_dmg);
    std::cout << target << " ST : Attacked " << "// hit_p left : " << this->Hit_points << " // Energy left :" << this->Energy_points << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
    if (this->Energy_points < 1)
    {
        std::cout << this->name << " ST : Repair : Run out of Energy point" << std::endl;
        return ;
    }
    this->Hit_points += amount;
    this->Energy_points--;
    std::cout << this->name << " ST : Repaired // hit_p left : "<< this->Hit_points << " // Energy left :" << this->Energy_points << std::endl;
}
