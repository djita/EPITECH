/*
** common_str.c for common_str in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Mar 10 12:18:49 2012 exam_user
** Last update Sat Mar 10 12:33:21 2012 exam_user
*/

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putnbr(int nb)
{
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + '0');
}

int		is_exist(char c, char *dst)
{
  int		i;

  i = 0;
  while (dst[i])
    {
      if (c == dst[i])
	return (1);
      ++i;
    }
  return (0);
}

void		common_str(char *src, char *dst)
{
  int		i;
  int		x;

  i = 0;
  x = 0;
  while (src[i])
    {
      if (is_exist(src[i], dst))
	++x;
      ++i;
    }
  my_putnbr(x);
}

int		main(int ac, char **av)
{
  if (ac == 3)
    common_str(av[1], av[2]);
  my_putchar('\n');
  return (0);
}
