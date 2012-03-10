/*
** epur_str.c for epur_str in /exam//rendu/ex_5
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct 23 12:28:33 2010 exam_user
** Last update Sat Oct 23 14:17:06 2010 exam_user
*/

int	my_putchar(char c)
{
  write (1, &c, 1);
}

int	my_putstr(char *str)
{
  int	x;

  x = 0;
  while (str[x])
    {
      my_putchar(str[x]);
      x = x + 1;
    }
}

int	epur_str(char *chain)
{
  int	i;

  i = 0;
  while (chain[i])
    {
      while (chain[i] >= 33 && chain[i] <= 126)
	{
	  my_putchar(chain[i]);
	  i = i + 1;
	}
      while (chain[i] == ' ')
	{
	  i = i + 1;
	}
    }
}

int	main(int argc, char **argv)
{
  if (argv[1])
    {
      if (argv[2])
	{
	  my_putchar('\n');
	  return;
	}
      epur_str(argv[1]);
    }
  my_putchar('\n');
  return;
}
