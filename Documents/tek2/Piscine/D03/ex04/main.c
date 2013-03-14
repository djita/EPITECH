#include <stdio.h>
#include "String.h"

int		main(int ac, char **av)
{
  String	test;
  String	ptr;
  char		c = 0;

  if (ac == 3)
    {
      int	i = 0;
      StringInit(&test, av[1]);
      StringInit(&ptr, av[2]);
      printf("Your n-%d string: %s\n", i++, test.str);
      test.append_s(&test, &ptr);
      printf("Your n-%d string: %s\n", i++, test.str);
      test.assign_c(&test, av[2]);
      printf("Your n-%d string: %s\n", i++, test.str);
      test.clear(&test);
      c = test.at(&test, i);
      if (c >= 0)
	printf("Your n-%d character '%c' in string: '%s'\n", i, c, test.str);
      StringDestroy(&test);
      StringDestroy(&ptr);
      printf("free'd\n");
    }
  return 0;
}
