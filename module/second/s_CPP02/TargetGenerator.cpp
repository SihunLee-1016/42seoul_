#include "TargetGenerator.hpp"
#include "ATarget.hpp"

TargetGenerator::~TargetGenerator()
{
    std::map<std::string, ATarget *>::iterator it_begin = data.begin();
    std::map<std::string, ATarget *>::iterator it_end = data.end();

    while (it_begin != it_end)
    {
        delete it_begin->second;
        ++it_begin;
    }
    data.clear();
}

void TargetGenerator::learnTargetType(ATarget *spell){
    if(spell)
        data.insert(std::pair<std::string, ATarget *>(spell->getType(),spell->clone()));
}

void TargetGenerator::forgetTargetType(std::string const &forget_spell){
    std::map<std::string, ATarget *>::iterator it = data.find(forget_spell);

    if (it != data.end())
        delete it->second;
    data.erase(forget_spell);
}

ATarget* TargetGenerator::createTarget(std::string const &spell){
    std::map<std::string, ATarget *>::iterator it = data.find(spell);

    if (it != data.end())
        return data[spell];
    return NULL;
}
