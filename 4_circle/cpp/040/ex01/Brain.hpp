#ifndef BRAIN_HPP
# define BRAIN_HPP
#include "Animal.hpp"
class Brain
{
    private:
        std::string *ideas;
    public:
        Brain();
        ~Brain();
        Brain(const Brain & obj);
        Brain& operator=(const Brain &obj);
};

#endif