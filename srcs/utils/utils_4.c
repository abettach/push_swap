/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 10:27:52 by abettach          #+#    #+#             */
/*   Updated: 2021/07/16 11:35:37 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort_table(t_cheker *c)
{
	int	tmp;
	int	i;
	int	j;

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
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_copy_stack_to_tab(t_cheker *c, int checker)
{
	int	i;

	i = 0;
	c->new_tab = malloc(sizeof(int) * (c->len + 1));
	while (i < c->len)
	{
		c->new_tab[i] = c->list_a[i];
		i++;
	}
	c->new_tab[i] = '\0';
	if (ft_check_sort(c) == 1 && checker == 0)
	{
		ft_free_all(c, 0);
		exit(0);
	}
}
