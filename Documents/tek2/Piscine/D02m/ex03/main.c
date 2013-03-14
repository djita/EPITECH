#include "func_ptr_enum.h"
#include "func_ptr.h"

int	main()
{
  char	*str = "J'utilise les pointeurs sur fonctions !";

  do_action(PRINT_NORMAL, str);
  do_action(PRINT_REVERSE, str);
  do_action(PRINT_UPPER, str);
  do_action(PRINT_42, str);

  return (0);
}
