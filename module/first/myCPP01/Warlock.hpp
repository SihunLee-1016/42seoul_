#pragma once
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class Warlock{
    private:
        std::string name;
        std::string title;

        std::map<std::string, ASpell *> data;

        Warlock();
        Warlock &operator=(Warlock const &other);
        Warlock(Warlock const &other);
    public:
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();
        
        std::string const &getName() const;
        std::string const &getTitle() const;

        void setTitle(std::string const &title);
        void introduce() const;

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string spellname);
        void launchSpell(std::string spell_name, ATarget const & atarget_ref);

};