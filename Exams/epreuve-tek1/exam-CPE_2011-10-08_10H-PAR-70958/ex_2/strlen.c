/*
** strlen.c for strlen in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct  8 10:07:05 2011 exam_user
** Last update Sat Oct  8 10:11:03 2011 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putnbr(int nb)
{
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + '0');
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	main(int ac, char **av)
{
  my_putnbr(my_strlen(av[1]));
  my_putchar('\n');
}
