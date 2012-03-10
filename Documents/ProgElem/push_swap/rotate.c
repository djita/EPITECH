/*
** rotate.c for push_swap in /home/guillo_e//working/prog_elem
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jan  5 12:41:24 2012 lyoma guillou
** Last update Sun Jan  8 19:58:13 2012 lyoma guillou
*/

#include "push_swap.h"

t_list		*rotate_list(t_list *list)
{
  my_putchar('r');
  my_putchar(list->name);
  my_putchar(' ');
  return (list->next);
}

void		rotate_double(t_list *list_a, t_list *list_b)
{
  list_a = list_a->next;
  list_b = list_b->next;
  my_putstr("rr ");
}

t_list		*rev_rotate_list(t_list *list)
{
  my_putstr("rr");
  my_putchar(list->name);
  my_putchar(' ');
  return (list->prev);
}

void		rev_rotate_double(t_list *list_a, t_list *list_b)
{
  list_a = list_a->prev;
  list_b = list_b->prev;
  my_putstr("rrr ");
}
