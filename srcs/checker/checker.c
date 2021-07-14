#include "../inc/push_swap.h"

int		ft_double_check(t_cheker *c)
{
	int i = 0;
	int j= 0;
	while (i < c->len)
	{
		j = i + 1;
		while (j < c->len)
		{
			if (c->list_a[j] == c->list_a[i])
				return 1;
			j++;
		}
		i++;
	}
	return 0;
}



void	ft_sort(t_cheker *c, char *arg)
{
	static int p = 0;
	// printf("%d\n",++p);
		printf("->%s\n",arg);
	if (strcmp(arg,"sa") == 0)
		ft_do_sa(c, 1);
	else if (strcmp(arg,"sb") == 0)
		ft_do_sb(c, 1);
	else if (strcmp(arg,"pa") == 0)
		ft_do_pa(c, 1);
	else if (strcmp(arg,"pb") == 0)
		ft_do_pb(c ,1);
	else if (strcmp(arg,"ra") == 0)
		ft_do_ra(c, 1);
	else if (strcmp(arg,"rb") == 0)
		ft_do_rb(c, 1);
	else if (strcmp(arg,"rra") == 0)
		ft_do_rra(c, 1);
	else if (strcmp(arg,"rrb") == 0)
		ft_do_rrb(c, 1);
}

void	ft_checker(t_cheker *c)
{
	char *arg = NULL;

	while (get_next_line(0,&arg))
	{
		if (strcmp(arg,"sa") == 0)
			ft_do_sa(c, 1);
		else if (strcmp(arg,"sb") == 0)
			ft_do_sb(c, 1);
		else if (strcmp(arg,"pa") == 0)
			ft_do_pa(c, 1);
		else if (strcmp(arg,"pb") == 0)
			ft_do_pb(c ,1);
		else if (strcmp(arg,"ra") == 0)
			ft_do_ra(c, 1);
		else if (strcmp(arg,"rb") == 0)
			ft_do_rb(c, 1);
		else if (strcmp(arg,"rra") == 0)
			ft_do_rra(c, 1);
		else if (strcmp(arg,"rrb") == 0)
			ft_do_rrb(c, 1);
		free(arg);
	}
	// print_stack_a(c);
	if (ft_check_sort(c) == 0)
		ft_putstr_fd("KO\n",1);
	else if (ft_check_sort(c) == 1)
		ft_putstr_fd("OK\n",1);
}

int		main(int ac, char **av)
{

	t_cheker c;

	ft_get_corr_args(&c,av);
	c.list_a = malloc(sizeof(int) * (c.len_ini + 1));
    c.list_b = malloc(sizeof(int) * (c.len_ini + 1));
	ft_copy_args_to_stack(&c);
    c.len = c.len_ini;
    c.len_b = 0;
    c.pb = 0;
	ft_checker(&c);

	return 0;
}