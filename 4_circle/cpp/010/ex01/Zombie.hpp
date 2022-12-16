#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
class Zombie
{
	private :
		std::string    *name;
	public :
		~Zombie();
		void    announce(void);
		void    makeZombie( std::string name);
		void	randomChump( std::string name );
};

Zombie* zombieHorde(int N, std::string name);