#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal
{
    private:
        Brain *_brain;
    public:
        Dog();
        Dog(const Dog &obj);
        ~Dog();
        Dog& operator=(const Dog &obj);
        virtual void    makesound(void) const;
        virtual std::string    gettype() const;
        Brain *getBrain() const;
};

#endif