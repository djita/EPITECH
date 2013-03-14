#include <stdlib.h>
#include <stdio.h>
#include "String.h"

int		main(int ac, char **av)
{
  String	test;
  String	*tab;

  if (ac > 1)
    {
      StringInit(&test, av[1]);
      tab = test.split_s(&test, av[2][0]);
      printf("List:\n");
      for (int i = 0; -1 == tab->empty(&tab[i]); ++i)
	printf("elem %d : %s\n", i, tab[i].str);

      StringDestroy(&test);
      printf("free'd\n");
    }
  return 0;
}
