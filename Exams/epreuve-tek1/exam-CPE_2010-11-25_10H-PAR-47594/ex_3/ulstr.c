/*
** ulstr.c for ulstr in /exam//rendu/ex_3
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Nov 25 11:36:42 2010 exam_user
** Last update Thu Nov 25 11:52:34 2010 exam_user
*/

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      write (1, &str[i], 1);
      i = i + 1;
    }
}

int	ulstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
	{
	  if (str[i] >= 'a' && str[i] <= 'z')
	    str[i] = str[i] - 32;
	  else
	    str[i] = str[i] + 32;
	}
      i = i + 1;
    }
  my_putstr(str);
}

int	main(int argc, char **argv)
{
  if (argv[2] || argv[1] == 0)
    {
      write (1, "\n", 1);
      return;
    }
  if (argv[1])
    ulstr(argv[1]);
  write (1, "\n", 1);
}
