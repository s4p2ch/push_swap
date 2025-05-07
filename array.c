/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmkrtchy <nmkrtchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:06:01 by nmkrtchy          #+#    #+#             */
/*   Updated: 2025/05/07 22:09:00 by nmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_sorted(t_stack *a)
{
	size_t	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->arr[i] > a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	swap(int arr[])
{
	int	temp;

	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
}

// shift > 0 adds num to the beggining
// shift < 0 adds num to the ending
void	push(t_stack *stack, int num, char shift)
{
	if (shift < 0)
		stack->arr[stack->size] = num;
	else
	{
		ft_memmove((stack->arr) + 1, stack->arr, stack->size);
		stack->arr[0] = num;
	}
	stack->size++;
}

// decrements size first, so we dont need to use (size - 1)
// to reach the last element.
// with shift > 0 returns FIRST element
// with shift < 0 returns LAST element
int	pop(t_stack *stack, char shift)
{
	int	res;

	stack->size--;
	if (shift > 0)
	{
		res = stack->arr[0];
		ft_memmove(stack->arr, (stack->arr) + 1, stack->size);
	}
	else
		res = stack->arr[stack->size];
	return (res);
}
