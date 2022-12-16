#include "Zombie.hpp"
Zombie* zombieHorde(int N, std::string name )
{
	int i = 0;
	std::string str[10]= {"1","2","3","4","5","6","7","8","9","10"};

	if (N <= 0)
		return (NULL);
	Zombie	*zom_hord;

	zom_hord = new Zombie[N];

	while (i < N)
	{
		name.append(str[i]);
		zom_hord[i].makeZombie(name);
		name.resize(3);
		i++;
	}
	return (zom_hord);
}
