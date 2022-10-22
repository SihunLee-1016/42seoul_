#include "Weapon.hpp"
class HumanA
{
    private:
        std::string _name;
        std::string _weapon_type;
    public:
        HumanA(std::string name, Weapon& type);
        void        attack(void);
};
