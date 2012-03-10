/*
** test.c for  in /home/guillo_e//Documents/working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Feb 29 15:05:13 2012 lyoma guillou
** Last update Fri Mar  2 18:52:56 2012 lyoma guillou
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int		main()
{
  DIR		*ptr;
  struct dirent	*dir;
  struct stat	buf;

  stat(".", &buf);
  ptr = opendir("..");
  dir = readdir(ptr);
  while (buf.st_ino != dir->d_ino)
    dir = readdir(ptr);
  printf("%s\n", dir->d_name);
}
