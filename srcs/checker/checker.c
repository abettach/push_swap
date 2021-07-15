/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:29:44 by abettach          #+#    #+#             */
/*   Updated: 2021/07/15 14:17:49 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort_checker_more(t_cheker *c, char *arg)
{
	if (strcmp(arg, "ra") == 0)
		ft_do_ra(c, 1);
	else if (strcmp(arg, "rb") == 0)
		ft_do_rb(c, 1);
	else if (strcmp(arg, "rr") == 0)
	{
		ft_do_ra(c, 1);
		ft_do_rb(c, 1);
	}
	else if (strcmp(arg, "rra") == 0)
		ft_do_rra(c, 1);
	else if (strcmp(arg, "rrb") == 0)
		ft_do_rrb(c, 1);
	else if (strcmp(arg, "rrr") == 0)
	{
		ft_do_rra(c, 1);
		ft_do_rrb(c, 1);
	}
}

void	ft_sort_checker(t_cheker *c, char *arg)
{
	if (strcmp(arg, "sa") == 0)
		ft_do_sa(c, 1);
	else if (strcmp(arg, "sb") == 0)
		ft_do_sb(c, 1);
	else if (strcmp(arg, "ss") == 0)
	{
		ft_do_sa(c, 1);
		ft_do_sb(c, 1);
	}
	else if (strcmp(arg, "pa") == 0)
		ft_do_pa(c, 1);
	else if (strcmp(arg, "pb") == 0)
		ft_do_pb(c, 1);
	else
		ft_sort_checker_more(c, arg);
}

void	ft_checker(t_cheker *c)
{
	char	*arg;

	arg = NULL;
	while (get_next_line(0, &arg))
	{
		ft_sort_checker(c, arg);
		free(arg);
	}
}

int	main(int ac, char **av)
{
	t_cheker	c;

	ft_get_corr_args(&c, av);
	c.list_a = malloc(sizeof(int) * (c.len_ini + 1));
	c.list_b = malloc(sizeof(int) * (c.len_ini + 1));
	ft_copy_args_to_stack(&c);
	c.len = c.len_ini;
	c.len_b = 0;
	c.pb = 0;
	ft_checker(&c);
	if (ft_check_sort(&c) == 0)
		ft_putstr_fd("KO\n", 1);
	else if (ft_check_sort(&c) == 1)
		ft_putstr_fd("OK\n", 1);
	return (0);
}
