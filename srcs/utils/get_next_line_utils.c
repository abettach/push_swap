/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:38:37 by abettach          #+#    #+#             */
/*   Updated: 2021/03/26 15:36:35 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		length;
	char		*tab;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	length = ft_strlen(&s[start]);
	if (length >= len)
		length = len;
	tab = (char *)malloc((length + 1));
	if (!tab)
		return (0);
	while (i < length && s[start] != '\0')
		tab[i++] = s[start++];
	tab[i] = '\0';
	return (tab);
}
