/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmkrtchy <nmkrtchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:19:52 by nmkrtchy          #+#    #+#             */
/*   Updated: 2025/05/07 22:48:54 by nmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_seq(t_op seq[], size_t size)
{
	const char	*op_names[11];
	size_t		i;

	op_names[SA] = "sa";
	op_names[SB] = "sb";
	op_names[SS] = "ss";
	op_names[PA] = "pa";
	op_names[PB] = "pb";
	op_names[RA] = "ra";
	op_names[RB] = "rb";
	op_names[RR] = "rr";
	op_names[RRA] = "rra";
	op_names[RRB] = "rrb";
	op_names[RRR] = "rrr";
	i = 0;
	while (i < size)
	{
		ft_write((char *)op_names[seq[i]]);
		ft_write("\n");
		i++;
	}
}

int	in_arr(int *arr, int size, int num)
{
	while (size > 0)
		if (*arr == num)
			return (1);
		else
		{
			size--;
			arr++;
		}
	return (0);
}

int	parse(char *strnum, int *arr, int i)
{
	int	num;

	num = ft_atoi(strnum, &i);
	if (i < 0 || in_arr(arr, i, num) > 0)
		return (EXIT_FAILURE);
	arr[i] = num;
	return (EXIT_SUCCESS);
}
