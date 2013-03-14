#ifndef CHECKCITIZENS_H_
# define CHECKCITIZENS_H_

typedef enum	e_citType
  {
    kCitizenUnknown,
    kCitizenNormal,
    kCitizenBronze,
    kCitizenSilver,
    kCitizenGold
  }		CitizenType;

struct		s_Citizen
{
  unsigned int	id;
  char const	*name;
  CitizenType	type;
  unsigned int	nbMentees;
  unsigned int	*mentees;
};

typedef struct s_Citizen	Citizen;

int		is_Delegate(unsigned int idCitizen);
int		containsDelegatesOnly(unsigned int idsCitizens[], unsigned int idsCitiznesSize);
int		countDelegates(unsigned int idsCitizens[], unsigned int idsCitizensSize);

void		Citizen_setType(struct s_Citizen* citizen);
struct s_Citizen	*newCitizen(unsigned int id, char const *name, unsigned int nbMentees);

void		Citizen_attachMentee(struct s_Citizen *this, unsigned int idMentee);
void		Citizen_detachMentee(struct s_Citizen *this, unsigned int idMentee);
unsigned int	Citizen_getNextCitizenId(void);
void		deleteCitizen(Citizen *this);

#endif
