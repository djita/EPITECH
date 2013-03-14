/*
** list_funcs.c for bistromathique in /afs/epitech.net/users/epitech_2016/falck_m/public/prog_elem/bistromathique
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Nov  1 19:05:59 2011 lyoma guillou
** Last update Thu Nov 10 14:19:57 2011 lyoma guillou
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "my_std/str_manip.h"

int		is_ops(char c, char *ops)
{
  int		ind;

  ind = 0;
  while (ops[ind])
    {
      if (c == ops[ind])
	return (ind);
      ind++;
    }
  return (-1);
}

int		is_base(char c, char *base)
{
  int		ind;

  ind = 0;
  while (base[ind])
    {
      if (c == base[ind])
	return (ind);
      ind += 1;
    }
  return (-1);
}

t_oper		*init_list(char op)
{
  t_oper	*elem;

  elem = malloc(sizeof(*elem));
  if (NULL == elem)
    return (NULL);
  elem->data = op;
  elem->sign = 0;
  elem->next = NULL;
  elem->prev = NULL;
  return (elem);
}

t_oper		*app_in_list(t_oper *link, char op)
{
  t_oper	*new_link;

  if (!(new_link = malloc(sizeof(*link))))
    my_put_estr("Could not alloc. app_in_list");
  new_link->data = op;
  if (op < 0)
    new_link->sign = -1;
  else
    new_link->sign = 1;
  new_link->prev = link;
  new_link->next = NULL;
  if (link)
    {
      link->next = new_link;
      new_link->sign = link->sign;
    }
  return (new_link);
}

t_oper		*operand_to_list(char *str)
{
  int		i;
  t_oper	*output;
  t_oper	*cur_link;

  i = my_strlen(str) - 1;
  while (i >= 0)
    {
      if (i == my_strlen(str) - 1)
	cur_link = output = init_list(str[i] - '0');
      else
	cur_link = app_in_list(cur_link, str[i] - '0');
      i = i - 1;
    }
  return (output);
}

void		read_list(t_oper *first_link)
{
  while (first_link->next)
    first_link = first_link->next;
  if (first_link->sign < 0)
    my_putchar('-');
  while (first_link)
    {
      if (!first_link->next && first_link->prev)
	{
	  if (first_link->data != 0)
	    my_putnbr(first_link->data);
	}
      else
	my_putnbr(first_link->data);
      first_link = first_link->prev;
    }
}

//  char *machin;

//  my_put_nbr(*(int *)(&machin));
