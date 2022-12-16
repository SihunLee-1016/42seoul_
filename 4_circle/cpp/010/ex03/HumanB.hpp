#ifndef HUMANB_HPP
# define HUMANB_HPP
#include "Weapon.hpp"
class HumanB
{
	private:
		std::string _name;
		Weapon *B_w;
	public:
		HumanB(std::string name);
		void        attack(void);
		void        setWeapon(Weapon *w_type);
};
#endif