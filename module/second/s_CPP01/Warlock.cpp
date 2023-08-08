#include "Warlock.hpp"


Warlock::Warlock(std::string const &name,std::string const &title){
    this->name = name;
    this->title = title;
    std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
    std::map<std::string, ASpell*>::iterator it_begin = data.begin();
    std::map<std::string, ASpell*>::iterator it_end = data.end();

    while (it_begin != it_end)
    {
        delete it_begin->second;
        ++it_begin;
    }
    data.clear();
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
    
    if (spell)
        data.insert(std::pair<std::string, ASpell*>(spell->getName(),spell->clone()));
}

void Warlock::forgetSpell(std::string forget_spell){
    std::map<std::string, ASpell*>::iterator it = data.find(forget_spell);
    if (it != data.end())
        delete it->second;
    data.erase(forget_spell);
}

void Warlock::launchSpell(std::string spell, ATarget const &ref){
    ASpell *tmp = data[spell];

    if(tmp)
        tmp->launch(ref);
}