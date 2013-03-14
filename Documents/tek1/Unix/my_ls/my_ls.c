/*
** my_ls.c for my_ls in /home/guillo_e//working/unix/my_ls
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Dec  3 22:57:22 2011 lyoma guillou
** Last update Sun Dec  4 16:55:26 2011 lyoma guillou
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include "my_ls.h"

t_data		*init_data(struct dirent *cur_file)
{
  t_data	*file_cont;
  int		ret;

  ret = 0;
  if ( ((file_cont = malloc(sizeof(*file_cont))) == NULL) ||
       ((ret = lstat(cur_file->d_name, &(file_cont->buffer))) == -1) || 
       ((file_cont->user = getpwuid(file_cont->buffer.st_uid)) == NULL) ||
       ((file_cont->grp = getgrgid(file_cont->buffer.st_gid)) == NULL) )
    return (NULL);
  file_cont->file_name = cur_file->d_name;
  return (file_cont);
}

void		my_put_rights(struct stat mode)
{
  if (S_ISREG(mode.st_mode))
    my_putchar('-');
  if (S_ISDIR(mode.st_mode))
    my_putchar('d');
  if (S_ISLNK(mode.st_mode))
    my_putchar('l');
 
  ((mode.st_mode & S_IRUSR) != 0 ) ? my_putchar ('r') : my_putchar('-');
  ((mode.st_mode & S_IWUSR) != 0 ) ? my_putchar ('w') : my_putchar('-');
  ((mode.st_mode & S_IXUSR) != 0 ) ? my_putchar ('x') : my_putchar('-');

  ((mode.st_mode & S_IRGRP) != 0 ) ? my_putchar ('r') : my_putchar('-');
  ((mode.st_mode & S_IWGRP) != 0 ) ? my_putchar ('w') : my_putchar('-');
  ((mode.st_mode & S_IWGRP) != 0 ) ? my_putchar ('x') : my_putchar('-');

  ((mode.st_mode & S_IROTH) != 0 ) ? my_putchar ('r') : my_putchar('-');
  ((mode.st_mode & S_IWOTH) != 0 ) ? my_putchar ('w') : my_putchar('-');
  ((mode.st_mode & S_IXOTH) != 0 ) ? my_putchar ('x') : my_putchar('-');
  my_putchar(' ');
}

void		block_recover(char *str)
{
  DIR		*elem;
  struct dirent	*ptr;
  t_data	*data;
  int		x;

  x = 0;
  elem = opendir(str);
  while ((ptr = readdir(elem)) != NULL)
    {
      data = init_data(ptr);
      x += data->buffer.st_blocks;
    }
  my_putstr("total ");
  my_putnbr(x / 2);
  my_putchar('\n');
  closedir(elem);
}

void		data_recover(char *str)
{
  DIR		*elem;
  struct dirent	*ptr;
  t_data	*data;

  block_recover(str);
  elem = opendir(str);
  while ((ptr = readdir(elem)) != NULL)
    {
      data = init_data(ptr);
      my_put_rights(data->buffer);
      my_putnbr((int) data->buffer.st_nlink);
      my_putchar(' ');
      my_putstr(data->user->pw_name);
      my_putchar(' ');
      my_putstr(data->grp->gr_name);
      my_putchar(' ');
      my_putnbr((int) data->buffer.st_size);
      my_putchar(' ');
      my_putstr(my_strncpy(data->time, ctime(&(data->buffer.st_mtime)) + 4, 12));
      my_putchar(' ');
      my_putstr(ptr->d_name);
      my_putchar('\n');
    }
  closedir(elem);
}
