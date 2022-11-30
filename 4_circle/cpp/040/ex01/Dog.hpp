#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal
{
    private:
        Brain dog_brain;
    public:
        Dog();
        Dog(const Dog &obj);
        Dog& operator=(const Dog &obj);
        ~Dog();
        virtual void    makesound(void) const;
        virtual std::string    gettype() const;
        void    make_brain(void);
};

#endif