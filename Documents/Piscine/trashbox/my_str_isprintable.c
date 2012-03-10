/*
** my_str_isprintable.c for my_str_is_printable in /home/guillo_e//Documents/Piscine
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Oct 11 17:21:21 2011 lyoma guillou
** Last update Tue Oct 11 17:43:02 2011 lyoma guillou
*/

int	is_printable(char c)
{
  if (c >= ' ' && c <= '~')
    return (1);
  return (0);
}

int	my_str_isprintable(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (is_printable(str[i]) == 0)
	return (0);
      i++;
    }
  return (1);
}
