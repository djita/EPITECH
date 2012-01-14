/*
** my_funcs.c for convert_base in /home/guillo_e//Documents/Piscine
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Oct 12 21:42:17 2011 lyoma guillou
** Last update Wed Oct 12 21:47:02 2011 lyoma guillou
*/

void			my_putchar(char c)
{
  write(1, &c, 1);
}

void			my_putstr(char *str)
{
  int			i;

  i = 0;
  while (str[i])
    i++;
  write(1, str, i);
}

int			my_strlen(char *str)
{
  int			i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int     my_power_rec(int nb, int power)
{
  if (power < 0)
    return (0);
  if (power == 0)
    return (1);
  if (power > 0)
    nb = my_power_rec(nb, power - 1) * nb;
  return (nb);
}
