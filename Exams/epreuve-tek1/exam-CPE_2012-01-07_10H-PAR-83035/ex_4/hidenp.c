/*
** hidenp.c for hidenp in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Jan  7 11:13:55 2012 exam_user
** Last update Sat Jan  7 11:17:22 2012 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	hidenp(char *src, char *pat)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (pat[i])
    {
      if (src[j] == pat[i])
	++j;
      if (src[j] == '\0')
	return (1);
      ++i;
    }
  if (pat[0] == '\0' && src[0] == '\0')
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
