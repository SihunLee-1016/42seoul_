#pragma once

#include "ASpell.hpp"

//상속은 public으로 받아야함
class Polymorph : public ASpell
{
    public:
        Polymorph();
        ~Polymorph();
        
        virtual ASpell *clone() const;
};