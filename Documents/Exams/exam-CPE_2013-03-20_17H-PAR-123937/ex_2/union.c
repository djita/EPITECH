#define _BSD_SOURCE

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void my_putchar(char c)
{
  write(1, &c, 1);
}

int is_capt(char c)
{
  static int tab[256];
  int i = c;
  if (tab[i] == 0)
    {
      tab[i] = 1;
      my_putchar(c);
      return 0;
    }
  return 1;
}

void _union(char *s1, char *s2)
{
  int i = 0;
  for (i = 0; s1[i]; ++i)
    is_capt(s1[i]);
  for (i = 0; s2[i]; ++i)
    is_capt(s2[i]);
}

int main(int ac, char **av)
{
  if (ac > 1)
    {
      char *buff = strdup(av[1]);
      char *buff2 = strdup(av[2]);
      _union(buff, buff2);
    }
  my_putchar('\n');
  return 0;
}
