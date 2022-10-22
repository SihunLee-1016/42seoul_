#include "Zombie.hpp"
#include "newZombie.hpp"
int main()
{
    Zombie zom1;
    Zombie zom2;
    Zombie zom3;

    zom1.announce();
    zom2.announce();
    zom3.announce();

    new_Zombie zom4;
    new_Zombie zom5;
    new_Zombie zom6;

    zom4.newZombie("AA");
    zom5.newZombie("BB");
    zom6.newZombie("CC");

    zom4.announce();
    zom5.announce();
    zom6.announce();


    new_Zombie zom7;
    new_Zombie zom8;
    new_Zombie zom9;

    zom7.randomChump("DD");
    zom8.randomChump("EE");
    zom9.randomChump("FF");
}