/*
** func_ptr.h for func_ptr in /home/guillo_e//Documents/working/tek2/piscine/D02m/ex03
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jan 10 10:05:31 2013 lyoma guillou
** Last update Thu Jan 10 10:31:08 2013 lyoma guillou
*/

#ifndef FUNC_PTR_H_
# define FUNC_PTR_H_

# include "func_ptr_enum.h"

typedef struct	s_act
{
  t_action	action;
  void		(*func)(char *);
}		t_act;

void		print_42(char *str);
void		print_upper(char *str);
void		print_reverse(char *str);
void		print_normal(char *str);

#endif
