#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
class Cat : public Animal
{
    private:
    public:
        Cat();
        Cat(const Cat &obj);
        ~Cat();
        Cat& operator=(const Cat &obj);
        virtual void    makesound(void) const;
        virtual std::string    gettype()const;
};

#endif