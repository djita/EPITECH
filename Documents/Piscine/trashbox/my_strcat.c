/*
** my_strcat.c for my_strcat in /home/guillo_e//Documents/Piscine
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Oct 11 09:17:29 2011 lyoma guillou
** Last update Tue Oct 11 09:32:15 2011 lyoma guillou
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	len;

  i = 0;
  len = my_strlen(dest);
  while (src[i])
    {
      dest[len + i] = src[i];
      i++;
    }
  dest[len + i] = '\0';
}
