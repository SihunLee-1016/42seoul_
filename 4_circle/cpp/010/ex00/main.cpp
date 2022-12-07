#include "Zombie.hpp"
int main()
{
	Zombie zom1("A");
	Zombie* nzom = Zombie::newZombie("SSSS");

	zom1.announce();
	randomChump("ADADADA");

	delete nzom;
	return (0);
}