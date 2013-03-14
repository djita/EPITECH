/*
** operators.c for bistromathique in /afs/epitech.net/users/epitech_2016/falck_m/public/prog_elem/bistromathique
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Wed Nov 02 17:07:53 2011 mickael falck
** Last update Thu Nov 10 16:20:36 2011 lyoma guillou
*/

#include "bistromathique.h"
#include "list_funcs.h"
#include "out_check.h"

t_oper		*do_add(t_oper *a, t_oper *b)
{
  t_oper	*first_link;
  t_oper	*cur_link;
  char		result;

  first_link = NULL;
  while (a || b)
    {
      result = (a && !b) ? a->data : b->data;
      result = (a && b) ? a->data + b->data : result;
      if(!first_link)
	cur_link = first_link = app_in_list(NULL, result);
      else
	cur_link = app_in_list(cur_link, result);
      if (b)
	b = b->next;
      if (a)
	a = a->next;
    }
  first_link = out_check(first_link);
  return (first_link);
}

t_oper		*do_sub(t_oper *a, t_oper *b)
{
  t_oper	*first_link;
  t_oper	*cur_link;
  char		result;

  first_link = NULL;
  while (a || b)
    {
      result = a->data - b->data;
      if (!first_link)
	cur_link = first_link = app_in_list(NULL, result);
      else
	cur_link = app_in_list(cur_link, result);
      if (a)
	a = a->next;
      if (b)
	b = b->next;
    }
  first_link = out_check(first_link);
  return (first_link);
}
