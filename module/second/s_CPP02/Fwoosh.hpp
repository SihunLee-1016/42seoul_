#pragma once
#include "ASpell.hpp"

class Fwoosh : public ASpell{
    private:
    public:
        Fwoosh();
        ~Fwoosh();
        virtual ASpell *clone() const;
};