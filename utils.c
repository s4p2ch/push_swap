/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmkrtchy <nmkrtchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:19:52 by nmkrtchy          #+#    #+#             */
/*   Updated: 2025/04/04 19:58:44 by nmkrtchy         ###   ########.fr       */
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

// incorrect output with
// ./main 9 8 3 4 2 6 4
int	frequency(void *arr, int size, int num)
{
	int res;

	res = 0;
	while (size >= 0)
		if (*(int *)arr == num)
		{
			res++;
			arr++;
			size--;
		}
	else
	{
		size--;
		arr++;
	}
	return (res);
}



// Calculate the cost of moving an element to the top of stack A
// int cost_to_top(size_t pos, size_t size)
// {
//     if (pos <= size / 2)
//         return pos; // Use ra
//     else
//         return size - pos; // Use rra
// }

// // Move element at position pos to the top of stack A
// void move_to_top_a(t_stack *a, t_stack *b, size_t pos)
// {
//     if (pos <= a->size / 2)
//     {
//         // Use ra
//         for (size_t i = 0; i < pos; i++)
//             apply_op(RA, a, b);
//     }
//     else
//     {
//         // Use rra
//         for (size_t i = 0; i < a->size - pos; i++)
//             apply_op(RRA, a, b);
//     }
// }

// // Move element at position pos to the top of stack B
// void move_to_top_b(t_stack *a, t_stack *b, size_t pos)
// {
//     if (pos <= b->size / 2)
//     {
//         // Use rb
//         for (size_t i = 0; i < pos; i++)
//             apply_op(RB, a, b);
//     }
//     else
//     {
//         // Use rrb
//         for (size_t i = 0; i < b->size - pos; i++)
//             apply_op(RRB, a, b);
//     }
// }