/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmkrtchy <nmkrtchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:20:03 by nmkrtchy          #+#    #+#             */
/*   Updated: 2025/05/07 12:05:24 by nmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_OPS 5500

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	SIZE
}			t_op;

typedef struct s_stack
{
	size_t	size;
	int		*arr;
}			t_stack;

typedef struct s_seq
{
	t_op	op[MAX_OPS];
	size_t	size;
}			t_seq;

int			parse(char *strnum, int *arr, int i);
int			in_arr(int *arr, int size, int num);
int			is_sorted(t_stack *a);

void		swap(int arr[]);
void		push(t_stack *stack, int num, char shift);
int			pop(t_stack *stack, char shift);
void		apply_op(t_op op, t_stack *a_stack, t_stack *b_stack);

void		ft_memmove(int *dest, const int *src, size_t size);
int			ft_atoi(char *str, int *i);
int			ft_strlen(char *str);
void		ft_write(char *str);
int			ft_strcmp(const char *s1, const char *s2);
char		**ft_split(const char *s, char c);
int			free_split(char **split);

void		print_seq(t_op seq[], size_t size);

void		sort_stack(int *stack, size_t ssize);
int			count_words(const char *s, char c);
void		normalize(int *stack, size_t size);
void		butterfly_sort(t_stack *a, t_stack *b);

#endif