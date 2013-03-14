#include "checkCitizens.h"

int		is_Delegate(unsigned int idCitizen)
{
  return !(idCitizen % 64);
}

int		containsDelegatesOnly(unsigned int idsCitizens[], unsigned int idsCitizensSize)
{
  unsigned int	i;

  if (idsCitizensSize != 0)
    {
      for (i = 0; i < idsCitizensSize && is_Delegate(idsCitizens[i]); ++i);
      return (i == idsCitizensSize);
    }
  return 0;
}

int		countDelegates(unsigned int idsCitizens[], unsigned int idsCitizensSize)
{
  unsigned int	x = 0;
  unsigned int	i = 0;

  for (i = 0; i < idsCitizensSize; ++i)
    if (is_Delegate(idsCitizens[i]))
      ++x;
  return x;
}

void		Citizen_setType(Citizen *citizen)
{
  citizen->type = kCitizenNormal;
  if (citizen->id < 8)
    citizen->type = kCitizenGold;
  if (citizen->id >= 8 && citizen->id < 64)
    citizen->type = kCitizenSilver;
  if (citizen->id >= 64 && citizen->id < 4096)
    citizen->type = kCitizenBronze;
}
