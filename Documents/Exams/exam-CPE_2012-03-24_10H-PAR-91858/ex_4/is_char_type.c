/*
** is_char_type.c for ord_alphlong in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Mar 24 10:41:41 2012 exam_user
** Last update Sat Mar 24 10:42:12 2012 exam_user
*/

int		is_sep(char c)
{
  if (c <= ' ')
    return (1);
  return (0);
}

int		is_uper(char c)
{
  if (c >= 'A' && c <= 'Z')
    return (1);
  return (0);
}

int		is_lower(char c)
{
  if (c >= 'a' && c <= 'z')
    return (1);
  return (0);
}

int		is_alpha(char c)
{
  if (is_uper(c) || is_lower(c))
    return (1);
  return (0);
}
