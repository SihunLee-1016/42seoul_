#include "Animal.hpp"
class Cat : public Animal
{
    private:
        /* data */
    public:
        Cat();
        Cat(const Cat &obj);
        ~Cat();
        Cat& operator=(const Cat &obj);
        void    makesound(void);

};

Cat::Cat()
{
    std::cout << "Cat constructor activated" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor activated" << std::endl;
}

void    Cat::makesound(void)
{
    std::cout << "Meow" << std::endl;
}