/*
** out_check.c for bistromathique in /afs/epitech.net/users/epitech_2016/falck_m/public/prog_elem/bistromathique
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Nov  2 17:44:21 2011 lyoma guillou
** Last update Thu Nov 10 17:15:41 2011 lyoma guillou
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "list_funcs.h"
#include "my_std/str_manip.h"

t_oper	*check_next(t_oper *output, char op)
{
  if (output->next == NULL)
    return (app_in_list(output, op));
  else
    return (output->next);
}

t_oper		*out_check(t_oper *link)
{
  t_oper	*out;
  char		tmp;

  out = link;
  while (link != NULL)
    {
      tmp = link->data;
      if (tmp >= 10)
	{
          link->next = check_next(link, 0);
	  link->data = tmp % 10;
	  link->next->data = link->next->data + (tmp / 10);
	  link->sign = 0;
	}
      else if (tmp < 0)
	{
	  if (link->prev == NULL)
	    tmp = 0;
	  else
	    {
	      tmp = link->prev->data;
	      link->prev->data = 10 - tmp;
	    }
	  link->data = 0;
	  link->sign = -1;
	}
      link = link->next;
    }
  return (out);
}
