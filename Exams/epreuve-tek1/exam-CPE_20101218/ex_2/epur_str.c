/*
** epur_str.c for epur_str in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Dec 18 10:11:33 2010 exam_user
** Last update Sat Feb  5 15:48:10 2011 lyoma guillou
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

int	charnum(char *str)
{
  int	i;
  int	z;

  i = 0;
  z = 0;
  while (str[i])
    {
      if (str[i] > ' ')
	z++;
      i++;
    }
  return(z);
}

int	epur_str(char *str)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  x = 0;
  y = 0;
  while (str[i])
    {
      if (str[i] <= ' ' && x == 1)
	{
	  if (y == charnum(str))
	    return;
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
  if (argv[2])
    {
      my_putchar('\n');
      return;
    }
  if (argv[1])
    epur_str(argv[1]);
  my_putchar('\n');
}
