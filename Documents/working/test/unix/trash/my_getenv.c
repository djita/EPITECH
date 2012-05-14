#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char		*my_getenv(char *str)
{
  int		i;

  i = 0;
  while (my_env[i])
    {
      if (!strncmp(str, my_env[i], strlen(str)) 
	  && my_env[i][strlen(str)] == '=')
	return (my_env[i] + strlen(str) + 1);
      ++i;
    }
  return (NULL);
}

