#pragma once
#include "ATarget.hpp"

//상속은 public으로 받아야함
class Dummy : public ATarget
{
    private:
    public:
        Dummy();
        ~Dummy();
        
        //virtual 붙혀야함.
        virtual ATarget *clone() const;
};