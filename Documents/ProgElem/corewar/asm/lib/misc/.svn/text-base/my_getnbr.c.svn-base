/*
** my_getnbr.c for misc in /home/czegan_g/tmp/asm/lib/misc
**
** Made by gaby czegany
** Login   <czegan_g@epitech.net>
**
** Started on  mer. mars 07 06:08:47 2012 gaby czegany
** Last update ven. mars 23 00:21:49 2012 gaby czegany
*/

int     my_getnbr_hexa(const char *hexa)
{
  int   ret;
  int   t;
  int   n;

  ret = 0;
  t = 0;
  n = 0;
  while (*hexa && (n < 16))
  {
    if ((*hexa >= '0') && (*hexa <= '9'))
      t = (*hexa - '0');
    else if ((*hexa >= 'A') && (*hexa <= 'F'))
      t = (*hexa - 'A' + 10);
    else if ((*hexa >= 'a') && (*hexa <= 'f'))
      t = (*hexa - 'a' + 10);
    else
      return (ret);
    n++;
    ret *= 16;
    ret += t;
    hexa++;
    if (n >= 8)
      return (ret);
  }
  return (ret);
}

int             my_getnbr(char *tmp)
{
  const char    *str;
  int           result;
  int           p;

  str = tmp;
  result = 0;
  p = 1;
  while (((*str) == '-') || ((*str) == '+'))
  {
    if (*str == '-')
      p = p * (-1);
    if (*str == '+')
      p = 1;
    str = str + 1;
  }
  if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
    return (my_getnbr_hexa(str + 2));
  while ((*str >= '0') && (*str <= '9'))
  {
    result = (result * 10) + ((*str) - '0');
    str = str + 1;
  }
  return (result * p);
}

int     my_atoi(char *s)
{
  int   nb;

  nb = 0;
  while (*s != '\0')
  {
    if (*s == '-')
      nb = - nb;
    if (*s >= '0' && *s <= '9')
      nb = nb * 10 + *s - 48;
    s++;
  }
  return (nb);
}
