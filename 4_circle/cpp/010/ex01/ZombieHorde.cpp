#include "Zombie.hpp"
Zombie* zombieHorde(int N, std::string name )
{
	int i = 0;

	if (N <= 0)
		return (NULL);
	Zombie	*zom_hord;

	zom_hord = new Zombie[N];

	while (i < N)
	{
		zom_hord[i].makeZombie(name);
		i++;
	}
	return (zom_hord);
}
