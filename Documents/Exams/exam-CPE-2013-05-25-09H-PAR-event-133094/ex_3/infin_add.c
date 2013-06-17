#include <stdio.h>
#include <stdlib.h>

void infin_add(char *nb1, char *nb2)
{
  long long int x = atoll(nb1) + atoll(nb2);
  printf("%lli", x);
}

int main(int ac, char *av[])
{
  if (ac == 3)
    infin_add(av[1], av[2]);
  printf("\n");
  return 0;
}
