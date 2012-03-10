/*
** maff_alpha.c for maff_alpha in /exam//rendu/ex_1
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Nov 25 10:38:08 2010 exam_user
** Last update Thu Nov 25 10:55:19 2010 exam_user
*/

int	my_putchar(char c)
{
  write (1, &c, 1);
}

int	maff_alpha()
{
  char c;

  c = 'a';
  while (c >= 'a' && c < 'z')
    {
      my_putchar(c);
      c = c - 31;
      while (c > 'A' && c <= 'Z')
	{
	  my_putchar(c);
	  c = c + 33;
	}
    }
}

int	main()
{
  maff_alpha();
  my_putchar('\n');
}
