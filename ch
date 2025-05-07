/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmkrtchy <nmkrtchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:25:24 by nmkrtchy          #+#    #+#             */
/*   Updated: 2025/05/07 12:09:42 by nmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <unistd.h>

static int	read_op(char *buf)
{
	int	i;
	int	n;

	i = 0;
	n = read(0, buf + i, 1);
	while (n > 0 && buf[i] != '\n')
	{
		i++;
		if (i > 3)
			return (-1);
		n = read(0, buf + i, 1);
	}
	if (n < 0)
		return (-1);
	if (n == 0 && i == 0)
		return (0);
	if (buf[i] != '\n')
		return (-1);
	buf[i] = '\0';
	return (1);
}

static int	apply_str(char *op, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(op, "sa"))
		apply_op(SA, a, b);
	else if (!ft_strcmp(op, "sb"))
		apply_op(SB, a, b);
	else if (!ft_strcmp(op, "ss"))
		apply_op(SS, a, b);
	else if (!ft_strcmp(op, "pa"))
		apply_op(PA, a, b);
	else if (!ft_strcmp(op, "pb"))
		apply_op(PB, a, b);
	else if (!ft_strcmp(op, "ra"))
		apply_op(RA, a, b);
	else if (!ft_strcmp(op, "rb"))
		apply_op(RB, a, b);
	else if (!ft_strcmp(op, "rr"))
		apply_op(RR, a, b);
	else if (!ft_strcmp(op, "rra"))
		apply_op(RRA, a, b);
	else if (!ft_strcmp(op, "rrb"))
		apply_op(RRB, a, b);
	else if (!ft_strcmp(op, "rrr"))
		apply_op(RRR, a, b);
	else
		return (0);
	return (1);
}

static int	init_stacks(t_stack *a, t_stack *b, int *arr, int size)
{
	a->arr = arr;
	a->size = size;
	b->arr = malloc(sizeof(int) * size);
	b->size = 0;
	if (!b->arr)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**args;
	size_t	i;
	char	op[4];
	int		ret;

	int count, *arr;
	t_stack a, b;
	if (argc < 2)
		return (0);
	args = (argc == 2) ? ft_split(argv[1], ' ') : &argv[1];
	for (count = 0; args[count]; count++)
		;
	if (!(arr = malloc(sizeof(int) * count)))
		return (ft_write("Error1\n"), EXIT_FAILURE);
	for (i = 0; i < (size_t)count; i++)
		if (parse(args[i], arr, i))
			return (ft_write("Error2\n"), EXIT_FAILURE);
	if (!init_stacks(&a, &b, arr, count))
		return (ft_write("Error3\n"), EXIT_FAILURE);
	while ((ret = read_op(op)) > 0 && apply_str(op, &a, &b))
		;
	if (ret < 0 || (ret > 0 && !apply_str(op, &a, &b)))
		return (ft_write("Error4\n"), EXIT_FAILURE);
	ft_write((is_sorted(&a) && b.size == 0) ? "OK\n" : "KO\n");
	return (0);
}
