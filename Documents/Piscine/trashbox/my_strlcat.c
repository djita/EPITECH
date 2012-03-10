/*
** my_strlcat.c for my_strlcat in /home/guillo_e//Documents/Piscine
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Oct 11 10:27:33 2011 lyoma guillou
** Last update Tue Oct 11 10:39:19 2011 lyoma guillou
*/

int	my_strlcat(char *dest, char *src, int size)
{
  int	i;
  int	len;

  i = 0;
  len = 0;
  while (dest[len])
    len++;
  while ((len + i) < size)
    {
      dest[len + i] = src[i];
      i++;
    }
  dest[len + i] = '\0';
}
