#include "FragTrap.hpp"
FragTrap::FragTrap(void)
{
    this->Hit_points = 100;
    this->Energy_points = 100;
    this->attack_dmg = 30;
    std::cout << this->name << " FT : initialized" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    this->name = name;
    this->Hit_points = 100;
    this->Energy_points = 100;
    this->attack_dmg = 30;
    std::cout << this->name << " FT : initialized.w.name" << std::endl;
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
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << this->name << " FT : Destroied" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    if (this->Energy_points == 0)
    {
        std::cout << this->name << " FT : HighFive failed | NO ENERGT POINT" << std::endl;
        return ;
    }
    std::cout << this->name << " FT : HighFive Guys!" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
    if (this->Energy_points < 1)
    {
        std::cout << this->name << " FT : Attack : Run out of Energy point" << std::endl;
        return ;
    }
    if (this->Hit_points == 0)
    {
        std::cout << this->name << " Attack : Hp is under 0" << std::endl;
        return ;
    }
    this->takeDamge(this->attack_dmg);
    std::cout << target << " FT : Attacked " << "// hit_p left : " << this->Hit_points << " // Energy left :" << this->Energy_points << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
    if (this->Energy_points < 1)
    {
        std::cout << this->name << " FT : Repair : Run out of Energy point" << std::endl;
        return ;
    }
    this->Hit_points += amount;
    this->Energy_points--;
    std::cout << this->name << " FT : Repaired // hit_p left : "<< this->Hit_points << " // Energy left :" << this->Energy_points << std::endl;
}
