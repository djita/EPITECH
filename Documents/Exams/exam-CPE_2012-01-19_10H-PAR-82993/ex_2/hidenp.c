/*
** hidenp.c for hidenp in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jan 19 10:37:44 2012 exam_user
** Last update Thu Jan 19 10:40:59 2012 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	hidenp(char *src, char *dst)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dst[i])
    {
      if (src[j] == dst[i])
	j++;
      i++;
    }
  if (src[j] == '\0')
    return (1);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac == 3)
    my_putchar(hidenp(av[1], av[2]) + '0');
  my_putchar('\n');
  return (0);
}
