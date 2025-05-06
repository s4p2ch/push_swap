/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmkrtchy <nmkrtchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:19:48 by nmkrtchy          #+#    #+#             */
/*   Updated: 2025/05/06 09:39:21 by nmkrtchy         ###   ########.fr       */
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
	if (i < 0 || in_arr(arr, i, num) > 0)
		return (EXIT_FAILURE);
	arr[i] = num;
	return (EXIT_SUCCESS);
}

// int	main(int argc, char **argv)
// {
// 	int		*arr;
// 	char	**args;
// 	int		count;
// 	int		i;

// 	if (argc < 2)
// 		return (ft_write(argv[0]), EXIT_FAILURE);
// 	if (argc == 2)
// 		args = ft_split(argv[1], ' ');
// 	else
// 		args = &argv[1];
// 	count = 0;
// 	while (args[count])
// 		count++;
// 	arr = malloc(sizeof(int) * count);
// 	if (!arr)
// 		return (ft_write("Error\n"), EXIT_FAILURE);
// 	i = -1;
// 	while (++i < count)
// 		if (parse(args[i], arr, i))
// 			return (ft_write("Error\n"), free(arr), 
// 				argc == 2 && free_split(args), EXIT_FAILURE);
// 	sort_stack(arr, count);
// 	free(arr);
// 	if (argc == 2)
// 		free_split(args);
// 	return (EXIT_SUCCESS);
// }


int	main(int argc, char **argv)
{
	int		*arr;
	char	**splited;
	size_t	i;

	if (argc < 2)
		return (ft_write(argv[0]), EXIT_FAILURE);
	splited = &argv[1];
	if (argc == 2)
	{
		arr = malloc(sizeof(int) * count_words(argv[1], ' '));
		splited = ft_split(argv[1], ' ');
	}
	else
		arr = malloc(sizeof(int) * (argc - 1));
	if (!arr)
		return (ft_write("Error\n"), EXIT_FAILURE);
	i = 0;
	while(splited[i++])
		if (parse(splited[i - 1], arr, i - 1))
			return (ft_write("Error\n"), free(arr), 
				argc == 2 && free_split(splited), EXIT_FAILURE);
	sort_stack(arr, i - 1);
	free(arr);
	return (EXIT_SUCCESS);
}