/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_more_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:36:29 by abettach          #+#    #+#             */
/*   Updated: 2021/07/15 14:29:02 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_scan_top(t_cheker *c, int chunk_size)
{
	int	i;
	int	indice;
	int	moves;

	moves = 0;
	i = 0;
	while (i < c->len)
	{
		indice = 0;
		while (indice < chunk_size)
		{
			if (c->list_a[i] == c->new_tab[indice])
				return (moves);
			indice++;
		}
		i++;
		moves++;
	}
	return (-1);
}

int	get_scan_end(t_cheker *c, int chunk_size)
{
	int	i;
	int	moves;
	int	indice;

	moves = 0;
	i = c->len - 1;
	while (i >= 0)
	{
		indice = 0;
		while (indice < chunk_size)
		{
			if (c->list_a[i] == c->new_tab[indice])
				return (moves);
			indice++;
		}
		i--;
		moves++;
	}
	return (-1);
}

void	push_a_to_b(t_cheker *c, int chunk_size)
{
	int	move_top;
	int	move_end;

	move_top = get_scan_top(c, chunk_size);
	move_end = get_scan_end(c, chunk_size);
	if (move_top <= move_end)
	{
		while (move_top-- > 0)
			ft_do_ra(c, 0);
		ft_do_pb(c, 0);
	}
	else
	{
		while (move_end-- >= 0)
			ft_do_rra(c, 0);
		ft_do_pb(c, 0);
	}
}
