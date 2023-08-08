#include <iostream>
#include "ASpell.hpp"
#include <map>

class SpellBook{
    private:
        SpellBook(SpellBook const &other);
        SpellBook &operator=(SpellBook const &other);

        std::map<std::string, ASpell *> data;
    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string const &forget_spell);
        ASpell* createSpell(std::string const &spell);
};