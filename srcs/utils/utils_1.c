/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:10:15 by abettach          #+#    #+#             */
/*   Updated: 2021/07/23 16:38:36 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_check_sort(t_push *c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < c->len - 1)
	{
		if (c->list_a[i] > c->list_a[i + 1])
			return (0);
		else
			i++;
	}
	return (1);
}

void	ft_copy_args_to_stack(t_push *c)
{
	int		i;

	i = 0;
	while (c->new_av[i])
	{
		c->list_a[i] = ft_atoi(c->new_av[i], c);
		i++;
	}
	c->list_a[i] = '\0';
}

char	*ft_strchr(const char *s, int c)
{
	char	c3;
	char	*str;
	int		i;

	c3 = (char)c;
	str = (char *)s;
	i = 0;
	if (c3 == '\0')
		return (str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == c3)
			return (str + i);
		i++;
	}
	return (NULL);
}

void	ft_sort_table(t_push *c)
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

void	ft_copy_stack_to_tab(t_push *c, int checker)
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
	if (ft_check_sort(c) == 1 && checker == 0 && ft_check_error(c) != -1)
	{
		ft_free_all(c, 0);
		exit(0);
	}
}
