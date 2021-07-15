/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_b_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:49:08 by abettach          #+#    #+#             */
/*   Updated: 2021/07/15 14:08:41 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    ft_do_pb_2(t_cheker *c)
{
    int i = 0;
    int j = 0;
    int *tmp;

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
void    ft_do_pb_1(t_cheker *c)
{
    c->list_b[0] = c->list_a[0];
    c->list_b[1] = '\0';
}
void    ft_do_pb(t_cheker *c, int cheker)
{
    int i;

    c->len--;
	c->len_b++;
    c->pb++;
    if (c->pb == 1)
        ft_do_pb_1(c);
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
        ft_putstr_fd("pb\n",1);
}