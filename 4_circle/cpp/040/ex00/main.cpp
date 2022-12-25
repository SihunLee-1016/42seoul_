#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Wronganimal.hpp"
#include "Wrongcat.hpp"
// #include <sys/wait.h>
int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const Wronganimal* k = new Wrongcat();

    std::cout << "get_type" << std::endl;
    std::cout << j->gettype() << " " << std::endl;
    std::cout << i->gettype() << " " << std::endl;
    std::cout << k->gettype() << " " << std::endl;


    i->makesound(); //will output the cat sound!
    std::cout << std::endl;

    j->makesound();
    std::cout << std::endl;

    k->makesound();
    std::cout << std::endl;

    meta->makesound();
    std::cout << std::endl;


    delete meta;
    std::cout << std::endl;

    delete i;
    std::cout << std::endl;

    delete j;
    std::cout << std::endl;

    delete k;

    std::cout << "end end" << std::endl<< std::endl;

    // system("leaks ex00");
    return 0;   
}