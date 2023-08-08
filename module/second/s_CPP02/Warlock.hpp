#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>
#include "SpellBook.hpp"

class Warlock{
    private:
        std::string name;
        std::string title;

        SpellBook data;
        
        Warlock();
        Warlock(Warlock const & other);
        Warlock &operator=(Warlock const & other);
    public:
        Warlock(std::string const &name,std::string const &title);
        ~Warlock();

        std::string const & getName() const;
        std::string const & getTitle() const;

        void setTitle(std::string const &title);

        void introduce() const;

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string forget_spell);
        void launchSpell(std::string spell, ATarget const &ref);
};