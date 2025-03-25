/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmkrtchy <nmkrtchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:20:03 by nmkrtchy          #+#    #+#             */
/*   Updated: 2025/03/25 22:59:09 by nmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_INSTR 5500

typedef enum e_op {
    SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR
} t_op;

typedef struct s_stack
{
    int size;
    int *arr;
} t_stack;


int	ft_strlen(char *str);
int	ft_write(char *mes);
void sort_stack(int *stack, int size);

#endif