#include "../cheker.h"

int     ft_get_case(t_cheker *c)
{
    if (c->list_a[0] > c->list_a[1] && c->list_a[1] < c->list_a[2] && c->list_a[2] > c->list_a[0])
        return 1;
    if (c->list_a[0] > c->list_a[1] && c->list_a[1] > c->list_a[2] && c->list_a[2] < c->list_a[0])
        return 2;
    if (c->list_a[0] > c->list_a[1] && c->list_a[1] < c->list_a[2] && c->list_a[2] < c->list_a[0])
        return 3;
    if (c->list_a[0] < c->list_a[1] && c->list_a[1] > c->list_a[2] && c->list_a[2] > c->list_a[0])
        return 4;
    if (c->list_a[0] < c->list_a[1] && c->list_a[1] > c->list_a[2] && c->list_a[2] < c->list_a[0])
        return 5;
}
void    ft_sort_3numbers(t_cheker *c)
{
    if (ft_get_case(c) == 1)
        ft_do_sa(c,0);
    else if (ft_get_case(c) == 2)
    {
        ft_do_sa(c,0);
        ft_do_rra(c,0);   
    }
    else if (ft_get_case(c) == 3)
        ft_do_ra(c,0);
    else if (ft_get_case(c) == 4)
    {
        ft_do_sa(c,0);
        ft_do_ra(c,0);   
    }
    else if (ft_get_case(c) == 5)
        ft_do_rra(c,0);
}
