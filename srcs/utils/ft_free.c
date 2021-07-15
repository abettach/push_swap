/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:49:44 by abettach          #+#    #+#             */
/*   Updated: 2021/07/15 13:49:45 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    ft_free_all(t_cheker *c)
{
    int i = -1;

    while (c->new_av[++i])
        free(c->new_av[i]);
    if (c->new_av)
        free(c->new_av);
    free(c->list_a);
    free(c->list_b);
    free(c->new_tab);
}