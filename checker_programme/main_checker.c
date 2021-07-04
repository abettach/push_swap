#include "../cheker.h"

int		main(int ac, char **av)
{

	t_cheker c;

	ft_get_args(&c,av);
	ft_checker(&c);

	return 0;
}