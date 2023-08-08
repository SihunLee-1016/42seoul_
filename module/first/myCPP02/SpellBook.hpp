#pragma once

#include "ASpell.hpp"
#include <map>
class SpellBook{
    private:
        SpellBook &operator=(SpellBook const &other);
        SpellBook (SpellBook const &other);

        std::map<std::string, ASpell *> data;
    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell* spell);
        void forgetSpell(std::string const &forget);
        ASpell * createSpell(std::string const &spell);


};
