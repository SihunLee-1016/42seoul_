#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"
class Cat : public Animal
{
    private:
        Brain *_brain;
    public:
        Cat();
        Cat(const Cat &obj);
        ~Cat();
        Cat& operator=(const Cat &obj);
        virtual void    makesound() const;
        virtual std::string    gettype()const;
        Brain *get_brain() const;
        void    check_brain();
    
};

#endif