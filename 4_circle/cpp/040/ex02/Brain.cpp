#include "Brain.hpp"
Brain::Brain()
{
    std::cout << "in brain constructor, dynamic allocate activated" << std::endl;
    ideas = new std::string[100];
    for (int i = 0; i < 100 ; i++)
    {
        ideas[i] = "h";
    }
}

Brain::~Brain()
{

    std::cout << "in brain Destructor, dynamic allocate activated" << std::endl;
    delete[] ideas;
}
