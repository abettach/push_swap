/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:10:04 by abettach          #+#    #+#             */
/*   Updated: 2021/07/20 20:18:18 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_free_all(t_push *c, int before)
{
	int		i;

	i = -1;
	while (c->new_av[++i])
		free(c->new_av[i]);
	if (c->new_av)
		free(c->new_av);
	free(c->list_a);
	free(c->list_b);
	if (before == 0)
		free(c->new_tab);
}

int	count_str(char *s1, char c)
{
	int	i;
	int	lengt;
	int	count;

	count = 0;
	i = 0;
	lengt = ft_strlen(s1);
	while (s1[i] == c)
	{
		count++;
		i++;
	}
	i = lengt - 1;
	while (s1[i] == c)
	{
		count++;
		i--;
	}
	return (count);
}

char	*ft_strtrim(char *s1, char set)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	j = 0;
	i = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s1)
			- count_str(s1, set) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] == set)
		i++;
	len = ft_strlen(s1) - 1;
	while (s1[len] == set)
		len--;
	while (i <= len)
	{
		str[j] = s1[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		count;

	count = 0;
	i = (ft_strlen(s1) + ft_strlen(s2) + 1);
	ret = (char *)malloc(sizeof(char) * (i));
	i = 0;
	while (s1[i])
	{
		ret[count] = s1[i];
		count++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		ret[count] = s2[i];
		count++;
		i++;
	}
	ret[count] = '\0';
	return (ret);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;
	int		j;

	j = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	i = 0;
	while (i < j)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
