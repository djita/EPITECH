#include <stdio.h>
#include <string.h>

int wdmatch(char *src, char *dst)
{
  int i = 0;
  size_t j = 0;
  for (i = 0; dst[i]; ++i)
    if (src[j] == dst[i])
      ++j;
  return (j == strlen(src) && j != 0);
}

int main(int ac, char *av[])
{
  if (ac == 3)
    if (1 == wdmatch(av[1], av[2]))
      printf("%s", av[1]);
  printf("\n");
  return 0;
}
