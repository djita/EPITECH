/*
** swap_push_op.c for push_swap in /home/guillo_e//working/prog_elem
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Jan  3 16:58:06 2012 lyoma guillou
** Last update Sun Jan  8 19:57:06 2012 lyoma guillou
*/

#include <stdlib.h>
#include "push_swap.h"

t_list		*swap_list(t_list *list)
{
  int		tmp;

  tmp = list->val;
  list->val = list->next->val;
  list->next->val = tmp;
  my_putchar('s');
  my_putchar(list->name);
  my_putchar(' ');
  return (list);
}

void		swap_double(t_list *list_a, t_list *list_b)
{
  int		tmp;

  tmp = list_a->val;
  list_a->val = list_a->next->val;
  list_a->next->val = tmp;

  tmp = list_b->val;
  list_b->val = list_b->next->val;
  list_b->next->val = tmp;
  my_putstr("ss ");
}

t_list		*relink_first(t_list *src, t_list *dst)
{
  t_list	*tmp;

  tmp = src;
  tmp->prev = dst->prev;
  dst->prev->next = tmp;
  tmp->next = dst;
  dst->prev = tmp;
  return (tmp);
}

t_swap		*push_to_a(t_swap *swap)
{
  t_list	*new_first;
  t_list	*new_last;

  new_first = swap->l_b->next;
  new_last = swap->l_b->prev;
  new_first->prev = new_last;
  new_last->next = new_first;
  if (swap->l_a == NULL)
    {
      swap->l_a = swap->l_b;
      swap->l_a->next = swap->l_a;
      swap->l_a->prev = swap->l_a;
    }
  else
    swap->l_a = relink_first(swap->l_b, swap->l_a);
  if (swap->l_b == new_first)
    new_first = NULL;
  swap->l_b = new_first;
  swap->l_a->name = 'a';
  my_putstr("pa");
  return (swap);
}

t_swap		*push_to_b(t_swap *swap)
{
  t_list	*new_first;
  t_list	*new_last;

  new_first = swap->l_a->next;
  new_last = swap->l_a->prev;
  new_first->prev = new_last;
  new_last->next = new_first;
  if (swap->l_b == NULL)
    {
      swap->l_b = swap->l_a;
      swap->l_b->next = swap->l_b;
      swap->l_b->prev = swap->l_b;
    }
  else
    swap->l_b = relink_first(swap->l_a, swap->l_b);
  if (swap->l_a == new_first)
    new_first = NULL;
  swap->l_a = new_first;
  swap->l_b->name = 'b';
  my_putstr("pb ");
  return (swap);
}
