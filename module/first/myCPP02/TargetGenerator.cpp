#include "TargetGenerator.hpp"
#include <string>
#include <utility>


TargetGenerator::TargetGenerator(){}

TargetGenerator::~TargetGenerator(){
    std::map<std::string, ATarget *>::iterator it_b = data.begin();
    std::map<std::string, ATarget *>::iterator it_e = data.end();
    while (it_b != it_e)
    {
        delete it_b->second;
        ++it_b;
    }
    data.clear();
}

void TargetGenerator::learnTargetType(ATarget* target){
    if(target)
        data.insert(std::pair<std::string, ATarget *>(target->gettype(),target->clone()));
}

void TargetGenerator::forgetTargetType(std::string const & forget){
    std::map<std::string, ATarget*>::iterator it = data.find(forget);
    if (it != data.end())
        delete it->second;
    data.erase(forget);
}

ATarget * TargetGenerator::createTarget(std::string const &target){
    std::map<std::string, ATarget*>::iterator it = data.find(target);
    if (it != data.end())
        return data[target];
    return NULL;
}