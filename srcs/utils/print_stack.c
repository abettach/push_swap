#include "../inc/push_swap.h"

void    print_stack_a(t_cheker *c)
{
    int i = 0;

    while (i < c->len)
    {
        printf("a = %d\n",c->list_a[i]);
        i++;
    }
}
void    print_stack_b(t_cheker *c)
{
    int i = 0;

    while (i < c->len_b)
    {
        printf("b = %d\n",c->list_b[i]);
        i++;
    }
}