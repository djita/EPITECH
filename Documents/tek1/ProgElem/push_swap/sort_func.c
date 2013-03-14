/*
** sort_func.c for push_swap in /home/guillo_e//working/prog_elem
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Jan  3 17:59:42 2012 lyoma guillou
** Last update Sun Jan  8 20:02:26 2012 lyoma guillou
*/

#include <stdlib.h>
#include "push_swap.h"

void		show_list(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  if (tmp != NULL)
    {
      while (tmp != list->prev)
	{
	  my_putnbr(tmp->val);
	  my_putchar(' ');
	  tmp = tmp->next;
	}
      my_putnbr(tmp->val);
    }
  my_putchar('\n');
}

void		swap_sort(t_swap *swap)
{
  t_list	*tmp;
  int		tval;

  while (swap->l_a->next != swap->l_a)
    {
      tmp = swap->l_a;
      tval = tmp->val;
      swap->l_a = rotate_list(swap->l_a);
      while (swap->l_a != tmp)
	{
	  if (tval > swap->l_a->val)
	    {
	      tmp = swap->l_a;
	      tval = tmp->val;
	    }
	  swap->l_a = rotate_list(swap->l_a);
	}
      swap = push_to_b(swap);
    }
  while (swap->l_b != NULL)
    {
      swap = push_to_a(swap);
      if (swap->l_b)
	my_putchar(' ');
    }
}
