/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmkrtchy <nmkrtchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:46:19 by nmkrtchy          #+#    #+#             */
/*   Updated: 2025/05/07 22:48:04 by nmkrtchy         ###   ########.fr       */
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

void	ft_write(char *str)
{
	write(1, str, ft_strlen(str));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

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

// if dest is on the left of src in memory
// it will copy arr from the end
void	ft_memmove(int *dest, const int *src, size_t size)
{
	if (dest < src)
		while (size--)
			*dest++ = *src++;
	else
		while (size--)
			*(dest + size) = *(src + size);
}
