/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:36:41 by abettach          #+#    #+#             */
/*   Updated: 2021/07/17 10:57:12 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_push_swap(t_cheker *c)
{
	if (c->len == 2 && c->list_a[0] > c->list_a[1])
		ft_do_sa(c, 0);
	else if (c->len == 3)
		ft_sort_3numbers(c);
	else if (c->len > 3 && c->len <= 5)
		ft_sort_5numbers(c);
	else if (c->len > 5 && c->len <= 500)
	{
		if (c->len <= 100)
			ft_sort_more(c, 5, c->len / 5);
		else if (c->len > 100 && c->len <= 500)
			ft_sort_more(c, 13, c->len / 13);
	}
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
		ft_copy_stack_to_tab(&c, 0);
		ft_sort_table(&c);
		if ((ft_check_error(&c)) == -1)
			write (2, "Error\n", 6);
		if (ft_check_error(&c) == -1 || c.len_ini <= 1)
		{
			ft_free_all(&c, 0);
			exit(0);
		}
		ft_push_swap(&c);
		ft_free_all(&c, 0);
	}
	return (0);
}
