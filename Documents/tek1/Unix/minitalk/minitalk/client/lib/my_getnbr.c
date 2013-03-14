/*
** my_getnbr.c for minitalk in /home/guillo_e//Documents/working/unix/minitalk/client/lib
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Mar 15 18:32:29 2012 lyoma guillou
** Last update Fri Mar 16 09:57:03 2012 lyoma guillou
*/

static int	_is_numeric(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

unsigned int	my_getnbr(char *str)
{
  unsigned int	x;
  int		i;

  x = 0;
  i = 0;
  while (_is_numeric(str[i]))
    {
      x = (x * 10) + (str[i] - '0');
      ++i;
    }
  return (x);
}
