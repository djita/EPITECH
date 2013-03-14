#include <stdio.h>
#include "String.h"

int		main(int ac, char **av)
{
  String	ptr;

  if (ac == 2)
    {
      StringInit(&ptr, av[1]);
      printf("Your string: %s\n", ptr.str);
      StringDestroy(&ptr);
      printf("free'd\n");
    }
  return 0;
}
