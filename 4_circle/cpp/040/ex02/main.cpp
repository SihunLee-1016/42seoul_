#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Wronganimal.hpp"
#include "Wrongcat.hpp"
int main()
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