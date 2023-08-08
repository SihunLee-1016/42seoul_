#include "SpellBook.hpp"

SpellBook::~SpellBook()
{
    std::map<std::string, ASpell *>::iterator it_begin = data.begin();
    std::map<std::string, ASpell *>::iterator it_end = data.end();

    while (it_begin != it_end)
    {
        delete it_begin->second;
        ++it_begin;
    }
    data.clear();
}

void SpellBook::learnSpell(ASpell *spell){
    if(spell)
        data.insert(std::pair<std::string, ASpell *>(spell->getName(),spell->clone()));
}

void SpellBook::forgetSpell(std::string const &forget_spell){
    std::map<std::string, ASpell *>::iterator it = data.find(forget_spell);

    if (it != data.end())
        delete it->second;
    data.erase(forget_spell);
}

ASpell* SpellBook::createSpell(std::string const &spell){
    std::map<std::string, ASpell *>::iterator it = data.find(spell);

    if (it != data.end())
        return data[spell];
    return NULL;
}