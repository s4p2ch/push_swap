/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normilize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmkrtchy <nmkrtchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:09:35 by nmkrtchy          #+#    #+#             */
/*   Updated: 2025/05/08 20:30:19 by nmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// void	copy_array(int *dest, int *src, size_t size)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// }

// void	bubble_sort(int *arr, size_t size)
// {
// 	size_t	i;
// 	size_t	j;
// 	int		temp;

// 	i = 0;
// 	while (i < size)
// 	{
// 		j = i + 1;
// 		while (j < size)
// 		{
// 			if (arr[i] > arr[j])
// 			{
// 				temp = arr[j];
// 				arr[j] = arr[i];
// 				arr[i] = temp;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	do_norm(int *stack, int *sorted, int *normalized, size_t size)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			if (stack[i] == sorted[j])
// 			{
// 				normalized[i] = j;
// 				break ;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	normalize(int *stack, size_t size)
// {
// 	int	*sorted;
// 	int	*normalized;

// 	sorted = malloc(sizeof(int) * size);
// 	normalized = malloc(sizeof(int) * size);
// 	copy_array(stack, sorted, size);
// 	bubble_sort(sorted, size);
// 	do_norm(stack, sorted, normalized, size);
// 	copy_array(stack, normalized, size);
// 	free(sorted);
// 	free(normalized);
// }
void normalize(int *stack, size_t size)
{
    int *sorted = malloc(sizeof(int) * size);
    int *normalized = malloc(sizeof(int) * size);
    
    // Copy the original stack
    for (size_t i = 0; i < size; i++)
        sorted[i] = stack[i];
    
    // Sort the copy
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (sorted[j] > sorted[j + 1])
            {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }
    
    // Create normalized array
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (stack[i] == sorted[j])
            {
                normalized[i] = j;
                break;
            }
        }
    }
    
    // Copy normalized values back to original stack
    for (size_t i = 0; i < size; i++)
        stack[i] = normalized[i];
    
    free(sorted);
    free(normalized);
}
