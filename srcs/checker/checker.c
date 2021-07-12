#include "../inc/push_swap.h"

int		ft_double_check(t_cheker *c)
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

int	ft_check_sort(t_cheker *c)
{
	int i = 0;
	int j = 0;

	while (c->list_a[i + 1])
	{
		if (c->list_a[i] > c->list_a[i + 1])
			return 0;
		i++;
	}
	return 1;
}

void	ft_sort(t_cheker *c)
{
	int i = 0;

	while (c->command[i])
	{
		if (c->pb == 0)
			ft_init_stack_b(c);
		if (ft_strcmp(c->command[i],"start") == 0)
			i++;
		if (ft_strcmp(c->command[i],"sa") == 0)
			ft_do_sa(c, 1);
		else if (ft_strcmp(c->command[i],"sb") == 0)
			ft_do_sb(c, 1);
		else if (ft_strcmp(c->command[i],"ss") == 0)
		{
			ft_do_sa(c, 1);
			ft_do_sb(c, 1);
		}
		else if (ft_strcmp(c->command[i],"pa") == 0)
			ft_do_pa(c, 1);
		else if (ft_strcmp(c->command[i],"pb") == 0)
			ft_do_pb(c ,1);
		else if (ft_strcmp(c->command[i],"ra") == 0)
			ft_do_ra(c, 1);
		else if (ft_strcmp(c->command[i],"rb") == 0)
			ft_do_rb(c, 1);
		else if (ft_strcmp(c->command[i],"rr") == 0)
		{
			ft_do_ra(c, 1);
			ft_do_rb(c, 1);
		}
		else if (ft_strcmp(c->command[i],"rra") == 0)
			ft_do_rra(c, 1);
		else if (ft_strcmp(c->command[i],"rrb") == 0)
			ft_do_rrb(c, 1);
		else if (ft_strcmp(c->command[i],"rrr") == 0)
		{
			ft_do_rra(c, 1);
			ft_do_rrb(c, 1);
		}
		else if (!c->command[i])
			break;
		i++;
	}
}

void	ft_checker(t_cheker *c)
{
	c->command = malloc(sizeof(char *) * 1);
	c->command[0] = ft_strdup("start");
	c->command[1] = NULL;
	while (1)
	{
		get_next_line(0,&c->tab);
		if (ft_strcmp(c->tab,"\0") == 0)
			break;
		ft_strjoin_command(c,c->tab);
		free(c->tab);
	}
	ft_sort(c);
	if (ft_check_sort(c) == 0)
		ft_putstr_fd("KO\n",1);
	else
		ft_putstr_fd("OK\n",1);
}

int		main(int ac, char **av)
{

	t_cheker c;

	ft_get_args(&c,av);
    c.len_ini = ft_get_len_ini(av);
	c.len = ft_get_len_ini(av);
	c.list_b = malloc(sizeof(int) * (c.len_ini + 1));
    c.len_b = 0;
    c.pb = 0;
	ft_checker(&c);

	return 0;
}