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

int main()
{
	int	num;
	int	i = 0;
	
	Zombie	*zombies;

	std::cout << "Input number : ";
	std::cin >> num;
	if (num <= 0)
		return (0);

	zombies = zombieHorde(num, "zoooommmm");
	while (i < num)
	{
		zombies[i].announce();
		i++;
	}
	delete[] zombies;
	std::cout << "All zombies dead" << std::endl;
	return (0);
}
