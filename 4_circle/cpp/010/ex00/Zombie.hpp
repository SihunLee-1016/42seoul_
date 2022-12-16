#include <iostream>
#include <string>
#include <iomanip>

class Zombie
{
    private:
        std::string name;
    public :
        Zombie(std::string str);
        ~Zombie();
        void    announce(void);
        static Zombie *newZombie(std::string str);
};

void randomChump(std::string str);