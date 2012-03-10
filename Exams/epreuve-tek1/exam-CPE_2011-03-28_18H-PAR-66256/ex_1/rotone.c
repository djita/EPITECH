/*
** rotone.c for rotone in /exam//rendu/ex_1
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Mar 28 18:01:26 2011 exam_user
** Last update Mon Mar 28 18:19:13 2011 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  write(1, str, i);
}

char	*rotone(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
	{
	  if (str[i] == 'z' || str[i] == 'Z')
	    str[i] = str[i] - ('z' - 'a') - 1;
	  str[i] = str[i] + 1;
	}
      i++;
    }
  my_putstr(str);
  return (0);
}

int	main(int argc, char **argv)
{
  if (argc == 2)
    rotone(argv[1]);
  my_putchar('\n');
  return (0);
}
