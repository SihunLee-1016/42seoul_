#include "Animal.hpp"
class Dog : public Animal
{
    private:
    public:
        Dog();
        Dog(const Dog &obj);
        Dog& operator=(const Dog &obj);
        ~Dog();
        void    makesound(void);

};

Dog::Dog()
{
    std::cout << "Dog constructor activated" << std::endl;
}

Dog::Dog(const Dog &obj)
{
    std::cout << "Dog constructor2 activated" << std::endl;
}

Dog& operator=(const Dog &obj)
{
    std::cout << "Dog operator activated" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor activated" << std::endl;
}

void    Dog::makesound(void)
{
    std::cout << "Bark" << std::endl;   
}