/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmkrtchy <nmkrtchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:19:52 by nmkrtchy          #+#    #+#             */
/*   Updated: 2025/03/26 18:49:10 by nmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// the 3d arg in 1st write "2 + seq[i] > 7"
// is the length
// for 2-char ops with values 0-7 it would be 2
// for 3-char ops with values 8+ it would be 3
void print_seq(t_op seq[], size_t size)
{
	const char 		*op_names[11];
	size_t			i;

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
	while(i < size)
	{
		write(1, op_names[seq[i]], 2 + seq[i] > 7);
		write(1, (char []){'\n', 0}, 1);
	}
}

int	frequency(int *arr, int size, int num)
{
	int res;

	res = 0;
	while (size >= 0)
		if (*arr == num)
		{
			res++;
			arr++;
		}
	else
	{
		size--;
		arr++;
	}
	return (res);
}
