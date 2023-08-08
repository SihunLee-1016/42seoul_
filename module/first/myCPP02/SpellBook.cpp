#include "SpellBook.hpp"
#include <string>
#include <utility>


SpellBook::SpellBook(){}

SpellBook::~SpellBook(){
    std::map<std::string, ASpell *>::iterator it_b = data.begin();
    std::map<std::string, ASpell *>::iterator it_e = data.end();
    while (it_b != it_e)
    {
        delete it_b->second;
        ++it_b;
    }
    data.clear();
}

void SpellBook::learnSpell(ASpell* spell){
    if(spell)
        data.insert(std::pair<std::string, ASpell *>(spell->getName(),spell->clone()));
}

void SpellBook::forgetSpell(std::string const &forget){
    std::map<std::string, ASpell*>::iterator it = data.find(forget);
    if (it != data.end())
        delete it->second;
    data.erase(forget);
}

ASpell * SpellBook::createSpell(std::string const &spell){
    std::map<std::string, ASpell*>::iterator it = data.find(spell);
    if (it != data.end())
        return data[spell];
    return NULL;
}