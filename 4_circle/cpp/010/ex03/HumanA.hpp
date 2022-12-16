#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
class HumanA
{
    private:
        std::string _name;
        Weapon &A_w;
    public:
        HumanA(std::string name, Weapon& type);
        void        attack(void);
};

#endif