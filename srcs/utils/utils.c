#include "../inc/push_swap.h"

void	ft_get_args(t_cheker *c, char **av)
{
	int i = 1;

	while (av[i])
		i++;
	i--;
	c->list_a = malloc(sizeof(int) * (i + 1+ 1));
	i =  1;
	int j = 0;
	while (av[i])
	{
		if (ft_strcmp(av[i],"0") == 0)
			c->list_a[j] = -1;
		else
			c->list_a[j] = ft_atoi(av[i]);
		i++;
		j++;
	}
	c->list_a[j] = '\0';
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

char		*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
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
    while (c->command[i])
    {
        free(c->command[i]);
        c->command[i] = NULL;
        i++;
    }
    if (c->command)
        free(c->command);
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
    i = 0;
     while (tab[i])
    {
        free(tab[i]);
        tab[i] = NULL;
        i++;
    }
    if (tab)
        free(tab);
}