/*
** colle_struct.c for colle3 in /home/guillo_e//working/colle
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sun Oct 30 05:43:08 2011 lyoma guillou
** Last update Sun Oct 30 05:59:31 2011 lyoma guillou
*/

#include <stdlib.h>
#include "my.h"

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
