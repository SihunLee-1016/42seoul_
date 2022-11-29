#include <iostream>
#include <string>
class Animal
{
    protected :
        std::string type;
    private:
    public:
        Animal();
        Animal(const Animal &obj);
        ~Animal();
        Animal& operator=(const Animal &obj);
        virtual void    makesound(void);
        std::string    gettype();
};

Animal::Animal(/* args */)
{
    this->type = 0;
}

Animal::~Animal()
{
}

virtual void    Animal::makesound(void)
{
    std::cout << "From Animal class" << std::endl;
}

std::string Animal::gettype()
{
    return (this->type);
}