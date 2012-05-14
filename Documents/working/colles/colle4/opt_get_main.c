#include <string.h>
#include "opt_get.h"

/*
t_bool           opt_isset(t_opt* options, const char* option);
const char **opt_args(t_opt* options, const char* option);
t_opt           *opt_get(int ac, char **av, const char* format);
t_pos           opt_pos(t_opt* options, const char* option);
void            opt_free(t_opt* options);
*/

int main(int ac, char **av)
{
        if (ac > 2)
        {
        t_opt   *res = opt_get(ac - 1, av + 1, av[1]);

        if (res == NULL)
          puts("Invalid");
        else
          puts("Valid");
        return 0;
        }
}