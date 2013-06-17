#ifndef LINK_H_
# define LINK_H_

typedef enum	e_dync
  {
    DEAD = 1 << 0,
    ALIVE = 1 << 1,
    PHYSIC = 1 << 2,
    REACT = 1 << 3,
    UNKNOWN = 1 << 4
  }		_dync;

typedef enum	e_type
  {
    INEXIST = 1 << 0,
    EXIST = 1 << 1,
    UNKNOWN = 1 << 2
  }		_type;

typedef struct	s_data
{
  enum e_type	val;
  enum e_dync	rct;
  char		*name;
  struct s_data	*next;
  struct s_data	*prev;
}		t_data;

#endif /* !LINK_H_ */
