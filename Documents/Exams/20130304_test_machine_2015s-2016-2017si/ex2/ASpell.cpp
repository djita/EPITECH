#include "ASpell.h"
#include "ATarget.h"
#include <string>

ASpell::ASpell(std::string _name, std::string _effects) : name(_name), effects(_effects) {}
ASpell::ASpell(ASpell const &other) : name(other.name), effects(other.effects) {}
ASpell::~ASpell() {}

std::string ASpell::getName() const { return this->name; }
std::string ASpell::getEffects() const { return this->effects; }

void ASpell::launch(ATarget const &target)
{
  target.getHitBySpell(*this);
}

ASpell & ASpell::operator=(ASpell const &other)
{
  name = other.name;
  effects = other.effects;
  return *this;
}
