/*
** opt_isset.c for opt_isset in /home/deleta_m//Projets/Colles/Colle_4
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Mon May  7 19:20:23 2012 marc deletang
** Last update Mon May  7 22:59:00 2012 lyoma guillou
*/

#include <stdlib.h>
#include "opt_get.h"
#include "lib.h"

t_bool		opt_isset(t_opt *options, const char *option)
{
  t_opt		*tmp;
  char		*opt;
  t_bool	state;

  tmp = options;
  opt = (char *) option;
  state = 0;
  while (tmp != NULL)
    {
      if (options->arg + 1 == opt)
	state = 1;
      tmp = tmp->next;
    }
  return (state);
}
