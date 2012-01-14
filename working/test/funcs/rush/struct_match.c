/*
** struct_match.c for struct_match in /home/guillo_e//working/test/funcs
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Nov 26 18:15:30 2011 lyoma guillou
** Last update Sat Nov 26 21:41:51 2011 lyoma guillou
*/

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int             is_type_range(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || 
      (c >= '0' && c <= '9') || (c == '-' || c == '_'))
    return (1);
  if (c == ' ')
    return (2);
  return (0);
}

int             struct_match(char *str)
{
  int           i;
  int		is_tdef;

  i = 0;
  if (str[0] == 't' && str[1] == '_')
    is_tdef = 1;
  else
    return (0);
  while (is_type_range(str[i]) != 0)
    {
      if (is_type_range(str[i]) == 2)
	return (-1);
      i++;
    }
  if (i != my_strlen(str) || i <= 2)
    return (0);
  return (1);
}
