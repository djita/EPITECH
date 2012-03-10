/*
** maff_alpha.c for maff_alpha in /exam//rendu/ex_1
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Feb 11 17:33:05 2011 exam_user
** Last update Fri Feb 11 17:41:38 2011 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	maff_alpha()
{
  char	c;

  c = 'a';
  while (c >= 'a' && c <= 'z')
    {
      my_putchar(c);
      c = c - 31;
      while (c >= 'A' && c <= 'Z')
	{
	  my_putchar(c);
	  c = c + 33;
	}
    }
  my_putchar('\n');
}

int	main()
{
  maff_alpha();
  return (0);
}
