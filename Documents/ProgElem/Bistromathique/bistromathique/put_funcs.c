/*
** put_funcs.c for bistromathique in /afs/epitech.net/users/epitech_2016/falck_m/public/prog_elem/bistromathique
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Nov  1 18:15:48 2011 lyoma guillou
** Last update Wed Nov 02 15:33:34 2011 mickael falck
*/

#include <stdlib.h>
#include <unistd.h>
#include "bistromathique.h"
#include "put_funcs.h"

void		put_list(t_oper **list)
{
  t_oper	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      my_putstr(&tmp->data);
      my_putchar('\n');
      tmp = tmp->next;
    }
}
