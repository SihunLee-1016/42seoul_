#include "Weapon.hpp"
class HumanB
{
	private:
		std::string _name;
		std::string _weapon_type;
	public:
		HumanB(std::string name);
		void        attack(void);
		void        setWeapon(Weapon w_type);
};
