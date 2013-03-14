#include <stdlib.h>
#include <stdio.h>
#include "String.h"

int		main(int ac, char **av)
{
  String	test;
  String	ptr;

  if (ac > 1)
    {
      //      char	*str;
      StringInit(&test, av[1]);
            
      printf("Your string is: %s\n", test.c_str(&test));
      
      StringDestroy(&test);
      StringDestroy(&ptr);
      printf("free'd\n");
    }
  return 0;
}
