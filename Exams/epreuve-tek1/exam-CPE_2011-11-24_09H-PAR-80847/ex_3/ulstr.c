/*
** ulstr.c for ulstr in /exam//rendu/ex_3
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Nov 24 09:22:55 2011 exam_user
** Last update Thu Nov 24 09:33:14 2011 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	put_alpha(char c)
{
  if (c >= 'a' && c <= 'z')
    my_putchar(c - ('a' - 'A'));
  else if (c >= 'A' && c <= 'Z')
    my_putchar(c + ('a' - 'A'));
  else
    my_putchar(c);
}

void	ulstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      put_alpha(str[i]);
      i++;
    }
}

int	main(int ac, char **av)
{
  if (ac == 2)
    ulstr(av[1]);
  my_putchar('\n');
  return (0);
}
