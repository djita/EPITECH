/*
** my_strncpy.c for my_strncpy in /home/guillo_e//afs/rendu/piscine/Jour_06
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Oct 12 12:02:53 2010 lyoma guillou
** Last update Mon Oct 10 09:36:36 2011 lyoma guillou
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n && src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  if (i >= n)
    dest[i] = '\0';
  return (dest);
}
