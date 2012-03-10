/*
** rotone.c for rotone in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Feb 11 18:50:55 2011 exam_user
** Last update Fri Feb 11 19:02:51 2011 exam_user
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

void	rotone(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
	{
	  if (str[i] == 'z' || str[i] == 'Z')
	    str[i] = str[i] - 25;
	  else
	    str[i] = str[i] + 1;
	}
      i++;
    }
  my_putstr(str);
}

int	main(int argc, char **argv)
{
  if (argc == 2)
    rotone(argv[1]);
  my_putchar('\n');
  return (0);
}
