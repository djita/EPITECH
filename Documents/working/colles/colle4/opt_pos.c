/*
** opt_post.c for opt_post in /home/deleta_m//Projets/Colles/Colle_4
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Mon May  7 19:22:03 2012 marc deletang
** Last update Mon May  7 22:41:26 2012 lyoma guillou
*/

#include <stdlib.h>
#include "opt_get.h"
#include "lib.h"

t_pos		opt_pos(t_opt *options, const char *option)
{
  t_opt		*tmp;
  int		cnt;
  char		*opt;

  cnt = 1;
  tmp = options;
  opt = (char *) option;
  while (tmp != NULL)
    {
      if (!my_strncmp(tmp->arg + 1, opt, my_strlen(opt)))
	return (cnt);
      cnt++;
      tmp = tmp->next;
    }
  return (-1);
}
