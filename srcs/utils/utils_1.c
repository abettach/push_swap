/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:10:15 by abettach          #+#    #+#             */
/*   Updated: 2021/07/16 10:56:59 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_check_sort(t_cheker *c)
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

char	*clean_join(char *s1, char *s2)
{
	char	*tmp;

	tmp = s1;
	s1 = ft_strjoin(s1, s2);
	free(tmp);
	return (s1);
}

void	ft_copy_args_to_stack(t_cheker *c)
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

char	*ft_chr(const char *s, int c)
{
	char		c2;
	char		*str;
	int			i;

	c2 = (char)c;
	str = (char *)s;
	i = 0;
	if (c2 == '\0')
		return (str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == c2)
			return (str + i);
		i++;
	}
	return (NULL);
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
