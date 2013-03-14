#include "Mutation.hpp"
#include "Zergling.hpp"
#include "Baneling.hpp"
#include "Overlord.hpp"
#include "Overseer.hpp"

AUnit * Mutation::muter(AUnit *unit)
{
  AUnit * _new = NULL; 
  if (unit->_type == AUnit::ZERG)
    {
      _new = new Baneling(*unit);
      delete unit;
    }
  if (unit->_type == AUnit::LORD)
    {
      _new = new Overseer(*unit);
      delete unit;
    }
  return _new;
}
