/*
** add.c for castmania in /home/guillo_e//Documents/working/tek2/piscine/D02m/ex04
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jan 10 11:01:27 2013 lyoma guillou
** Last update Thu Jan 10 11:48:21 2013 lyoma guillou
*/

#include <stdlib.h>

#include "castmania.h"

int		normal_add(int a, int b)
{
  return (a + b);
}

int		absolute_add(int a, int b)
{
  return normal_add(abs(a), abs(b));
}

void		exec_add(t_add *operation)
{
  t_integer_op	op;

  op = operation->add_op;
  switch (operation->add_type)
    {
    case (NORMAL):
      op.res = normal_add(op.a, op.b);
      break;
    case (ABSOLUTE):
      op.res = absolute_add(op.a, op.b);
      break;
    }
}
