/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmkrtchy <nmkrtchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:19:48 by nmkrtchy          #+#    #+#             */
/*   Updated: 2025/03/25 23:12:41 by nmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_atoi(char *str, int *i)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
		if (*str >= '0' && *str <= '9')
			res = res * 10 + *str++ - '0';
	else
		return (*i = -1, 0);
	if (res * sign != (int)(res * sign))
		return (*i = -1, 0);
	return (res * sign);
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
	if (i < 0 || in_arr(arr, i, num))
		return (EXIT_FAILURE);
	arr[i] = num;
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int		*arr;
	int		i;

	if (argc < 2)
		return (ft_write(argv[0]), EXIT_FAILURE);
	arr = malloc(sizeof(int) * (argc - 1));
	if (!arr)
		return (ft_write("Error\n"), EXIT_FAILURE);
	i = 0;
	while (argv[++i])
		if (parse(argv[i], arr, i - 1))
			return (ft_write("Error\n"), free(arr), EXIT_FAILURE);
	sort_stack(arr, i - 1);
	free(arr);
	return (EXIT_SUCCESS);
}

	// i = (int)(1L << 31);
	// printf("\n%d", i - 1);