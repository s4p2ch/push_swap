/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmkrtchy <nmkrtchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:19:52 by nmkrtchy          #+#    #+#             */
/*   Updated: 2025/03/30 16:15:54 by nmkrtchy         ###   ########.fr       */
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

void ft_write(char *str)
{
	write(1, str, ft_strlen(str));
}

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
	i = 0;
	while(i < size)
	{
		ft_write((char *)op_names[seq[i]]);
		ft_write("\n");
		i++;
	}
}

int	frequency(void *arr, int size, int num)
{
	int res;

	res = 0;
	while (size >= 0)
		if (*(int *)arr == num)
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
