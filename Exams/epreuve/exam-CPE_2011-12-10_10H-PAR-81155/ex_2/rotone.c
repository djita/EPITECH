/*
** rotone.c for rotone in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Dec 10 10:47:28 2011 exam_user
** Last update Sat Dec 10 10:55:54 2011 exam_user
*/

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		is_alpha(char c)
{
  if ((c >= 'a' && c < 'z') || (c >= 'A' && c < 'Z'))
    return (1);
  if (c == 'z' || c == 'Z')
    return (2);
  return (0);
}

void		rotone(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (is_alpha(str[i]) != 0)
	{
	  if (is_alpha(str[i]) == 2)
	    my_putchar(str[i] + 'A' - 'Z');
	  if (is_alpha(str[i]) == 1)
	    my_putchar(str[i] + 1);
	}
      else
	my_putchar(str[i]);
      i = i + 1;
    }
}

int		main(int ac, char **av)
{
  if (ac == 2)
    rotone(av[1]);
  my_putchar('\n');
  return (0);
}
