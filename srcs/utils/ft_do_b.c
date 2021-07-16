/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:37:35 by abettach          #+#    #+#             */
/*   Updated: 2021/07/16 14:13:32 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_do_sb(t_cheker *c, int cheker)
{
	int		tmp;

	tmp = c->list_b[0];
	c->list_b[0] = c->list_b[1];
	c->list_b[1] = tmp;
	if (cheker == 0)
		ft_putstr_fd("sb\n", 1);
}

void	ft_do_rb(t_cheker *c, int cheker)
{
	int		tmp;
	int		i;

	i = 0;
	tmp = c->list_b[0];
	while (i < c->len_b - 1)
	{
		c->list_b[i] = c->list_b[i + 1];
		i++;
	}
	c->list_b[i] = tmp;
	c->list_b[++i] = '\0';
	if (cheker == 0)
		ft_putstr_fd("rb\n", 1);
}

void	ft_do_rrb(t_cheker *c, int cheker)
{
	int		*list;
	int		i;
	int		j;

	i = 0;
	j = 1;
	list = malloc(sizeof(int) * (c->len_b + 1));
	list[0] = c->list_b[c->len_b - 1];
	i = 0;
	while (i < c->len_b - 1)
	{
		list[j] = c->list_b[i];
		j++;
		i++;
	}
	list[j] = '\0';
	i = -1;
	while (++i < c->len_b)
		c->list_b[i] = list[i];
	c->list_b[i] = '\0';
	free(list);
	list = NULL;
	if (cheker == 0)
		ft_putstr_fd("rrb\n", 1);
}

void	ft_do_pb_2(t_cheker *c)
{
	int		i;
	int		j;
	int		*tmp;

	i = 0;
	j = 0;
	tmp = malloc(sizeof(int) * (c->len_b + 1));
	while (i < c->len_b - 1)
	{
		tmp[i] = c->list_b[i];
		i++;
	}
	tmp[i] = '\0';
	c->list_b[0] = c->list_a[0];
	i = 1;
	while (i < c->len_b)
	{
		c->list_b[i] = tmp[j];
		i++;
		j++;
	}
	c->list_b[i] = '\0';
	free(tmp);
	tmp = NULL;
}

void	ft_do_pb(t_cheker *c, int cheker)
{
	int		i;

	c->len--;
	c->len_b++;
	c->pb++;
	if (c->pb == 1)
	{
		c->list_b[0] = c->list_a[0];
		c->list_b[1] = '\0';
	}
	else if (c->pb > 1)
		ft_do_pb_2(c);
	i = 0;
	while (i < c->len)
	{
		c->list_a[i] = c->list_a[i + 1];
		i++;
	}
	c->list_a[i] = '\0';
	if (cheker == 0)
		ft_putstr_fd("pb\n", 1);
}
