#include <stdlib.h>
#include <stdio.h>
#include "String.h"

int		main(int ac, char **av)
{
  String	test;
  String	ptr;

  if (ac > 1)
    {
      StringInit(&test, av[1]);
      StringInit(&ptr, av[2]);
      printf("Pattern is at position: %d\n", test.find_s(&test, &ptr, 5));
      printf("Works also with a string: %d\n", test.find_c(&test, av[2], 5));

      StringDestroy(&test);
      StringDestroy(&ptr);
      printf("free'd\n");
    }
  return 0;
}
