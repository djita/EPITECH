/*
** rotone.c for rotone in /exam//rendu/ex_3
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct 23 10:47:09 2010 exam_user
** Last update Sat Oct 23 12:41:53 2010 exam_user
*/

int	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  int	j;

  j = 0;
  while (str[j])
    {
      my_putchar(str[j]);
      j = j + 1;
    }
}

int	rotone(char *lin)
{
  int	i;
  
  i = 0;
  while (lin[i])
    {
      if ((lin[i] >= 'a' && lin[i] <= 'z') || (lin[i] >= 'A' && lin[i] <= 'Z'))
	{
	  if (lin[i] == 'z')
	    lin[i] = 'a';
	  if (lin[i] == 'Z')
	    lin[i] = 'A';
	  else
	    lin[i] = lin[i] + 1;
	}
      i = i + 1;
    }
  my_putstr(lin);
}

int	main(int argc, char **argv)
{
  if (argv[1])
    {
      rotone(argv[1]);
    }
  my_putchar('\n');
  return;
}
