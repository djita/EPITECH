/*
** div.c for castmania in /home/guillo_e//Documents/working/tek2/piscine/D02m/ex04
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jan 10 10:43:14 2013 lyoma guillou
** Last update Thu Jan 10 12:11:52 2013 lyoma guillou
*/

#include "castmania.h"

int		integer_div(int a, int b)
{
  return (b != 0 ? a / b : 0);
}

float		decimale_div(int a, int b)
{
  return (b != 0 ? a / b : 0);
}

void		exec_div(t_div *operation)
{
  t_integer_op	*ent;
  t_decimale_op	*dec;

  switch (operation->div_type)
    {
    case (INTEGER):
      ent = operation->div_op;
      ent->res = integer_div(ent->a, ent->b);
      break;
    case (DECIMALE):
      dec = operation->div_op;
      dec->res = decimale_div(dec->a, dec->b);
      break;
    }
}
