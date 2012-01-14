/*
** colle3.c for s_3 in /home/jpdeplaix/colles/s_3
** 
** Made by jacques-pascal deplaix
** Login   <deplai_j@epitech.net>
** 
** Started on  Sat Oct 29 18:27:46 2011 jacques-pascal deplaix
** Last update Sun Oct 30 05:53:38 2011 lyoma guillou
*/

#include "my.h"

void		print_size(t_sqr *sqr)
{
  my_putstr(" [");
  my_put_nbr(sqr->col_nb);
  my_putstr("] [");
  my_put_nbr(sqr->lin_nb);
  my_putchar(']');
}

void		print_colle(t_sqr *sqr)
{
  if (sqr->colle & COLLE1_1)
    my_putstr("[colle1-1]");
  else if (sqr->colle & COLLE1_2)
    my_putstr("[colle1-2]");
  else if (sqr->colle & COLLE1_3)
    my_putstr("[colle1-3]");
  else if (sqr->colle & COLLE1_4)
    my_putstr("[colle1-4]");
  else if (sqr->colle & COLLE1_5)
    my_putstr("[colle1-5]");
  print_size(sqr);
  my_putchar('\n');
}

int		lin_number(char *buffer)
{
  int		i;
  int		counter;

  i = 0;
  counter = 0;
  while (buffer[i])
    {
      if ('\n' == buffer[i])
	counter += 1;
      i += 1;
    }
  return (counter);
}

int		col_number(char *buffer)
{
  int		i;

  i = 0;
  while (buffer[i] && '\n' != buffer[i])
    i += 1;
  return (i);
}

void		what_is_this_glue(char *buffer)
{
  t_sqr		*sqr;
  int		i;

  i = 0;
  sqr = s_sqr_new(buffer);
  while (buffer[i])
    {
      if ('\n' == buffer[i])
	{
	  sqr->lin += 1;
	  sqr->col = 0;
	}
      else
	{
	  sqr->col += 1;
	  call_colle(sqr, i);
	}
      i += 1;
    }
  print_colle(sqr);
}
