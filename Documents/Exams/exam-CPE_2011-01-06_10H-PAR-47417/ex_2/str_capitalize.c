/*
** str_capitalize.c for str_capitalize in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jan  6 10:45:37 2011 exam_user
** Last update Thu Jan  6 11:01:04 2011 exam_user
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

int	str_capitalize(char *str)
{
  int	i;
  int	x;

  i = 0;
  while (str[i])
    {
      if (str[i] == ' ')
	{
	  x = 1;
	  i = i + 1;
	}
      if (x == 1)
	{
	  x = 0;
	  if (str[i] >= 'a')
	    str[i] = str[i] - 32;
	}
      i++;
    }
  my_putstr(str);
}

int	main(int argc, char **argv)
{
  if (argv[1] == 0)
    {
      my_putchar('\n');
      return;
    }
  if (argv[2] != 0)
      return;
  str_capitalize(argv[1]);
  my_putchar('\n');
  return;
}
