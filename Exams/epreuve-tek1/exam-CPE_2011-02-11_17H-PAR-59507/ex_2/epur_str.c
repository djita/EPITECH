/*
** epur_str.c for epur_str in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Feb 11 17:38:57 2011 exam_user
** Last update Fri Feb 11 18:28:38 2011 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	charnum(char *str)
{
  int	i;
  int	x;

  i = 0;
  x = 0;
  while (str[i])
    {
      if (str[i] > ' ')
	x++;
      i++;
    }
  return (x);
}

void	epur_str(char *str)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  x = 0;
  y = 0;
  while (str[i])
    {
      if (x == 1)
	{
	  if (str[i] <= ' ' && y < charnum(str))
	    my_putchar(' ');
	  x = 0;
	}
      if (str[i] > ' ')
	{
	  my_putchar(str[i]);
	  x = 1;
	  y++;
	}
      i++;
    }
}

int	main(int argc, char **argv)
{
  if (argc == 2)
    epur_str(argv[1]);
  my_putchar('\n');
  return (0);
}
