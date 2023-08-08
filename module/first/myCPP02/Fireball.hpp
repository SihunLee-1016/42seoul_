#pragma once

#include "ASpell.hpp"

//상속은 public으로 받아야함
class Fireball : public ASpell
{
    public:
        Fireball();
        ~Fireball();
        
        virtual ASpell *clone() const;
};