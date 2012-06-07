/*
** my_getnbr.c for my_getnbr in /home/guillo_e//afs/public/deleta_m
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon May 14 19:23:47 2012 lyoma guillou
** Last update Mon May 14 20:29:59 2012 lyoma guillou
*/

static int	_is_num(char c)
{
  return ((c >= '0' && c <= '9'));
}

int		my_getnbr(char *str)
{
  int		i;
  int		x;

  i = 0;
  x = 0;
  while (_is_num(str[i]))
    {
      x = (x * 10) + (str[i] - '0');
      ++i;
    }
  return (x);
}
