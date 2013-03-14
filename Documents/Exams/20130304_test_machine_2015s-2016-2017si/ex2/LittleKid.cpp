#include "LittleKid.h"
#include "ATarget.h"

LittleKid::LittleKid() : ATarget("LittleKid") {}

LittleKid * LittleKid::clone() { return new LittleKid; }
