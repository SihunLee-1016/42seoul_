#ifndef ANIMAL_HPP
#define ANIMAL_HPP
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
        virtual ~Animal();
        virtual Animal& operator=(const Animal &obj);
        virtual void    makesound(void) const = 0;
        virtual std::string gettype() const;
};

#endif