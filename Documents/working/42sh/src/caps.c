/*
** caps.c for src in /mnt/fedora_std/home/falck_m/Work/42sh/src
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Fri May 18 19:44:50 2012 mickael falck
** Last update Sun May 20 17:05:34 2012 mickael falck
*/

#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include "termcaps.h"
#include "parse_caps.h"
#include "history.h"
#include "readline.h"

void		keyup(t_readline *rl)
{
  rl->offset = strlen(rl->buff);
}

void		keydown(t_readline *rl)
{
  rl->offset = strlen(rl->buff);
}

void		keyleft(t_readline *rl)
{
  if (rl->offset)
    --rl->offset;
}

void		keyright(t_readline *rl)
{
  if (rl->offset < strlen(rl->buff))
    ++rl->offset;
}

void		keybackspace(t_readline *rl)
{
  char		*tmp;

  if (rl->offset)
    {
      tmp = strdup(rl->buff + rl->offset);
      strcpy(rl->buff + rl->offset - 1, tmp);
      termcommand("le");
      --rl->offset;
      free(tmp);
    }
}
