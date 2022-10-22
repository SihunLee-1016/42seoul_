#include <iostream>
#include <string.h>
#include <iomanip>

class Zombie
{
    public :
        ~Zombie()
        {
            std::cout <<"Destroyed" << std::endl;
        }
        void    announce(void);
};