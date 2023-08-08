#include "Warlock.hpp"


Warlock::Warlock(std::string const &name,std::string const &title){
    this->name = name;
    this->title = title;
    std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
    std::cout << this->name << ": My job here is done!\n";
}

void Warlock::introduce() const
{
    std::cout << this->name << ": I am" << this->name << ", " << this->title << "!\n";
}

std::string const & Warlock::getName() const{return (this->name);}

std::string const & Warlock::getTitle() const{return (this->title);}

void Warlock::setTitle(std::string const &title){
    this->title = title;
}
        
void Warlock::learnSpell(ASpell *spell){
    ASpell *tmp = 0;
    if (tmp == spell)
        return;
    data.learnSpell(spell);
}

void Warlock::forgetSpell(std::string forget_spell){
    data.forgetSpell(forget_spell);
}

void Warlock::launchSpell(std::string spell, ATarget const &ref){
    ASpell *tmp = data.createSpell(spell);

    if(tmp)
        tmp->launch(ref);
}