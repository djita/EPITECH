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
      test.insert_s(&test, 13, &ptr);
      //test.insert_c(&test, 13, av[2]);
      printf("Pattern is at position: %s\n", test.str);
      printf("Works also with a string: %s\n", test.str);

      StringDestroy(&test);
      StringDestroy(&ptr);
      printf("free'd\n");
    }
  return 0;
}
