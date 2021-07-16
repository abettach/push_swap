/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:10:12 by abettach          #+#    #+#             */
/*   Updated: 2021/07/16 11:33:59 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	i = 0;
	if (s)
		while (s[i] != '\0')
			write(fd, &s[i++], 1);
}

int	ft_atoi(const char *str, t_cheker *c)
{
	int		s;
	long	r;

	s = 1;
	r = 0;
	while (*str == ' ' || *str == '\t' || *str == '\r'
		|| *str == '\n' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
		s = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		r = (r * 10) + (*str - '0');
		str++;
	}
	r = r * s;
	if (r > 2147483647 || r < -2147483648)
	{
		ft_putstr_fd("Error\n", 2);
		ft_free_all(c, 1);
		exit(0);
	}
	return (r);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t		i;
	char		*s11;
	char		*s22;

	i = 0;
	if (s1 == NULL)
		return (1);
	s11 = (char *)s1;
	s22 = (char *)s2;
	while ((s11[i] || s22[i]))
	{
		if (s11[i] != '\0' && s22[i] == '\0')
			return (s11[i]);
		if (s11[i] == '\0' && s22[i] != '\0')
			return (-s22[i]);
		if (s11[i] > s22[i])
			return (s11[i] - s22[i]);
		if (s11[i] < s22[i])
			return (s11[i] - s22[i]);
		i++;
	}
	return (0);
}

int	ft_strlen(const char *s)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
