#ifndef CHEKER_H
#define CHEKER_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# define BUFFER_SIZE 32
# define STDERR 2

typedef struct s_cheker
{
    char     *tab;
    char    **command;
    int      *list_a;
    int      *list_b;
    int     len;
    int     *new_tab;
    char    **swap_command;
}   t_cheker;

int		get_next_line(const int fd, char **line);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
int	    ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

//Utils
void		ft_putchar(char c);
void		ft_putstr(char *str);
int			ft_atoi(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int		    ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
void		ft_putstr_fd(char *s, int fd);
void        ft_error(char   *str);
void    ft_strjoin_command(t_cheker *c, char *arg);
void    print_stack_a(t_cheker *c);
void    print_stack_b(t_cheker *c);
int		ft_double_check(t_cheker *c);

//checker 
void	ft_checker(t_cheker *c);
void	ft_get_args(t_cheker *c, char **av);
//push_swap
int     ft_get_len(int  *stack_a);
void    ft_copy_stack(t_cheker *c);
void    ft_sort_table(t_cheker *c);
int     ft_get_case(t_cheker *c);
void    ft_sort_3numbers(t_cheker *c);
void    ft_sort_5numbers(t_cheker *c);
void    ft_sort_more(t_cheker *c, int nbr_chunk);

//stack a
void    ft_do_sa(t_cheker *c, int cheker);
void    ft_do_ra(t_cheker *c, int cheker);
void    ft_do_rra(t_cheker *c, int cheker);
void    ft_do_pa(t_cheker *c, int cheker);

//stack b
void    ft_do_pb(t_cheker *c, int cheker, int pb);
void    ft_do_sb(t_cheker *c, int cheker);  
void    ft_do_rb(t_cheker *c, int cheker);
void    ft_do_rrb(t_cheker *c, int cheker);
void    ft_init_stack_b(t_cheker *c);

#endif