/*
** utls.c for cpe-rush1-2016-guillo_e in /home/czegan_g/Documents/dev/school/report/svn/cpe-rush1-2016-guillo_e
** 
** Made by gaby czegany
** Login   <czegan_g@epitech.net>
** 
** Started on  Sat Nov 26 22:14:54 2011 gaby czegany
** Last update Sun Nov 27 17:57:43 2011 lyoma guillou
*/

/*
** {{{1 caractères valides pour un type
*/

int             is_type_range(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
      (c >= '0' && c <= '9') || (c == '-' || c == '_'))
    return (1);
  if (c == ' ')
    return (2);
  return (0);
}

char		*my_strcpy(char *dst, char *src)
{
  int		i;

  i = 0;
  while (src[i])
    {
      dst[i] = src[i];
      i++;
    }
  dst[i] = '\0';
  return (dst);
}
