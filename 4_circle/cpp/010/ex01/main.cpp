#include "Zombie.hpp"


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
