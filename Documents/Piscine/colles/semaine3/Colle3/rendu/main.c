/*
** main.c for colle3.c in /home/guillo_e//working/colle
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sun Oct 30 05:48:20 2011 lyoma guillou
** Last update Sun Oct 30 05:49:43 2011 lyoma guillou
*/

#include "my.h"

int		main()
{
  char		buffer[BUFFER_LEN + 1];
  int		len;

  len = 0;
  sleep(2);
  if (len = read(0, buffer, BUFFER_LEN))
    {
      buffer[len] = '\0';
      what_is_this_glue(buffer);
    }
  return (0);
}
