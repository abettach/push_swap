/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:29:44 by abettach          #+#    #+#             */
/*   Updated: 2021/07/16 11:33:42 by abettach         ###   ########.fr       */
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

int	check_command(char *command)
{
	if (ft_strcmp(command, "sa") != 0 && ft_strcmp(command, "sb") != 0
		&& ft_strcmp(command, "ra") != 0 && ft_strcmp(command, "rb") != 0
		&& ft_strcmp(command, "pa") != 0 && ft_strcmp(command, "pb") != 0
		&& ft_strcmp(command, "rra") != 0 && ft_strcmp(command, "rrb") != 0
		&& ft_strcmp(command, "rr") != 0 && ft_strcmp(command, "rrr") != 0
		&& ft_strcmp(command, "ss") != 0)
		return (-1);
	return (1);
}

void	ft_checker(t_cheker *c)
{
	char	*arg;

	arg = NULL;
	while (get_next_line(0, &arg))
	{
		if (check_command(arg) == 1)
			ft_sort_checker(c, arg);
		else
		{
			write (2, "Error\n", 6);
			free(arg);
			exit(0);
		}
		free(arg);
	}
	if (ft_check_sort(c) == 0)
		ft_putstr_fd("KO\n", 1);
	else if (ft_check_sort(c) == 1)
		ft_putstr_fd("OK\n", 1);
}

int	main(int ac, char **av)
{
	t_cheker	c;

	if (ac > 1)
	{
		ft_get_corr_args(&c, av);
		c.list_a = malloc(sizeof(int) * (c.len_ini + 1));
		c.list_b = malloc(sizeof(int) * (c.len_ini + 1));
		ft_copy_args_to_stack(&c);
		c.len = c.len_ini;
		c.len_b = 0;
		c.pb = 0;
		ft_copy_stack_to_tab(&c, 1);
		ft_sort_table(&c);
		if ((ft_check_error(&c)) == -1)
			write (2, "Error\n", 6);
		if (ft_check_error(&c) == -1 || c.len_ini <= 1)
		{
			ft_free_all(&c, 0);
			exit(0);
		}
		ft_checker(&c);
		ft_free_all(&c, 0);
	}
	return (0);
}
