#include "../inc/push_swap.h"

int	ft_check_sort(t_cheker *c)
{
	int i = 0;
	int j = 0;

	while (i < c->len - 1)
	{
		if (c->list_a[i] > c->list_a[i + 1])
			return 0;
		else
			i++;
	}
	return 1;
}

char		*clean_join(char *s1, char *s2)
{
	char	*tmp;

	tmp = s1;
	s1 = ft_strjoin(s1, s2);
	free(tmp);
	return (s1);
}

void		ft_bzero(void *s, size_t n)
{
	unsigned char	*d;
	size_t			i;

	d = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		d[i] = 0;
		i++;
	}
	return ;
}
void    ft_copy_args_to_stack(t_cheker *c)
{
    int i = 0;

    while (c->new_av[i])
    {
        c->list_a[i] = ft_atoi(c->new_av[i]);
        i++;
    }
    c->list_a[i] = '\0';

}

char		*ft_chr(const char *s, int c)
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

int     ft_get_len(int  *stack_a)
{
    int i = 0;
    while (stack_a[i])
        i++;
    return i;
}

int	get_spaces(char *str, int ret)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(str, ' ');
	while (split && split[i])
	{
		ret++;
		i++;
	}
	//ft_free_2(split);
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
	//ft_free_2(split);
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

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putstr(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void			ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	if (s)
		while (s[i] != '\0')
			write(fd, &s[i++], 1);
}

int					ft_atoi(const char *str)
{
	int				s;
	int				r;

	s = 1;
	r = 0;
	while (*str == ' ' || *str == '\t' || *str == '\r' ||
	*str == '\n' || *str == '\v' || *str == '\f')
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
	return (r);
}

int				ft_strcmp(const char *s1, const char *s2)
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

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s22;

	i = 0;
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	while ((s11[i] || s22[i]) && i < n)
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

int		ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
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

char		*ft_strdup(const char *s1)
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

void    ft_strjoin_command(t_cheker *c, char *arg)
{
    int i = 0;
    char **tab;

    while (c->command[i])
        i++;
    tab = malloc(sizeof(char *) * (i +  2));
    i = 0;
    while (c->command[i])
    {
        tab[i] = ft_strdup(c->command[i]);
        i++;
    }
    tab[i] = ft_strdup(arg);
	i++;
    tab[i] = NULL;
    i = 0;
    // while (c->command[i])
    // {
    //     free(c->command[i]);
    //     c->command[i] = NULL;
    //     i++;
    // }
    // if (c->command)
    //     free(c->command);
    i = 0;
    while (tab[i])
        i++;
    c->command = malloc(sizeof(char *) * (i + 1));
    i = 0;
    while (tab[i])
    {
        c->command[i] = ft_strdup(tab[i]);
        i++;
    }
    c->command[i] = NULL;
    // i = 0;
    //  while (tab[i])
    // {
    //     free(tab[i]);
    //     tab[i] = NULL;
    //     i++;
    // }
    // if (tab)
    //     free(tab);
}