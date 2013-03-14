#include <stdlib.h>
#include <stdio.h>
#include "String.h"

int		main(int ac, char **av)
{
  String	test;
  String	ptr;

  if (ac > 1)
    {
      size_t	i = 0;
      StringInit(&test, av[1]);
      StringInit(&ptr, "000000000000000");
      
      i = test.copy(&test, ptr.str, atoi(av[2]), atoi(av[3]));
      printf("%lu characters have been copied\nYour result is: '%s'\n", i, ptr.str);
      
      StringDestroy(&test);
      StringDestroy(&ptr);
      printf("free'd\n");
    }
  return 0;
}
