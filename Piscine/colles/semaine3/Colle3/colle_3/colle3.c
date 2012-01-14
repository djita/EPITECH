/*
** colle3.c for s_3 in /home/jpdeplaix/colles/s_3
** 
** Made by jacques-pascal deplaix
** Login   <deplai_j@epitech.net>
** 
** Started on  Sat Oct 29 18:27:46 2011 jacques-pascal deplaix
** Last update Sun Oct 30 05:37:10 2011 lyoma guillou
*/

#include <stdlib.h>
#include "my.h"

#define BUFFER_LEN 4095

typedef enum	e_colle
{
  COLLE1_1 = 1 << 0,
  COLLE1_2 = 1 << 1,
  COLLE1_3 = 1 << 2,
  COLLE1_4 = 1 << 3,
  COLLE1_5 = 1 << 4
}		t_colle;

typedef struct	s_sqr
{
  int		lin;
  int		col;
  int		lin_nb;
  int		col_nb;
  char		*buffer;
  t_colle	colle;
}		t_sqr;

typedef struct	s_desc
{
  char		top_left;
  char		top_right;
  char		bot_left;
  char		bot_right;
  char		lin;
  char		col;
}		t_desc;

t_colle		init_colle(char *buffer)
{
  if ('o' == buffer[0])
    return (COLLE1_1);
  else if ('/' == buffer[0])
    return (COLLE1_2);
  else if ('A' == buffer[0] || 'B' == buffer[0])
    return (COLLE1_3 | COLLE1_4 | COLLE1_5);
  return (0);
}

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

void		colle(t_sqr *sqr, t_desc *desc, int i, t_colle colle)
{
  if (sqr->lin == 1 && sqr->col == 1)
    {
      if (desc->top_left != sqr->buffer[i])
	sqr->colle ^= colle;
    }
  else if (sqr->lin == 1 && sqr->col == sqr->col_nb)
    {
      if (desc->top_right != sqr->buffer[i])
	sqr->colle ^= colle;
    }
  else if (sqr->lin == sqr->lin_nb && sqr->col == 1)
    {
      if (desc->bot_left != sqr->buffer[i])
	sqr->colle ^= colle;
    }
  else if (sqr->lin == sqr->lin_nb && sqr->col == sqr->col_nb)
    {
      if (desc->bot_right != sqr->buffer[i])
	sqr->colle ^= colle;
    }
  else if ((sqr->lin == 1 || sqr->lin == sqr->lin_nb) && desc->lin != sqr->buffer[i])
    sqr->colle ^= colle;
  else if ((sqr->col == 1 || sqr->col == sqr->col_nb) && desc->col != sqr->buffer[i])
    sqr->colle ^= colle;
}

t_sqr		*s_sqr_new(char *buffer)
{
  t_sqr		*sqr;

  sqr = malloc(sizeof(t_sqr));
  if (sqr == NULL)
    return (NULL);
  sqr->lin = 1;
  sqr->col = 0;
  sqr->buffer = buffer;
  sqr->lin_nb = lin_number(buffer);
  sqr->col_nb = col_number(buffer);
  sqr->colle = init_colle(buffer);
  return (sqr);
}

t_desc		*s_desc_new(void)
{
  t_desc	*desc;

  desc = malloc(sizeof(t_desc));
  if (desc == NULL)
    return (NULL);
  return (desc);
}

t_desc		*colle1_1()
{
  t_desc	*ret;

  ret = malloc(sizeof(t_desc));
  if (ret == NULL)
    return (NULL);
  ret->top_left = 'o';
  ret->top_right = 'o';
  ret->bot_left = 'o';
  ret->bot_right = 'o';
  ret->lin = '-';
  ret->col = '|';
  return (ret);
}

t_desc		*colle1_2()
{
  t_desc	*ret;

  ret = malloc(sizeof(t_desc));
  if (ret == NULL)
    return (NULL);
  ret->top_left = '/';
  ret->top_right = '\\';
  ret->bot_left = '\\';
  ret->bot_right = '/';
  ret->lin = '*';
  ret->col = '*';
  return (ret);
}

t_desc		*colle1_3()
{
  t_desc	*ret;

  ret = malloc(sizeof(t_desc));
  if (ret == NULL)
    return (NULL);
  ret->top_left = 'A';
  ret->top_right = 'A';
  ret->bot_left = 'C';
  ret->bot_right = 'C';
  ret->lin = 'B';
  ret->col = 'B';
  return (ret);
}

t_desc		*colle1_4()
{
  t_desc	*ret;

  ret = malloc(sizeof(t_desc));
  if (ret == NULL)
    return (NULL);
  ret->top_left = 'A';
  ret->top_right = 'C';
  ret->bot_left = 'A';
  ret->bot_right = 'C';
  ret->lin = 'B';
  ret->col = 'B';
  return (ret);
}

t_desc		*colle1_5()
{
  t_desc	*ret;

  ret = malloc(sizeof(t_desc));
  if (ret == NULL)
    return (NULL);
  ret->top_left = 'A';
  ret->top_right = 'C';
  ret->bot_left = 'C';
  ret->bot_right = 'A';
  ret->lin = 'B';
  ret->col = 'B';
  return (ret);
}

void		call_colle(t_sqr *sqr, int i)
{
  if (sqr->colle & COLLE1_1)
    colle(sqr, colle1_1(), i, COLLE1_1);
  if (sqr->colle & COLLE1_2)
    colle(sqr, colle1_2(), i, COLLE1_2);
  if (sqr->colle & COLLE1_3)
    colle(sqr, colle1_3(), i, COLLE1_3);
  if (sqr->colle & COLLE1_4)
    colle(sqr, colle1_4(), i, COLLE1_4);
  if (sqr->colle & COLLE1_5)
    colle(sqr, colle1_5(), i, COLLE1_5);
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

int		main()
{
  char		buffer[BUFFER_LEN + 1];
  int		len;

  len = 0;
  sleep(2);
  if (len = read(0, buffer, BUFFER_LEN))
    {
      buffer[len] = '\0';
      what_is_this_glue(buffer);
    }
  return (0);
}
