#include <string.h>
#include <stdlib.h>
#include "pollModule.h"

struct Poll	*newPoll(char const *pollName)
{
  struct Poll	*new;

  new = malloc(sizeof(*new));
  new->ans = kVoteUnknown;
  new->name = NULL;
  if (pollName)
    new->name = pollName;
  new->citizenId = 0;
  new->next = NULL;
  return (new);
}

void		deletePoll(struct Poll *this)
{
  if (this->next)
    deletePoll(this->next);
  memset(this, 0, sizeof(*this));
  free(this);
}

void		constructPoll(struct Poll *this, char const *pollName)
{
  this->ans = kVoteUnknown;
  this->name = pollName;
  if (pollName)
    this->name = pollName;
  this->citizenId = 0;
  this->next = NULL;
}

void		destructPoll(struct Poll *this)
{
  if (this->next)
    destructPoll(this->next);
  this->ans = kVoteUnknown;
  this->name = NULL;
  this->citizenId = 0;
}

char const	*Poll_getPollName(struct Poll const *this)
{
  return (this->name) ? this->name : NULL;
}

void		Poll_addVote(struct Poll *this, unsigned int citizenId, enum PollVote vote)
{
  if (citizenId == this->citizenId && vote != kVoteUnknown)
    this->ans = vote;
  else
    {
      if (this->next)
	Poll_addVote(this->next, citizenId, vote);
      else
	{
	  struct Poll	*new;
      
	  new = newPoll(this->name);
	  new->ans = vote;
	  this->next = new;
	}  
    }
}

enum PollVote	Poll_getResult(struct Poll const *this)
{
  struct Poll	*tmp;
  int		catch = 0;

  if (this->next)
    {
      tmp = this->next;
      while (tmp->next)
	{
	  if (tmp->ans != kVoteUnknown)
	    catch = (tmp->ans == kVoteYes) ? catch + 1 : catch - 1;
	  tmp = tmp->next;
	}
    }
  if (tmp->ans != kVoteUnknown)
    catch = (tmp->ans == kVoteYes) ? catch + 1 : catch - 1;
  if (!catch)
    return kVoteUnknown;
  return (catch > 0) ? kVoteYes : kVoteNo;
}

unsigned int	Poll_getTotalNbVotes(struct Poll const *this)
{
  if (this->next)
    return 1 + Poll_getTotalNbVotes(this->next);
  return (this->ans);
}

unsigned int	Poll_getNbVotes(struct Poll const *this, enum PollVote vote)
{
  if (this && vote != kVoteUnknown)
    return ((vote == this->ans) ? 1 : 0) + Poll_getNbVotes(this->next, vote);
  return 0;
}
