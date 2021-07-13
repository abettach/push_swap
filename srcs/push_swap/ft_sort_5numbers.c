#include "../inc/push_swap.h"

void    ft_sort_5numbers(t_cheker *c)
{
    int median_stack;
    int i = 0;
    int j = 0;
    int len;
    median_stack = c->new_tab[c->len_ini / 2];
    // if (c->new_tab)
    //     free(c->new_tab);
    ft_copy_stack_to_tab(c);
    while (i < c->len_ini)
    {
        if (c->new_tab[i] < median_stack)
            ft_do_pb(c,0);
        else
            ft_do_ra(c, 0);
        i++;
    }
    len = c->len;
    if (len == 2)
    {
        if (c->list_a[0] > c->list_a[1])
            ft_do_sa(c, 0);
        if (c->list_b[0] < c->list_b[1])
            ft_do_sb(c, 0);
        ft_do_pa(c,0);
        ft_do_pa(c,0);
    }
    else
    {
        ft_sort_3numbers(c);
        if (c->list_b[0] < c->list_b[1])
            ft_do_sb(c, 0);
        ft_do_pa(c,0);
        ft_do_pa(c,0);
    }
}

