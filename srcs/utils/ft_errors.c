/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:49:37 by abettach          #+#    #+#             */
/*   Updated: 2021/07/16 13:18:08 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_check_double(t_cheker *c)
{
	int		i;

	i = 0;
	while (i < c->len)
	{
		if (c->new_tab[i] == c->new_tab[i + 1])
			return (-1);
		i++;
	}
	return (1);
}

int	ft_check_args(t_cheker *c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (c->new_av[i])
	{
		j = 0;
		while (c->new_av[i][j])
		{
			if ((c->new_av[i][j] == '+' || c->new_av[i][j] == '-')
				&& (c->new_av[i][j + 1] < '0' || c->new_av[i][j + 1] > '9'))
				return (-1);
			if ((c->new_av[i][j] < '0' || c->new_av[i][j] > '9')
				&& (c->new_av[i][j] != '-' && c->new_av[i][j] != '+'))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_error(t_cheker *c)
{
	if (ft_check_double(c) == -1 || ft_check_args(c) == -1)
		return (-1);
	return (1);
}
