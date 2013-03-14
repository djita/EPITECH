#ifndef POLLMODULE_H_
# define POLLMODULE_H_

enum		PollVote
  {
    kVoteNo = 0,
    kVoteYes,
    kVoteUnknown
  };

struct		Poll
{
  enum PollVote	ans;
  char const	*name;
  unsigned int	citizenId;
  struct Poll	*next;
};

struct Poll	*newPoll(char const *pollName);
void		deletePoll(struct Poll *this);
void		constructPoll(struct Poll *this, char const *pollName);
void		destructPoll(struct Poll *this);
char const	*Poll_getPollName(struct Poll const *this);
void		Poll_addVote(struct Poll *this, unsigned int citizenId, enum PollVote vote);
enum PollVote	Poll_getResult(struct Poll const *this);
unsigned int	Poll_getTotalNbVotes(struct Poll const *this);
unsigned int	Poll_getNbVotes(struct Poll const *this, enum PollVote vote);

#endif 
