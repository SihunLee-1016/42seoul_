#include <iostream>
#include "ATarget.hpp"
#include <map>

class TargetGenerator{
    private:
        TargetGenerator();
        TargetGenerator(TargetGenerator const &other);
        TargetGenerator &operator=(TargetGenerator const &other);

        std::map<std::string, ATarget *> data;
    public:
        ~TargetGenerator();

        void learnTargetType(ATarget *spell);
        void forgetTargetType(std::string const &forget_spell);
        ATarget* createTarget(std::string const &spell);
};