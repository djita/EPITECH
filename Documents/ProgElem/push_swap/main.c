/*
** main.c for push_swap in /home/guillo_e//working/prog_elem
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Jan  3 16:45:02 2012 lyoma guillou
** Last update Sun Jan  8 20:11:05 2012 lyoma guillou
*/

#include <stdlib.h>
#include "push_swap.h"

int		main(int ac, char **av)
{
  t_swap	*swap;

  if ((swap = malloc(sizeof(*swap))) == NULL)
    return (-1);
  if (ac > 1)
    {
      swap->l_a = circle_list(my_get_int_tab(ac, av), ac - 1, 'a');
      swap->l_b = NULL;
      swap_sort(swap);
      my_putchar('\n');
      
      /*      
      ** my_putstr("l_a: ");
      ** show_list(swap->l_a);
      ** my_putstr("l_b: ");
      ** show_list(swap->l_b); 
      */
      
    }
  return (0);
}
