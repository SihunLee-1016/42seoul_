#include"ClapTrap.hpp"

ClapTrap::ClapTrap(std::string str)
{
    this->name = str;
    this->Hit_points = 10;
	this->Energy_points = 10;
	this->Attak_dmg = 1;
    std::cout << this->name << "initialized" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << this->name << "Destroied" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
    if (this->Energy_points < 1)
    {
        std::cout << "Attack : Run out of Energy point" << std::endl;
        return ;
    }
    this->takeDamge(1);
    std::cout << target << " Attacked " << "// hit_p left : " << this->Hit_points << " // Energy left :" << this->Energy_points << std::endl;
}

void	ClapTrap::takeDamge(unsigned int amount)
{
    this->Hit_points -= amount;
    this->Energy_points--;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
    if (this->Energy_points < 1)
    {
        std::cout << "Repair : Run out of Energy point" << std::endl;
        return ;
    }
    this->Hit_points += amount;
    this->Energy_points--;
    std::cout << "Repaired // hit_p left : "<< this->Hit_points << " // Energy left :" << this->Energy_points << std::endl;
}

void    ClapTrap::status(void)
{
    std::cout << "Hp : " << this->Hit_points << "Ep : " << this->Energy_points << std::endl;

}