#pragma once
#include "ATarget.hpp"

class Dummy : public ATarget{
    private:
    public:
        Dummy();
        ~Dummy();
        virtual ATarget *clone() const;
};