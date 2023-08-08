#include "ASpell.hpp"

ASpell::ASpell(){}

ASpell::ASpell(std::string const &type){}

ASpell::~ASpell(){}

ASpell::ASpell(ASpell const &other){}

ASpell &ASpell::operator=(ASpell const &other){}

std::string const & ASpell::getName() const{}

std::string const & ASpell::getEffects() const{}


void ASpell::launch(ATarget const & ref) const
{
    ref.getHitBySpell((*this));
}
