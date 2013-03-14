/*
** stack.c for stack in /home/guillo_e//Documents/working/tek2/piscine/D02a/ex03
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jan 10 22:45:14 2013 lyoma guillou
** Last update Thu Jan 10 22:58:39 2013 lyoma guillou
*/

#include "generic_list.h"
#include "stack.h"

unsigned int	stack_get_size(t_stack stack)
{
  return (list_get_size(stack));
}

t_bool		stack_is_empty(t_stack stack)
{
  return (list_is_empty(stack));
}

t_bool		stack_push(t_stack *stack_ptr, void *elem)
{
  return (list_add_elem_at_front(stack_ptr, elem));
}

t_bool		stack_pop(t_stack *stack_ptr)
{
  return (list_del_elem_at_front(stack_ptr));
}

void		*stack_top(t_stack stack)
{
  return (list_get_elem_at_front(stack));
}
