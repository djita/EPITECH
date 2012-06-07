/*
** parse_caps.c for src in /mnt/fedora_std/home/falck_m/Work/42sh/src
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Fri May 18 19:29:48 2012 mickael falck
** Last update Sun May 20 16:08:46 2012 mickael falck
*/

#include <sys/types.h>
#include <string.h>
#include <term.h>
#include "termcaps.h"
#include "history.h"
#include "readline.h"
#include "caps.h"

typedef struct	s_cap
{
  char		*cap;
  void		(*f)(t_readline *);
}		t_cap;

static const t_cap	g_caps[] = {
  {"ku", keyup},
  {"kd", keydown},
  {"kl", NULL},
  {"kr", NULL},
  {"kb", keybackspace},
  {NULL, NULL}
};

int	capcmp(char *cap, const char *str)
{
  char	*capstr;

  if ((capstr = tgetstr(cap, NULL)) == NULL)
    return (0);
  else
    return (strcmp(capstr, str));
}

void		correct_offset(t_readline *rl)
{
  size_t	curpos;
  size_t	targetpos;
  int		diff;

  curpos = rl->offset;
  targetpos = strlen(rl->buff);
  diff = (curpos < targetpos) ? 1 : -1;
  while (curpos != targetpos)
    {
      termcommand((diff > 0) ? "nd" : "le");
      curpos += diff;
    }
}

int		parse_caps(t_readline *rl)
{
  size_t	i;

  i = 0;
  if (get_tty(-1) == 0)
    return (0);
  while (g_caps[i].cap && capcmp(g_caps[i].cap, rl->input))
    ++i;
  if (g_caps[i].cap)
    {
      if (g_caps[i].f)
	g_caps[i].f(rl);
      return (1);
    }
  else
    return (0);
}
