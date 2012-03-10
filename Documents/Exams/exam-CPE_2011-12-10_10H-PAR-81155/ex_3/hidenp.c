/*
** hidenp.c for hidenp in /exam//rendu/ex_3
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Dec 10 10:58:25 2011 exam_user
** Last update Sat Dec 10 11:03:31 2011 exam_user
*/

void		my_putchar(char c)
{
  write(1, &c, 1);
}

char		hidenp(char *pat, char *src)
{
  int		i;
  int		k;

  i = 0;
  k = 0;
  while (src[i])
    {
      if (src[i] == pat[k])
	k = k + 1;
      if (pat[k] == '\0')
	return (1);
      i = i + 1;
    }
  return (0);
}

int		main(int ac, char **av)
{
  if (ac == 3)
    my_putchar(hidenp(av[1], av[2]) + '0');
  my_putchar('\n');
  return (0);
}
