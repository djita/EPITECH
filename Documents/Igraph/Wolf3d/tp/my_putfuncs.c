/*
** my_putfuncs.c for wolf3d in 
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Jan 11 15:17:20 2012 lyoma guillou
** Last update Sat Jan 14 17:27:08 2012 lyoma guillou
*/

void		my_putchar(char c)
{
  write(1, &c, 1,);
}

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void		my_putnbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      if (nb <= -10)
	my_putnbr(nb / -10);
      my_putchar((-1 * (nb % 10)) + '0');
    }
  else
    {
      if (nb >= 10)
	my_putnbr(nb / 10);
      my_putchar((nb % 10) + '0');
    }
}
