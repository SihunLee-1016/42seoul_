#pragma once

#include "ASpell.hpp"

//상속은 public으로 받아야함
class Fwoosh : public ASpell
{
    public:
        Fwoosh();
        ~Fwoosh();
        
        virtual ASpell *clone() const;
};