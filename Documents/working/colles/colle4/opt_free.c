/*
** opt_free.c for opt_free in /home/deleta_m//Projets/Colles/Colle_4
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Mon May  7 19:22:42 2012 marc deletang
** Last update Mon May  7 20:40:39 2012 lyoma guillou
*/

#include <stdlib.h>
#include "opt_get.h"

void		opt_free(t_opt *options)
{
  t_opt		*tmp;
  t_opt		*tmp_free;

  tmp = options;
  while (tmp)
    {
      tmp_free = tmp;
      tmp = tmp->next;
      free(tmp_free->arg);
      free(tmp_free);
    }
}
