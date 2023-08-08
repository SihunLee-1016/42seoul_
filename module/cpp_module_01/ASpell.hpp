#pragma once

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
    private:
        std::string name;
        std::string effects;

    public:
        ASpell();
        ASpell(std::string const &name, std::string const &effects);
        ASpell(ASpell const &other);
        ASpell &operator=(ASpell const &other);
        virtual ~ASpell();

        std::string const &getName() const;
        std::string const &getEffects() const;

        void launch(ATarget const &atarget_ref) const;

        virtual ASpell *clone() const = 0;
};

// class ATarget;

// class ASpell{
//     private:
//         std::string name;
//         std::string effects;
//     public:
//         ASpell();
//         virtual ~ASpell();
//         ASpell(std::string const &name, std::string const &effects);
//         ASpell(ASpell const &other);
//         ASpell &operator=(ASpell cosnt &other);

//         std::string const &getName() const;
//         std::string const &getEffect() const;

//         void launch(ATarget const &atarget_ref) const;

//         virtual ATarget *clone() = 0;
// };