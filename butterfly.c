/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmkrtchy <nmkrtchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:32:26 by nmkrtchy          #+#    #+#             */
/*   Updated: 2025/05/08 20:48:58 by nmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// find the position of the highest value in stack
static int	find_max_pos(t_stack *b)
{
	int		max_pos;
	size_t	i;

	i = 1;
	max_pos = 0;
	while (i < b->size)
	{
		if (b->arr[i] > b->arr[max_pos])
			max_pos = i;
		i++;
	}
	return (max_pos);
}

static void	move_to_b(t_stack *a, t_stack *b)
{
	int	max_pos;

	while (b->size)
	{
		max_pos = find_max_pos(b);
		if (max_pos <= (int)(b->size / 2))
			while (max_pos--)
				apply_op(RB, a, b);
		else
		{
			max_pos = b->size - max_pos;
			while (max_pos--)
				apply_op(RRB, a, b);
		}
		apply_op(PA, a, b);
	}
}

void	butterfly_sort(t_stack *a, t_stack *b)
{
	size_t	size;
	size_t	chunk_size;
	size_t	next;

	size = a->size;
	chunk_size = (size / 100) * (20.0 - (size - 100) * (15.0 / 400.0));
	next = 0;
	while (a->size)
	{
		if ((size_t)a->arr[0] <= next)
		{
			apply_op(PB, a, b);
			apply_op(RB, a, b);
			next++;
		}
		else if ((size_t)a->arr[0] <= next + chunk_size)
		{
			apply_op(PB, a, b);
			next++;
		}
		else
			apply_op(RA, a, b);
	}
	move_to_b(a, b);
}
