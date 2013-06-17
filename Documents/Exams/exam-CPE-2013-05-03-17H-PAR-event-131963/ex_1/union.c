#include <unistd.h>
#include <strings.h>

int is_show(char c)
{
  static char tab[256];
  int val = c;

  if (!tab[val])
    {
      tab[val] = 1;
      return 0;
    }
  return 1;
}

void _union(char *src, char *dst)
{
  int i;

  for (i = 0; src[i]; ++i)
    if (0 == is_show(src[i]))
      write(1, &src[i], 1);
  for (i = 0; dst[i]; ++i)
    if (0 == is_show(dst[i]))
      write(1, &dst[i], 1);
}

int main(int ac, char **av)
{
  if (ac == 3)
    _union(av[1], av[2]);
  write(1, "\n", 1);
}
