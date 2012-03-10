/*
** rotone.c for rotone in /exam//rendu/ex_3
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jan  6 11:03:14 2011 exam_user
** Last update Thu Jan  6 11:14:44 2011 exam_user
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
      if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
	{
	  if (str[i] == 'Z' || str[i] == 'z')
	    str[i] = str[i] - 25;
	  else
	    str[i] = str[i] + 1;
	}
      my_putchar(str[i]);
      i++;
    }
}

int	main(int argc, char **argv)
{
  if (argv[1] == 0)
    {
      my_putchar('\n');
      return;
    }
  if (argv[2])
    return;
  rotone(argv[1]);
  my_putchar('\n');
  return;
}
