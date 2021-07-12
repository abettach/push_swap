#include "../inc/push_swap.h"

//push the first elemt of a to b
void    ft_do_pb(t_cheker *c, int cheker)
{
    int i = 0;
    int j = 0;
    int index = 0;
    int *tmp;

    c->len--;
	c->len_b++;
    c->pb++;

    if (c->pb == 1)
    {
        c->list_b[0] = c->list_a[0];
        c->list_b[1] = '\0';
    }
    if (c->pb > 1)
    {
        tmp = malloc(sizeof(int) * (c->len_b + 1));
        while (i < c->len_b - 1)
        {
            tmp[i] = c->list_b[i];
            i++;
        }
        tmp[i] = '\0';
        c->list_b[0] = c->list_a[0];
        i = 1;
        while (i < c->len_b)
        {
            c->list_b[i] = tmp[j];
            i++;
            j++;
        }
        c->list_b[i] = '\0';
    }
    i = 0;
    while (i < c->len)
    {
        c->list_a[i] = c->list_a[i + 1];
        i++;
    }
    c->list_a[i] = '\0';
    if (cheker == 0)
        ft_putstr_fd("pb\n",1);
}
//sb swap the 2 first element in b
void    ft_do_sb(t_cheker *c, int cheker)
{
    int tmp;

    tmp = c->list_b[0];
    c->list_b[0] = c->list_b[1];
    c->list_b[1] = tmp;
    if (cheker == 0)
        ft_putstr_fd("sb\n",1);
}

void    ft_do_rb(t_cheker *c, int cheker)
{
    int tmp;
    int i  = 0;

    tmp = c->list_b[0];
    while (c->list_b[i + 1])
    {
        c->list_b[i] = c->list_b[i+1];
        i++;
    }
    c->list_b[i] = tmp;
    if (cheker == 0)
        ft_putstr_fd("rb\n",1);
}

void    ft_do_rrb(t_cheker *c, int cheker)
{
    int *list;
    int i  = 0;
    int j = 1;

    while (c->list_b[i])
        i++;
    list = malloc(sizeof(int) * (i + 1));
    list[0] = c->list_b[i - 1];
    i = 0;
    while (c->list_b[i + 1])
    {
        list[j] = c->list_b[i];
        j++;
        i++;
    }
    list[j] = '\0';
    free(c->list_b);
    c->list_b = list;
    if (cheker == 0)
        ft_putstr_fd("rrb\n",1);
}

void    ft_init_stack_b(t_cheker *c)
{
    c->list_b = (int *)malloc (sizeof(int) * 1);
    c->list_b[0] = '\0';
}