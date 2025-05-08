/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmkrtchy <nmkrtchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:41:55 by nmkrtchy          #+#    #+#             */
/*   Updated: 2025/05/07 22:51:00 by nmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_op(t_op op)
{
	const char	*op_str[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
			"rra", "rrb", "rrr"};

	printf("%s\n", op_str[op]);
}

void	apply_op2(t_op op, t_stack *a_stack, t_stack *b_stack)
{
	if (op == RB && b_stack->size > 1)
		push(b_stack, pop(b_stack, 1), -1);
	else if (op == RRA || op == RRR)
	{
		if (a_stack->size > 1 && (op == RRA || op == RRR))
			push(a_stack, pop(a_stack, -1), 1);
		if (b_stack->size > 1 && (op == RRB || op == RRR))
			push(b_stack, pop(b_stack, -1), 1);
	}
	else if (op == RRB && b_stack->size > 1)
		push(b_stack, pop(b_stack, -1), 1);
}

void	apply_op(t_op op, t_stack *a_stack, t_stack *b_stack)
{
	if (op == SA || op == SB || op == SS)
	{
		if (a_stack->size >= 2 && (op == SA || op == SS))
			swap(a_stack->arr);
		if (b_stack->size >= 2 && (op == SB || op == SS))
			swap(b_stack->arr);
	}
	else if (op == PA && b_stack->size > 0)
		push(a_stack, pop(b_stack, 1), 1);
	else if (op == PB && a_stack->size > 0)
		push(b_stack, pop(a_stack, 1), 1);
	else if (op == RA || op == RR)
	{
		if (a_stack->size > 1 && (op == RA || op == RR))
			push(a_stack, pop(a_stack, 1), -1);
		if (b_stack->size > 1 && (op == RB || op == RR))
			push(b_stack, pop(b_stack, 1), -1);
	}
	else
		apply_op2(op, a_stack, b_stack);
	print_op(op);
}
