/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:38:49 by abettach          #+#    #+#             */
/*   Updated: 2021/07/16 10:00:22 by abettach         ###   ########.fr       */
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

static int	ft_rmp(char **new, int n, char **line, int fd)
{
	char	*temp;
	int		i;

	i = 0;
	while (new[fd][i] && new[fd][i] != '\n')
		i++;
	*line = ft_substr(new[fd], 0, i);
	if (!new[fd][i])
	{
		temp = new[fd];
		new[fd] = NULL;
		free(temp);
		return (0);
	}
	else
	{
		temp = new[fd];
		new[fd] = ft_strdup((new[fd]) + i + 1);
		free(temp);
	}
	if (!new[fd] || !*line)
		return (-1);
	if (n || (n == 0 && new[fd] != NULL))
		return (1);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*oldline[4864];
	char		*temp;
	int			n;

	buf = malloc(BUFFER_SIZE + 1);
	if (!line || fd < 0 || fd >= 4864 || BUFFER_SIZE <= 0 || \
	!buf || read(fd, buf, 0) == -1)
		return (-1);
	if (!oldline[fd])
		oldline[fd] = ft_strdup("");
	while ((!ft_strchr(oldline[fd], '\n')))
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == 0)
			break ;
		if (n < 0)
			return (-1);
		temp = oldline[fd];
		buf[n] = '\0';
		oldline[fd] = ft_strjoin(oldline[fd], buf);
		free(temp);
	}
	free(buf);
	return (ft_rmp(oldline, n, line, fd));
}
