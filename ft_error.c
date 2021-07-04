#include "cheker.h"

void    ft_error(char   *str)
{
    ft_putstr_fd("Error\n",STDERR);
    ft_putstr_fd(str,STDERR);
    ft_putstr_fd("\n",STDERR);
}