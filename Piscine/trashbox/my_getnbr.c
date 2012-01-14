/*
** my_getnbr.c for my_getnbr in /home/guillo_e//afs/rendu/piscine/Jour_04/ex_04
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Oct  6 10:56:32 2011 lyoma guillou
** Last update Fri Oct  7 21:27:58 2011 lyoma guillou
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int     is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (-1);
}

void    my_putnbr(int nb)
{
  int           ten;
  int           neg;
  char          zero;

  ten = 10;
  neg = -1;
  zero = '0';
  if (nb < 0)
    {
      my_putchar('-');
      if (nb <= -ten)
	my_putnbr(nb / -ten);
      my_putchar((neg * (nb % -ten)) + zero);
    }
  else
    {
      if (nb >= ten)
	my_putnbr(nb / ten);
      my_putchar((nb % ten) + zero);
    }
}

int     is_over_int(int nb, char sp)
{
  int   i;

  i = 214748364;
  if (nb <= i || nb >= -i)
    {
      my_putnbr(nb);
      my_putchar('\n');
      if (nb <= -i && sp > '8')
	return (-1);
      if (nb >= i && sp > '7')
	return (-1);
    }
  return(0);
}

int     my_getnbr(char *str)
{
  int   i;
  int   nb;
  int   neg;

  nb = 0;
  i = 0;
  neg = 1;
  while (str[i])
    {
      if (str[i] == '-' && nb == 0)
        neg = -neg;
      if (is_num(str[i]) == 1)
        {
	  if (is_over_int((nb * neg), str[i]) == -1)
            return (0);
          nb = nb * 10;
          nb = nb + (str[i] - '0');
        }
      if (str[i] != '-' && str[i] != '+' && is_num(str[i]) == -1)
        return (nb * neg);
      i++;
    }
  return (nb * neg);
}

int	main(int ac, char **av)
{
  my_putnbr(my_getnbr(av[1]));
}
