#ifndef BRAIN_HPP
# define BRAIN_HPP
#include "Animal.hpp"
class Brain
{

    private:
        std::string ideas[100];
    public:
        Brain(/* args */);
        ~Brain();
};

Brain::Brain()
{
    ideas = new std::sting[100];
}

Brain::~Brain()
{
}

#endif