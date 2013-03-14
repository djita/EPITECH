#include <stdlib.h>
#include <stdio.h>
#include "String.h"

int		main(int ac, char **av)
{
  String	test;
  //  String	ptr;

  if (ac > 1)
    {
      StringInit(&test, av[1]);
      printf("Pattern is at position: %d\n", test.to_int(&test));

      StringDestroy(&test);
      printf("free'd\n");
    }
  return 0;
}
