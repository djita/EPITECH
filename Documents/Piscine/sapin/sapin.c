/*
** sapin.c for sapin in /home/guillo_e//Documents/Piscine/sapin
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Oct  3 15:44:41 2011 lyoma guillou
** Last update Sun Oct  9 19:57:51 2011 lyoma guillou
*/		

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	sapin(int n)
{
  int	cnt;
  int	line;
  int	j;
  int	leaf;
  int	i;
  int	x;

  line = 1;
  leaf = 0;
  x = 0;
  cnt = n;
  while (cnt > 0)
    {
      x = x + n + 3;
      cnt--;
    }
  cnt++;
  while (cnt < x)
    {
      i = 0;
      j = 0;
      if (line - 1 == cnt + 3)
	{
	  line = line - 1;
	  j = j - 2;
	  i = i + 4;
	}
      while(j < (x - line))
	{
	  my_putchar(' ');
	  j++;
	}
      while (i < ((line - 1) * 2 + 1))
	{
	  my_putchar('*');
	  i++;
	}
      my_putchar('\n');
      line++;
      cnt++;
    }
}

int	main()
{
  sapin(3);
}
