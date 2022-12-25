#include "Brain.hpp"
Brain::Brain() {
    std::cout << "in brain constructor, dynamic allocate activated" << std::endl;
    ideas = new std::string[100];
    for (int i = 0; i < 100 ; i++)
    {
        ideas[i] = "h";
    }
}

Brain::~Brain(){

    std::cout << "in brain Destructor, dynamic allocate activated" << std::endl;
    delete[] ideas;
}

Brain::Brain(const Brain& b) {
    std::cout << "in brain copy constructor, dynamic allocate activated" << std::endl;
    
    for (int i = 0 ; i < 100 ; ++i)
        ideas[i] = b.getIdea(i);
}

std::string Brain::getIdea(const int& i) const {
  return ideas[i];
}

Brain& Brain::operator=(const Brain &obj){
    for (int i = 0 ; i < 100 ; ++i)
      ideas[i] = obj.getIdea(i);
    return *this;
}

void Brain::setIdea(const int& i, const std::string& idea) {
  ideas[i] = idea;
}