/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:37:35 by abettach          #+#    #+#             */
/*   Updated: 2021/07/15 14:07:28 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    ft_do_sb(t_cheker *c, int cheker)
{
    int tmp;

    tmp = c->list_b[0];
    c->list_b[0] = c->list_b[1];
    c->list_b[1] = tmp;
    if (cheker == 0)
        ft_putstr_fd("sb\n",1);
}

void    ft_do_rb(t_cheker *c, int cheker)
{
    int tmp;
    int i  = 0;

    tmp = c->list_b[0];
    while (i < c->len_b - 1)
    {
        c->list_b[i] = c->list_b[i+1];
        i++;
    }
    c->list_b[i] = tmp;
    c->list_b[++i] = '\0';
    if (cheker == 0)
        ft_putstr_fd("rb\n",1);
}

void    ft_do_rrb(t_cheker *c, int cheker)
{
    int *list;
    int i  = 0;
    int j = 1;

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
    i = 0;
    while (i < c->len_b)
    {
        c->list_b[i] = list[i];
        i++;
    }
    c->list_b[i] = '\0';
    free(list);
    list = NULL;
    if (cheker == 0)
        ft_putstr_fd("rrb\n",1);
}