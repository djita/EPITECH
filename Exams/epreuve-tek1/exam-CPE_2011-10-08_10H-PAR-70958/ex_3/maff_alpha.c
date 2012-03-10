/*
** maff_alpha.c for maff_alpha in /exam//rendu/ex_3
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct  8 10:13:59 2011 exam_user
** Last update Sat Oct  8 10:19:49 2011 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	is_alpha(char c)
{
  if (c >= 'a' && c <= 'z')
    return (2);
  if(c >= 'A' && c <= 'Z')
    return (1);
  return (0);
}

void	maff_alpha()
{
  char	c;

  c = 'a';
  while (is_alpha(c) == 2)
    {
      my_putchar(c);
      c = c - 31;
      while (is_alpha(c) == 1)
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
}
