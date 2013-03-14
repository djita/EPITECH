#include "ASpell.h"
#include "Fwoosh.h"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {}

Fwoosh * Fwoosh::clone() { return new Fwoosh; }
