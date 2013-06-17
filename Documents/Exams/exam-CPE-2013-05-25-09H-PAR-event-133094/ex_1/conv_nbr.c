#include <stdio.h>
#include <string.h>
#include <strings.h>

int my_pow(int val, int n)
{
  if (n > 0)
    return (val * my_pow(val, n - 1));
  return 1;
}

int get_value(char c, char *base)
{
  int i = 0;
  for (i = 0; base[i]; ++i)
    if (c == base[i])
      return i;
  return 0;
}

int from_base(char *nbr, char* ibase)
{
  int i = 0;
  size_t len = strlen(ibase);
  int x = 0;
  for (i = (nbr[0] == '-') ? 1 : 0; nbr[i]; ++i)
    x += get_value(nbr[i], ibase) * my_pow(len, (strlen(nbr) - (i + 1)));
  return ((nbr[0] == '-') ? -x : x);
}

void to_base(int nb, char *obase)
{
  int len = strlen(obase);
  if (nb < 0)
    printf("-");
  if (nb >= len || nb <= -len)
    to_base(nb / ((nb < 0) ? -len : len), obase);
  printf("%c", obase[((nb < 0) ? -nb % -len : nb % len)]);
}

void conv_nbr(char *nbr, char* ibase, char *obase)
{
  to_base(from_base(nbr, ibase), obase);
}

int main(int ac, char *av[])
{
  if (ac == 4)
    conv_nbr(av[1], av[2], av[3]);
  printf("\n");
  return 0;
}
