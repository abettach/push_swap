/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_more.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:36:34 by abettach          #+#    #+#             */
/*   Updated: 2021/07/17 10:57:40 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_big_nbr(t_cheker *c)
{
	int	ret;
	int	i;

	i = 0;
	ret = c->list_b[0];
	while (i < c->len_b)
	{
		if (c->list_b[i] > ret)
			ret = c->list_b[i];
		i++;
	}
	return (ret);
}

int	get_big_nbr_pos(t_cheker *c, int nbr)
{
	int	i;

	i = 0;
	while (i < c->len_b)
	{
		if (c->list_b[i] == nbr)
			return (i);
		i++;
	}
	return (-1);
}

void	last_sort(t_cheker *c, int pos_num, int midle_stack)
{
	int	big_nbr;
	int	i;
	int	stack_lengt;

	i = 0;
	stack_lengt = c->len_b;
	while (i < stack_lengt)
	{
		midle_stack = c->len_b / 2;
		big_nbr = get_big_nbr(c);
		pos_num = get_big_nbr_pos(c, big_nbr);
		if (pos_num <= midle_stack)
		{
			while (pos_num-- > 0)
				ft_do_rb(c, 0);
			ft_do_pa(c, 0);
		}
		else
		{
			while (pos_num++ < c->len_b)
				ft_do_rrb(c, 0);
			ft_do_pa(c, 0);
		}
		i++;
	}
}

void	ft_sort_more(t_cheker *c, int nbr_chunk, int chunk_size)
{
	int	i;
	int	j;
	int	inc;

	j = 0;
	i = 0;
	inc = chunk_size;
	while (i < nbr_chunk)
	{
		while (j < chunk_size)
		{
			push_a_to_b(c, chunk_size);
			j++;
		}
		chunk_size += inc;
		i++;
	}
	while (c->len)
		ft_do_pb(c, 0);
	last_sort(c, 0, 0);
}
