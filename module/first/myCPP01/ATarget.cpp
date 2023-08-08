#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget(){}

ATarget::ATarget(std::string const &type){ this->type = type;}

ATarget &ATarget::operator=(ATarget const &other){
    this->type = other.type;
    return (*this);
}

ATarget::ATarget (ATarget const &other)
{
    this->type = other.type;
}

ATarget::~ATarget()
{}

void ATarget::getHitBySpell(ASpell const &aspell_ref) const
{
    std::cout << this->type << " has been " << aspell_ref.getEffects() << "!\n";
}

std::string const & ATarget::gettype() const
{
    return (this->type);
}
