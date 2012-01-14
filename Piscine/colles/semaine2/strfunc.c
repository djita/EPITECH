/*
** strfunc.c for colle2-4 in /home/guillo_e//Documents/Piscine/colles/semaine2
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct 15 15:13:46 2011 lyoma guillou
** Last update Sat Oct 15 23:02:51 2011 lyoma guillou
*/

void	refresher(int len, int speed)
{
  int	num;

  num = 0;
  while (num < len)
    {
      my_putchar(' ');
      num = num + 1;
    }
  my_putchar('\r');
  usleep(speed);
}

int	char_verif(char c1, char c2)
{
  if (is_punct(c1) == 1)
    {
      if (is_punct(c2) == 1)
	return (0);
    }
  return (1);
}

int	my_spacer(char *str, int limit)
{
  int	index;
  int	space;
  int	pos;
  int	tru;

  index = 0;
  pos = 0;
  while (str[index])
    {
      space = 0;
      tru = char_verif(str[index], str[index + 1]);
      my_putchar(str[index]);
      while (space < limit && str[index + 1] != '\0' && tru == 1)
	{
	  my_putchar(' ');
	  pos = pos + 1;
	  space = space + 1;
	}
      index = index + 1;
    }
  return (index + pos);
}

int	show_string(char *str, int buffer, int speed)
{
  int	space;
  int	size;

  size = 0;
  space = 0;
  while (42)
    {
      while (size <= buffer)
	{
	  size = my_spacer(str, space);
	  refresher(buffer, speed);
	  space = space + 1;
	}
      while (size > my_strlen(str) && space >= 1)
	{
	  size = my_spacer(str, space);
	  refresher(buffer, speed);
	  space = space - 1;
	}
    }
}
