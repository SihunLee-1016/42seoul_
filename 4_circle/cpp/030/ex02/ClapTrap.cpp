#include"ClapTrap.hpp"
ClapTrap::ClapTrap(void)
{
    this->Hit_points = 10;
    this->Energy_points = 10;
    this->attack_dmg = 0;
    std::cout << this->name << " CT : initialized" << std::endl;
}
ClapTrap::ClapTrap(std::string str)
{
    this->name = str;
    this->Hit_points = 10;
	this->Energy_points = 10;
	this->attack_dmg = 0;
    std::cout << this->name << " CT : initialized.w.name" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
    this->name = obj.name;
    this->Hit_points = obj.Hit_points;
    this->Energy_points = obj.Energy_points;
    this->attack_dmg = obj.attack_dmg;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &obj)
{
    this->name = obj.name;
    this->Hit_points = obj.Hit_points;
    this->Energy_points = obj.Energy_points;
    this->attack_dmg = obj.attack_dmg;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << this->name << " CT : Destroied" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
    if (this->Energy_points < 1)
    {
        std::cout << this->name << " CT : Attack : Run out of Energy point" << std::endl;
        return ;
    }
    if (this->Hit_points == 0)
    {
        std::cout << this->name << " CT : Attack : Hp is under 0" << std::endl;
        return ;
    }
    this->takeDamge(this->attack_dmg);
    std::cout << target << " CT : Attacked " << "// hit_p left : " << this->Hit_points << " // Energy left :" << this->Energy_points << std::endl;
}

void	ClapTrap::takeDamge(unsigned int amount)
{
    if (this->Hit_points < this->attack_dmg )
    {
        this->Hit_points = 0;
        this->Energy_points = 0;
        return ;
    }
    this->Hit_points -= amount;
    this->Energy_points--;

}

void	ClapTrap::beRepaired(unsigned int amount)
{
    if (this->Energy_points < 1)
    {
        std::cout << this->name << " CT : Repair : Run out of Energy point" << std::endl;
        return ;
    }
    this->Hit_points += amount;
    this->Energy_points--;
    std::cout << this->name << " CT : Repaired // hit_p left : "<< this->Hit_points << " // Energy left :" << this->Energy_points << std::endl;
}

void    ClapTrap::status(void)
{
    std::cout << this->name << " Hp> : " << this->Hit_points << " Ep> : " << this->Energy_points << std::endl;

}