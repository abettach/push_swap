#include "../inc/push_swap.h"

void    ft_sort_table(t_cheker *c)
{
    int tmp;
    int i;
    int j = 0;
        i = 0;

    while (i < c->len - 1)
    {
        j = 0;
        while (j < c->len - 1)
        {
            if (c->new_tab[j] > c->new_tab[j + 1])
            {
                tmp = c->new_tab[j];
                c->new_tab[j] = c->new_tab[j + 1];
                c->new_tab[j + 1] = tmp;
                i = 0;
                break;
            }
            j++;
        }
        i++;
    }
}

void    ft_copy_stack_to_tab(t_cheker *c)
{
    int i = 0;

    c->new_tab = malloc(sizeof(int) * (c->len + 1));
    while (i < c->len)
    {
        c->new_tab[i] = c->list_a[i];
        i++;
    }
    c->new_tab[i] = '\0';
}

int		ft_double_check2(t_cheker *c)
{
	int i = 0;
	int j= 0;
	while (c->list_a[i])
	{
		j = i + 1;
		while (c->list_a[j])
		{
			if (c->list_a[j] == c->list_a[i])
				return 1;
			j++;
		}
		i++;
	}
	return 0;
}

void    ft_push_swap(t_cheker *c)
{
    // if (ft_double_check2(c) == 1)
	// {
	// 	ft_error("Error\n");
	// 	return  ;
	// }
    ft_sort_table(c);

    if (c->len < 2)
        return ;
    if (c->len == 2)
    {   
        if(c->list_a[0] > c->list_a[1])
            ft_do_sa(c,0);
    }
    else if (c->len == 3)
        ft_sort_3numbers(c);
    else if (c->len == 4 || c->len == 5)
        ft_sort_5numbers(c);
    else if (c->len > 5 && c->len <= 500)
    {
        if (c->len <= 100)
            ft_sort_more(c, 5, c->len / 5);
        else if (c->len > 100 && c->len <= 500)
            ft_sort_more(c, 13, c->len / 13);
    }
}

int     main(int ac, char **av)
{
    	t_cheker c;

	ft_get_corr_args(&c,av);
    c.list_a = malloc(sizeof(int) * (c.len_ini + 1));
    c.list_b = malloc(sizeof(int) * (c.len_ini + 1));
	ft_copy_args_to_stack(&c);
    c.len = c.len_ini;
    // printf("len = %d\n",c.len);
    ft_copy_stack_to_tab(&c);
    c.len_b = 0;
    c.pb = 0;
	ft_push_swap(&c);
    //print_stack_b(&c);

	return 0;
}