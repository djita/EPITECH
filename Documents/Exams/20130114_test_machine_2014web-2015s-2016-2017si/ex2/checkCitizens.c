#include <stdlib.h>
#include <string.h>
#include "checkCitizens.h"

static unsigned int	g_next = 0;

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

Citizen		*newCitizen(unsigned int id, char const *name, unsigned int nbMentees)
{
  Citizen	*new;

  if (id > g_next)
    g_next = id;
  new = malloc(sizeof(*new));
  new->id = id;
  new->name = name;
  new->nbMentees = nbMentees;
  new->mentees = 0;
  if (nbMentees != 0)
    {
      new->mentees = malloc(nbMentees * sizeof(*(new->mentees)));
      memset(new->mentees, 0, nbMentees);
    }
  Citizen_setType(new);
  return (new);
}

void		Citizen_attachMentee(Citizen *this, unsigned int idMentee)
{
  unsigned int	i = 0;
  unsigned int	*tmp;

  if (this && this->mentees)
    {
      tmp = this->mentees;
      for (i = 0; i < this->nbMentees; ++i)
	if (!tmp[i])
	  {
	    tmp[i] = idMentee;
	    break;
	  }
    }
}

void		Citizen_detachMentee(Citizen *this, unsigned int idMentee)
{
  unsigned int	i = 0;
  unsigned int	*tmp;

  if (this && this->mentees)
    {
      tmp = this->mentees;
      for (i = 0; i < this->nbMentees; ++i)
	if (tmp[i] == idMentee)
	  {
	    tmp[i] = 0;
	    break;
	  }
    }
}

unsigned int	Citizen_getNextCitizenId(void)
{
  return g_next + 1;
}

void		deleteCitizen(Citizen *this)
{
  if (this)
    {
      if (this->mentees)
	free(this->mentees);
      memset(this, 0, sizeof(*this));
      free(this);
    }
}
