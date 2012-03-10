/*
** maff_alpha.c for maff_alpha in /exam//rendu/ex_2
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Nov 12 10:34:41 2011 exam_user
** Last update Sat Nov 12 10:41:28 2011 exam_user
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	main()
{
  char	c;

  c = 'a';
  while (c >= 'a' && c < 'z')
    {
      my_putchar(c);
      c = c - 31;
      if (c >= 'A' && c <= 'Z')
	{
	  my_putchar(c);
	  c = c + 33;
	}
    }
  my_putchar('\n');
  return (0);
}
