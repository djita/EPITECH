#include <stdlib.h>
#include <stdio.h>
#include "String.h"

int		main(int ac, char **av)
{
  String	test;

  if (ac > 1)
    {
      StringInit(&test, av[1]);
      printf("res is: %d\n", test.empty(&test));
      
      StringDestroy(&test);
      printf("free'd\n");
    }
  return 0;
}
