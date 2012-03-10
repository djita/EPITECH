/*
** colle.c for colle in /home/guillo_e//Documents/Piscine/colle
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct  8 15:06:35 2011 lyoma guillou
** Last update Sat Oct  8 15:54:45 2011 lyoma guillou
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

char	is_border(int i, int j, int x, int y)
{
  if (i == 0 || j == 0 || i == x || j == y)
    {
      if ((i == 0 && j == 0) || (i == x && j == y))
	return ('A');
      if ((i == 0 && j == y) || (i == x && j == 0))
	return ('C');
      else
	return ('B');
    }
  else
    return (' ');
}

int	colle(int x, int y)
{
  int	i;
  int	j;
  char	c;

  i = 0;
  j = 0;
  c = ' ';
  while (j < y)
    {
      i = 0;
      while (i < x)
	{
	  c = is_border(i, j, x, y);
	  my_putchar(c);
	  i++;
	}
      j++;
      my_putchar('\n');
    }
}

int	main()
{
  colle(5, 3);
  return (0);
}
