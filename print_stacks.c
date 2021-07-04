#include "cheker.h"

void    print_stack_a(t_cheker *c)
{
    int i = 0;

    while (c->list_a[i])
    {
        printf("a = %d\n",c->list_a[i]);
        i++;
    }
}
void    print_stack_b(t_cheker *c)
{
    int i = 0;

    while (c->list_b[i])
    {
        printf("a = %d\n",c->list_b[i]);
        i++;
    }
}