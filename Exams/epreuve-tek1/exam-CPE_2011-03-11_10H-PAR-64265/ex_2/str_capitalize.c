/*
** str_capitalize.c for str_capitalize in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Mar 11 10:45:05 2011 exam_user
** Last update Fri Mar 11 11:05:21 2011 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  write(1, str, i);
}

int	is_separator(char c)
{
  if (c <= ' ')
    return (1);
  return (0);
}

int	is_alph(char c)
{
  if (c >= 'a' && c <= 'z')
    return (2);
  if (c >= 'A' && c <= 'Z')
    return (1);
  return (0);
}

char	*str_capitalize(char *str)
{
  int	i;
  int	x;

  i = 0;
  x = 0;
  while (str[i])
    {
      if (is_separator(str[i]) == 0 && x == 0)
	{
	  x = 1;
	  if (is_alph(str[i]) == 2)
	    str[i] = str[i] - 32;
	}
      if (is_separator(str[i]) == 1)
	x = 0;
      i++;
    }
  return (str);
}
