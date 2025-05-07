/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmkrtchy <nmkrtchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:19:48 by nmkrtchy          #+#    #+#             */
/*   Updated: 2025/05/06 18:14:36 by nmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	int		*arr;
	char	**splited;
	size_t	i;

	if (argc < 2)
		return (EXIT_FAILURE);
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
	while (splited[i++])
		if (parse(splited[i - 1], arr, i - 1))
			return (ft_write("Error\n"), free(arr), argc == 2
				&& free_split(splited), EXIT_FAILURE);
	sort_stack(arr, i - 1);
	free(arr);
	return (EXIT_SUCCESS);
}
