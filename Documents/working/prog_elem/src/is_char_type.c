/*
** is_char_type.c for lem-in in /home/guillo_e//Documents/working/prog_elem/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Apr  2 17:07:19 2012 lyoma guillou
** Last update Tue Apr 10 18:02:13 2012 lyoma guillou
*/

#include <parse.h>

int		is_sep(char c)
{
  if (c <= ' ' || c == '-')
    return (1);
  return (0);
}

int		is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int		is_low(char c)
{
  if (c >= 'a' && c <= 'z')
    return (1);
  return (0);
}

int		is_up(char c)
{
  if (c >= 'A' && c <= 'Z')
    return (1);
  return (0);
}

int		is_alphanum(char c)
{
  if (is_low(c) || is_up(c) || is_num(c))
    return (1);
  return (0);
}
