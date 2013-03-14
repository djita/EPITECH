/*
** my_strndup.c for src in /mnt/fedora_std/home/falck_m/Work/42sh/src
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Sun May 20 13:45:40 2012 mickael falck
** Last update Sun May 20 20:42:23 2012 mickael falck
*/

#include <sys/types.h>
#include <strings.h>
#include <stdlib.h>

char		*my_strndup(const char *buff, size_t len)
{
  char		*ptr;
  size_t	i;

  i = 0;
  ptr = malloc(len + 1);
  bzero(ptr, len + 1);
  while (ptr && i != len && buff[i])
    {
      ptr[i] = buff[i];
      ++i;
    }
  return (ptr);
}
