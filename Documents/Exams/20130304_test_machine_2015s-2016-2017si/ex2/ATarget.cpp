#include "ASpell.h"
#include "ATarget.h"
#include <iostream>
#include <string>

ATarget::ATarget(std::string _type) : type(_type) {}
ATarget::ATarget(ATarget const &other) : type(other.type) {}
ATarget::~ATarget() {}

std::string ATarget::getType() const { return this->type; }

void ATarget::getHitBySpell(ASpell const &spell)
{
  std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}

ATarget & ATarget::operator=(ATarget const &other)
{
  type = other.type;
  return *this;
}
