/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:36:59 by abettach          #+#    #+#             */
/*   Updated: 2021/07/15 13:42:01 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    ft_do_sa(t_cheker *c, int cheker)
{
    int tmp;

    tmp = c->list_a[0];
    c->list_a[0] = c->list_a[1];
    c->list_a[1] = tmp;
    if (cheker == 0)
        ft_putstr_fd("sa\n",1);
}

void    ft_do_ra(t_cheker *c, int cheker)
{
    int tmp;
    int i  = 0;

    tmp = c->list_a[0];
    while (i < c->len - 1)
    {
        c->list_a[i] = c->list_a[i+1];
        i++;
    }
    c->list_a[i] = tmp;
    c->list_a[++i] = '\0';
    if (cheker == 0)
        ft_putstr_fd("ra\n",1);
}

void    ft_do_rra(t_cheker *c, int cheker)
{
    int *list;
    int j = 1;

    list = malloc(sizeof(int) * (c->len + 1));
    list[0] = c->list_a[c->len - 1];
    int i  = 0;
    while (i < c->len - 1)
    {
        list[j] = c->list_a[i];
        j++;
        i++;
    }
    list[j] = '\0';
    i = 0;
    while (i < c->len)
    {
        c->list_a[i] = list[i];
        i++;
    }
    c->list_a[i] = '\0';
    free(list);
    list = NULL;
    if (cheker == 0)
        ft_putstr_fd("rra\n",1);
}

void    ft_do_pa(t_cheker *c, int cheker)
{
    int i = 0;
    int *list;

    c->len++;
    c->len_b--;
    c->pb--;
    i = 0;
    while (i < c->len - 1)
    {
        c->list_a[i+1] = c->list_a[i];
        i++;
    }
    c->list_a[0] = c->list_b[0];
    c->list_a[c->len] = '\0';
    i = 0;
    while (i < c->len_b)
    {
        c->list_b[i] = c->list_b[i + 1];
        i++;
    }
    c->list_b[i] = '\0';
    if (cheker == 0)
        ft_putstr_fd("pa\n",1);
}
