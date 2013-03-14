#include <stdio.h>
#include "String.h"

int		main(int ac, char **av)
{
  String	test;
  String	ptr;

  if (ac == 2)
    {
      StringInit(&test, av[1]);
      StringInit(&ptr, "");
      ptr.assign_c(&ptr, av[1]);
      printf("Your string: %s\n", ptr.str);
      StringDestroy(&test);
      StringDestroy(&ptr);
      printf("free'd\n");
    }
  return 0;
}
