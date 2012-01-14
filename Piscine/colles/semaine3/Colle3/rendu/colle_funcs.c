/*
** colle_funcs.c for colle3.c in /home/guillo_e//working/colle
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sun Oct 30 05:46:33 2011 lyoma guillou
** Last update Sun Oct 30 06:01:49 2011 lyoma guillou
*/

#include <stdlib.h>
#include "my.h"

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
