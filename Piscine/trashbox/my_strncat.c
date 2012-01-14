/*
** my_strncat.c for my_strcat in /home/guillo_e//Documents/Piscine
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Oct 11 10:04:19 2011 lyoma guillou
** Last update Tue Oct 11 10:09:41 2011 lyoma guillou
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char	*strncat(char *dest, char *src, int nb)
{
  int	i;
  int	len;

  i = 0;
  len = my_strlen(dest);
  while (i < n)
    {
      dest[len + i] = src[i];
      i++;
    }
  dest[len + i] = '\0';
  return (dest);
}
