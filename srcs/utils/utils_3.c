/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:10:09 by abettach          #+#    #+#             */
/*   Updated: 2021/07/15 14:10:10 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int     ft_get_len_ini(char **av)
{
    int i = 1;
    int len = 0;
    while (av[i])
    {
        i++;
        len++;
    }
    return len;
}


int	get_spaces(char *str, int ret)
{
	int		i;
	int k;
	char	**split;

	i = 0;
	split = ft_split(str, ' ');
	while (split && split[i])
	{
		ret++;
		i++;
	}
	k = 0;
	if (split[k])
		while (split[k])
		{
			free(split[k]);
			k++;
		}
	if (split)
		free(split);

	return (ret);
}

int	get_corr_len(t_cheker *c, char **av)
{
	int	i;
	int	j;
	int	ret;

	i = 1;
	j = 0;
	ret = 0;
	while (av[i])
	{
		if (av[i][0] != '\0')
		{
			j = 0;
			if (ft_strchr(av[i], ' ') != NULL)
				ret = get_spaces(av[i], ret);
			else
				ret++;
		}
		i++;
	}
	return (ret);
}

void	get_btween_quots(t_cheker *c, char **av, int i, int *j)
{
	char	**split;
	int		k;

	k = 0;
	split = ft_split(av[i], ' ');
	while (split[k])
	{
		c->new_av[*j] = ft_strdup(split[k]);
		k++;
		*j = *j + 1;
	}
	k = 0;
	if (split[k])
		while (split[k])
		{
			free(split[k]);
			k++;
		}
	if (split)
		free(split);
}

void	ft_get_corr_args(t_cheker *c, char **av)
{
	int	i;
	int	lengt;
	int	j;

	j = 0;
	i = 1;
	lengt = get_corr_len(c,av);
	c->len_ini = lengt;
	c->new_av = (char **)malloc(sizeof(char *) * (lengt + 1));
	while (av[i])
	{
		if (av[i][0])
		{
			if (ft_strchr(av[i], ' ') != NULL)
			{
				get_btween_quots(c, av, i, &j);
				i++;
			}
			else
				c->new_av[j++] = ft_strdup(av[i++]);
		}
		else
			i++;
	}
	c->new_av[j] = NULL;
}