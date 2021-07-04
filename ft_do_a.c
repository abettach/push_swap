#include "cheker.h"

// reverse command[0] && command [1]
void    ft_do_sa(t_cheker *c, int cheker)
{
    int tmp;

    tmp = c->list_a[0];
    c->list_a[0] = c->list_a[1];
    c->list_a[1] = tmp;
    if (cheker == 0)
        ft_putstr_fd("sa\n",1);
}
//rotate a --> b 1 element exp 1 2 3 , ra = 2 3 1
void    ft_do_ra(t_cheker *c, int cheker)
{
    int tmp;
    int i  = 0;

    tmp = c->list_a[0];
    while (c->list_a[i + 1])
    {
        c->list_a[i] = c->list_a[i+1];
        i++;
    }
    c->list_a[i] = tmp;
    if (cheker == 0)
        ft_putstr_fd("ra\n",1);
}
//rra , reverse ra, rotate a <-- by 1 element , expl 1 2 3 4 , rra 4 1 2 3
void    ft_do_rra(t_cheker *c, int cheker)
{
    int *list;
    int i  = 0;
    int j = 1;

    while (c->list_a[i])
        i++;
    list = malloc(sizeof(int) * (i + 1));
    list[0] = c->list_a[i - 1];
    i = 0;
    while (c->list_a[i + 1])
    {
        list[j] = c->list_a[i];
        j++;
        i++;
    }
    list[j] = '\0';
    free(c->list_a);
    c->list_a = list;
    if (cheker == 0)
        ft_putstr_fd("rra\n",1);
}

void    ft_do_pa(t_cheker *c, int cheker)
{
    int i = 0;
    int j = 1;
    int *list;

    while (c->list_a[i])
        i++;
    list = malloc(sizeof(int) * (i + 2));
    list[0] = c->list_b[0];
    i = 0;
    while (c->list_a[i])
    {
        list[j] = c->list_a[i];
        i++;
        j++;
    }
    list[j] = '\0';
    c->list_a = list;
    i = 0;
    while (c->list_b[i + 1])
    {
        c->list_b[i] = c->list_b[i + 1];
        i++;
    }
    c->list_b[i] = '\0';
    if (cheker == 0)
        ft_putstr_fd("pa\n",1);
}
