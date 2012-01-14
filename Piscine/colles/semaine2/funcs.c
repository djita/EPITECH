/*
** funcs.c for colle2-4 in /home/guillo_e//Documents/Piscine/colles/semaine2
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct 15 14:54:58 2011 lyoma guillou
** Last update Sat Oct 15 20:22:14 2011 lyoma guillou
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int	is_alphanum(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (1);
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int	is_punct(char c)
{
  if (c == '.' || c == ',' || c == ';' || c == ':' || c == 39 || c == '?' || c == '!')
    return (1);
  if (c == '\'' || c == '?' || c == '!')
    return (1);
  return (0);
}

