#pragma once

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell{
    
    private:
        std::string name;
        std::string effects;
        

    public:
        ASpell();
        ASpell(std::string const &type);
        virtual ~ASpell();
        ASpell(ASpell const &other);
        ASpell &operator=(ASpell const &other);

        std::string const & getName() const;
        std::string const & getEffects() const;
        
        
        virtual ASpell *clone() const = 0;

        void launch(ATarget const & ref) const;
};