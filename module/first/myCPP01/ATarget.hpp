#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget{
    private:
        std::string type;

    public:
        std::string const & gettype() const;

        //순수가상함수도 const가 붙어야함
        virtual ATarget *clone() const = 0 ;

        ATarget();
        ATarget(std::string const &type);
        ATarget &operator=(ATarget const &other);
        ATarget (ATarget const &other);
        //소멸자도 버츄얼 키워드 붙히기.
        ~ATarget();

        void getHitBySpell(ASpell const &aspell_ref) const;
};