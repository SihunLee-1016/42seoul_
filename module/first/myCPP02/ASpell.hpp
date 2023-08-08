#pragma once
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell{
    private:
        std::string name;
        std::string effects;

    public:
        std::string const & getName() const;
        std::string const & getEffects() const;

        //순수가상함수도 const가 붙어야함
        virtual ASpell *clone() const = 0;

        ASpell();
        ASpell(std::string const &name, std::string const &effects);
        ASpell &operator=(ASpell const &other);
        ASpell (ASpell const &other);
        //소멸자에 버츄얼.
        virtual ~ASpell();

        void launch(ATarget const &atarget_ref) const;
};

