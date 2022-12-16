#include "Zombie.hpp"
#include <sys/wait.h>

int main()
{
	int	num;
	int	i = 0;
	
	Zombie	*zombies;

	std::cout << "Input number : ";
	std::cin >> num;
	if (num <= 0 || std::cin.eof())
		return (0);

	zombies = zombieHorde(num, "zom");
	while (i < num)
	{
		zombies[i].announce();
		i++;
	}
	std::cout << std::endl;
	delete[] zombies;
	std::cout << "All zombies dead" << std::endl;
	return (0);
}
