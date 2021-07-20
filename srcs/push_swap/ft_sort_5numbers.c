/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:36:25 by abettach          #+#    #+#             */
/*   Updated: 2021/07/20 20:18:18 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort_5numbers_2(t_push *c)
{
	int	len;

	len = c->len;
	if (len == 2)
	{
		if (c->list_a[0] > c->list_a[1])
			ft_do_sa(c, 0);
		if (c->list_b[0] < c->list_b[1])
			ft_do_sb(c, 0);
		ft_do_pa(c, 0);
		ft_do_pa(c, 0);
	}
	else
	{
		ft_sort_3numbers(c);
		if (c->list_b[0] < c->list_b[1])
			ft_do_sb(c, 0);
		ft_do_pa(c, 0);
		ft_do_pa(c, 0);
	}
}

void	ft_sort_5numbers(t_push *c)
{
	int	median_stack;
	int	i;
	int	j;

	i = 0;
	j = 0;
	median_stack = c->new_tab[c->len_ini / 2];
	free(c->new_tab);
	c->new_tab = NULL;
	ft_copy_stack_to_tab(c, 0);
	while (i < c->len_ini)
	{
		if (c->new_tab[i] < median_stack)
			ft_do_pb(c, 0);
		else
			ft_do_ra(c, 0);
		i++;
	}
	ft_sort_5numbers_2(c);
}
