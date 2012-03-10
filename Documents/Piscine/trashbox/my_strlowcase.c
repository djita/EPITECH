/*
** my_strlowcase.c for my_strlowcase in /home/guillo_e//Documents/Piscine
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Oct 10 14:37:16 2011 lyoma guillou
** Last update Mon Oct 10 14:40:34 2011 lyoma guillou
*/

int	is_bigalpha(char c)
{
  if (c >= 'A' && c <= 'Z')
    return (1);
  return (0);
}

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      str[i] = str[i] + ('a' - 'A');
      i++;
    }
  return (str);
}
