#pragma once

#include <iostream>

class ASpell;

class ATarget
{
    private:
        std::string type;
    
    public:
        ATarget();
        ATarget(std::string const &type);
        ATarget(ATarget const &other);
        ATarget &operator=(ATarget const &other);
        virtual ~ATarget();

        void getHitBySpell(ASpell const &aspell_ref) const;
        
        std::string const &getType() const;

        virtual ATarget *clone() const = 0;
};

#include "ASpell.hpp"