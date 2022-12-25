#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Wronganimal.hpp"
#include "Wrongcat.hpp"
/*int main()
{
    int i = 0;
    Animal *array[10];
    
    while(i < 10)
    {
        if (i % 2 == 0)
        {
            array[i] = new Cat;
        }
        else
        {
            array[i] = new Dog;
        }
        i++;
    }
    i = 0;
    while (i < 10)
    {
        std::cout << "idx : " << i << "  " ;
        array[i]->makesound();
        i++;
    }

    i = 0;
    while (i < 10)
    {
        delete array[i];
        i++;
    }

    return 0;
}
*/

int main()
{
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

    std::cout << std::endl;


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