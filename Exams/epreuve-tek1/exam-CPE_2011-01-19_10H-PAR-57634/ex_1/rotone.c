/*
** rotone.c for rotone in /exam//rendu/ex_1
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Jan 19 10:34:44 2011 exam_user
** Last update Wed Jan 19 10:48:32 2011 exam_user
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

void	rotone(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
	{
	  if (str[i] == 'z')
	    str[i] = ('a' - 1);
	  if (str[i] == 'Z')
	    str[i] = ('A' - 1);
	  str[i] = str[i] + 1;
	}
      i++;
    }
  my_putstr(str);
}

int	main(int argc, char **argv)
{
  if (argc == 2)
    rotone(argv[1]);
  my_putchar('\n');
  return;
}
