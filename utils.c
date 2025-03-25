/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmkrtchy <nmkrtchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:19:52 by nmkrtchy          #+#    #+#             */
/*   Updated: 2025/03/25 21:20:30 by nmkrtchy         ###   ########.fr       */
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

int	ft_write(char *mes)
{
	write(1, mes, ft_strlen(mes));
	return (0);
}

void	ft_putn(long n)
{
	if (n < 0)
	{
		write(1, (char []){'-', 0}, 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putn(n / 10);
		ft_putn(n % 10);
	}
	else
		write(1, (char []){n + '0', 0}, 1);
}
