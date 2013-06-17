#include <stdlib.h>
#include <stdio.h>
#include ".sopipa.h"

void	sopipa(char *file1, char *cmd1, char *cmd2, char *file2)
{
  void	*ptr;
  char	buff[8192];
  int	(*fnc)(const char*);

  ptr = RAS;
  sprintf(buff, "< %s %s | %s > %s", file1, cmd1, cmd2, file2);
  fnc = ptr;
  fnc(buff);
}

int	main(int ac, char **av)
{
  if (ac == 5)
    sopipa(av[1], av[2], av[3], av[4]);
  return 0;
}
