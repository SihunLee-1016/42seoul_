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
        virtual void    makesound(void) const;
        virtual std::string gettype() const;
        virtual void    check_brain();

};

#endif