#include "ATarget.hpp"

ATarget::ATarget(){

}

ATarget::ATarget(std::string const &Type){

}

ATarget::~ATarget(){

}

ATarget::ATarget(ATarget const &other){

}

ATarget &ATarget::operator=(ATarget const &other){
    
}

std::string const & ATarget::getType() const{return (this->type);}

void ATarget::getHitBySpell(ASpell const &ref) const
{
    std::cout << this->type << " has been " << ref.getEffects() << std::endl;
}
