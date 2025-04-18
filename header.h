/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmkrtchy <nmkrtchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:20:03 by nmkrtchy          #+#    #+#             */
/*   Updated: 2025/03/30 16:16:43 by nmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_OPS 5500

typedef enum e_op {
    SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR
} t_op;

typedef struct s_stack
{
    size_t size;
    int *arr;
} t_stack;

int	ft_strlen(char *str);
void ft_write(char *str);
void print_seq(t_op[], size_t);
void sort_stack(int *stack, size_t ssize);
int	frequency(void *arr, int size, int num);

#endif