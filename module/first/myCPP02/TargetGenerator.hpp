#pragma once

#include "ATarget.hpp"
#include <map>

class TargetGenerator{
    private:
        TargetGenerator &operator=(TargetGenerator const &other);
        TargetGenerator (TargetGenerator const &other);

        std::map<std::string, ATarget *> data;
    public:
        TargetGenerator();
        ~TargetGenerator();

        
        void learnTargetType(ATarget* target);
        
        void forgetTargetType(std::string const & forget);

        
        ATarget* createTarget(std::string const &target);


};
