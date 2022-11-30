#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Wronganimal.hpp"
#include "Wrongcat.hpp"

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
    std::cout << "get_type end" << std::endl;


    i->makesound(); //will output the cat sound!
    std::cout << std::endl;

    j->makesound();
    std::cout << std::endl;

    k->makesound();
    std::cout << std::endl;

    meta->makesound();
    std::cout << std::endl;


    std::cout << "end start" << std::endl<< std::endl;
    delete meta;
    std::cout << std::endl;

    delete i;
    std::cout << std::endl;

    delete j;
    std::cout << std::endl;

    delete k;
    std::cout << std::endl;

    std::cout << "end end" << std::endl<< std::endl;
    return 0;   
}