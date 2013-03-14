/*
** main.c for tests in /home/lastmikoi/Work/malloc/tests
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  jeu. janv. 31 17:39:31 2013 mickael falck
** Last update jeu. janv. 31 18:52:27 2013 mickael falck
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define __USE_GNU
#include <dlfcn.h>

void		*malloc(size_t size);

int main(int ac, char *av[])
{

  char	*malloc_verbose;
  void *(*selected_malloc)(size_t);
  void (*selected_free)(void *);
  size_t	size;
  void		*start;
  void		*ptr;
  if (ac >= 2 && av[1][0] == 'm')
    {
      malloc_verbose = "MyMalloc";
      selected_malloc = &malloc;
      selected_free = &free;
    }
  else
    {
      malloc_verbose = "libCMalloc";
      selected_malloc = dlsym(RTLD_NEXT, "malloc");
      selected_free = dlsym(RTLD_NEXT, "free");
    }
  start = sbrk(0);
  printf("PID : %d\n", getpid());
  printf("&%s: %p\n", malloc_verbose, selected_malloc);
  size = 40960;
  ptr = selected_malloc(size);
  printf("%s(%lu)= %p (=%ld bytes @%p, map_size=%ld\n", malloc_verbose, size, (void *)(ptr - start), ptr - start, ptr, sbrk(0) - start);
  selected_free(ptr);
  ptr = selected_malloc(size);
  printf("%s(%lu)= %p (=%ld bytes @%p, map_size=%ld\n", malloc_verbose, size, (void *)(ptr - start), ptr - start, ptr, sbrk(0) - start);
  selected_free(ptr);
  ptr = selected_malloc(size);
  printf("%s(%lu)= %p (=%ld bytes @%p, map_size=%ld\n", malloc_verbose, size, (void *)(ptr - start), ptr - start, ptr, sbrk(0) - start);
  selected_free(ptr);
  ptr = selected_malloc(size);
  printf("%s(%lu)= %p (=%ld bytes @%p, map_size=%ld\n", malloc_verbose, size, (void *)(ptr - start), ptr - start, ptr, sbrk(0) - start);
  selected_free(ptr);
  ptr = selected_malloc(size);
  printf("%s(%lu)= %p (=%ld bytes @%p, map_size=%ld\n", malloc_verbose, size, (void *)(ptr - start), ptr - start, ptr, sbrk(0) - start);
  selected_free(ptr);
  return 0;
}

/*
 * FUCK
 *
 * THE
 *
 * POLICE
 */
#include "../chunk_list.c"
#include "../malloc.c"
#include "../realloc.c"
