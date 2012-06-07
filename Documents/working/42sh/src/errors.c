/*
** errors.c for src in /mnt/fedora_std/home/falck_m/Work/42sh/src
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Fri May 11 16:34:04 2012 mickael falck
** Last update Thu May 17 17:39:11 2012 mickael falck
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "errors.h"

/*
 * Since exit is forbidden, this function will not exit.
 *
 */
void		my_err(const char *module, const char *msg, t_e_exit do_exit)
{
  if (msg)
    {
      if (module)
	{
	  write(2, module, strlen(module));
	  write(2, " : ", 3);
	}
      write(2, msg, strlen(msg));
    }
  if (do_exit == EXIT)
    return ;
}
