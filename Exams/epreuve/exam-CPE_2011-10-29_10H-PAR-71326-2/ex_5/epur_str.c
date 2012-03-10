/*
** epur_str.c for epur_str in /exam//rendu/ex_5
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct 29 10:27:35 2011 exam_user
** Last update Sat Oct 29 10:48:21 2011 exam_user
*/

int	is_alphanum(char c)
{
  if (c >= '!' && c <= '~')
    return (1);
  return (0);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	count_char(char *str)
{
  int	i;
  int	cnt;

  i = 0;
  cnt = 0;
  while (str[i])
    {
      if (is_alphanum(str[i]) == 1)
	cnt++;
      i++;
    }
  return (cnt);
}

void	epur_str(char *str)
{
  int	i;
  int	word;
  int	cnt;

  i = 0;
  word = 0;
  cnt = count_char(str);
  while (str[i])
    {
      if (is_alphanum(str[i]) == 1)
	{
	  my_putchar(str[i]);
	  word = 1;
	  cnt--;
	}
      if (is_alphanum(str[i]) == 0 && word == 1 && cnt > 0)
	{
	  my_putchar(' ');
	  word = 0;	      
	}
      i++;
    }
}

int	main(int ac, char **av)
{
  if (ac == 2)
    epur_str(av[1]);
  my_putchar('\n');
  return (0);
}
