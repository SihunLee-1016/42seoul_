#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string	weapon;
	public:
		Weapon(std::string weapon_name);
		std::string getType(void);
		void    	setType(std::string weapon_name);
};
#endif