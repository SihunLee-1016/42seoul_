#include <iostream>
#include <string.h>
#include <iomanip>

class new_Zombie
{
    private :
        std::string    *name;
    public :
        ~new_Zombie()
        {
            std::cout << *(this->name);
            delete name;
            std::cout <<"  Destroyed" << std::endl;
        }
        void    announce(void);
        new_Zombie* newZombie( std::string name);
        void randomChump( std::string name );
};