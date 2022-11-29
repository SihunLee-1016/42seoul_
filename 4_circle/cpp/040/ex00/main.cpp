#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->gettype() << " " << std::endl;
    std::cout << i->gettype() << " " << std::endl;
    
    i->makesound(); //will output the cat sound!
    j->makesound();
    meta->makesound();
    
    return 0;   
}