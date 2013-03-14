#include <stdio.h>
#include "String.h"

int		main(int ac, char **av)
{
  String	test;
  String	ptr;

  if (ac == 3)
    {
      int	i = 0;
      StringInit(&test, av[1]);
      StringInit(&ptr, av[2]);
      i = test.compare_s(&test, &ptr);
      if (i == 0)
	printf("Your strings are identical\n");
      else
	printf("Your strings are different\n");

      StringDestroy(&test);
      StringDestroy(&ptr);
      printf("free'd\n");
    }
  return 0;
}
