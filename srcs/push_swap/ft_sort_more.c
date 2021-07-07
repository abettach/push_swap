#include "../inc/push_swap.h"

int	get_scan_top(t_cheker *c, int chunk_size)
{
	int	i;
	int	indice;
	int	moves;

	moves = 0;
	i = 0;
	while (i < c->len)
	{
		indice = 0;
		while (indice < chunk_size)
		{
			if (c->list_a[i] == c->new_tab[indice])
				return (moves);
			indice++;
		}
		i++;
		moves++;
	}
	return (-1);
}

int	get_scan_end(t_cheker *c, int chunk_size)
{
	int	i;
	int	moves;
	int	indice;

	moves = 0;
	i = c->len - 1;
	while (i >= 0)
	{
		indice = 0;
		while (indice < chunk_size)
		{
			if (c->list_a[i] == c->new_tab[indice])
				return (moves);
			indice++;
		}
		i--;
		moves++;
	}
	return (-1);
}

void	push_a_to_b(t_cheker *c, int chunk_size)
{
	int	move_top;
	int	move_end;

	move_top = get_scan_top(c, chunk_size);
	move_end = get_scan_end(c, chunk_size);
	if (move_top <= move_end)
	{
		while (move_top-- > 0)
			ft_do_ra(c, 0);
		ft_do_pb(c, 0);
	}
	else
	{
		while (move_end-- >= 0)
			ft_do_rra(c, 0);
		ft_do_pb(c, 0);
	}
}

int	get_big_nbr(t_cheker *c)
{
	int	*tmp;
	int		ret;
	tmp = malloc(sizeof(int) * (c->len_b + 1));
	int i= 1;
	while (i < c->len_b)
	{
		tmp[i] = c->list_b[i];
		i++;
	}
	ret = c->list_b[0];
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] > ret)
			ret = tmp[i];
		i++;
	}
	return (ret);
}

int	get_big_nbr_pos(t_cheker *c, int nbr)
{
	int	*tmp;
	int		ret;
	tmp = malloc(sizeof(int) * c->len + 1);
	int i= 0;
	while (i < c->len_b)
	{
		if (c->list_b[i] == nbr)
			return i;
		i++;
	}
	return (-1);
}

void	last_sort(t_cheker *c, int pos_num, int midle_stack)
{
	int	big_nbr;
	int	i;
	int	stack_lengt;

	i = 0;
	stack_lengt = c->len_b;
	while (i < stack_lengt)
	{
		midle_stack = stack_lengt / 2;
		big_nbr = get_big_nbr(c);
		pos_num = get_big_nbr_pos(c, big_nbr);
				printf("midl = %d.",midle_stack);
				printf("big = %d.",big_nbr);
				printf("pos = %d\n",pos_num);
		if (pos_num <= midle_stack)
		{
			while (pos_num-- > 0)
				ft_do_rb(c, 0);
			ft_do_pa(c, 0);
		}
		else
		{
			while (pos_num++ < c->len_b)
				ft_do_rrb(c, 0);
			ft_do_pa(c, 0);
		}
		i++;
	}
}

void	solution_for_more_2(t_cheker *c)
{
	int i = 0;
	if (c->len == 3)
		ft_sort_3numbers(c);
 	else if (c->len == 2)
	{
		if (c->list_a[0] > c->list_a[1])
			ft_do_sa(c, 0);
	}
	while (i <= c->len)
	{
		ft_do_pb(c, 0);
		i++;
	}
	last_sort(c, 0, 0);
}

void    ft_sort_more(t_cheker *c, int nbr_chunk, int chunk_size)
{
	int	i;
	int	j;
	int	inc;
	j = 0;
	i = 0;
	inc = chunk_size;
	while (i < nbr_chunk)
	{
		while (j < chunk_size)
		{
			push_a_to_b(c, chunk_size);
			j++;
		}
		chunk_size += inc;
		i++;
	}
	solution_for_more_2(c);
}