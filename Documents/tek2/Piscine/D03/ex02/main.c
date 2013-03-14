#include <stdio.h>
#include "String.h"

int		main(int ac, char **av)
{
  String	test;
  String	ptr;

  if (ac == 3)
    {
      StringInit(&test, av[1]);
      StringInit(&ptr, av[2]);
      test.append_s(&test, &ptr);
      printf("Your string: %s\n", test.str);
      StringDestroy(&test);
      StringDestroy(&ptr);
      printf("free'd\n");
    }
  return 0;
}
