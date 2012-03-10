/*
** hidenp.c for hidenp in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct 15 10:35:28 2011 exam_user
** Last update Sat Oct 15 10:43:20 2011 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	hidenp(char *fnd, char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (fnd[j] == str[i])
	j++;
      i++;
    }
  if (fnd[j] == '\0')
    return (1);
  else
    return (0);
}

int	main(int argc, char **argv)
{
  int	x;

  x = 0;
  if (argc == 3)
    {
      x = hidenp(argv[1], argv[2]);
      my_putchar(x + '0');
    }
  my_putchar('\n');
  return (0);
}
