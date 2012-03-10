/*
** hidenp.c for hidenp in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct 23 11:28:45 2010 exam_user
** Last update Sat Oct 23 12:49:35 2010 exam_user
*/

int	my_putchar(char c)
{
  write(1, &c, 1);
}

int	hidenp(char *pat, char *chain)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (chain[j])
    {
      if (pat[i] == chain[j])
	{
	  if (pat[i + 1] == '\0')
	    {
	      my_putchar('1');
	      return;
	    }
	  i = i + 1;
	}
      j = j + 1;
    }
  my_putchar('0');
}

int	main(int argc, char **argv)
{
  if (argv[0])
    { 
      if (argv[1])
	{
	  if (argv[3])
	    {	  
	      my_putchar('\n');
	      return;
	    }
	  if (argv[2])
	    hidenp(argv[1], argv[2]);	  
	}
    }
  my_putchar('\n');
  return;
}
