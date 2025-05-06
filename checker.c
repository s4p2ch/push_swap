#include "header.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static int	read_op(char *buf)
{
    int	i;
    int	n;

    i = 0;
    while ((n = read(0, buf + i, 1)) > 0 && buf[i] != '\n')
    {
        i++;
        if (i > 3)
            return (-1);
    }
    if (n < 0)
        return (-1);
    if (n == 0 && i == 0)
        return (0);
    if (buf[i] != '\n')
        return (-1);
    buf[i] = '\0';
    return (1);
}


static int	apply_str(char *op, t_stack *a, t_stack *b)
{
	if (!strcmp(op, "sa")) apply_op(SA, a, b);
	else if (!strcmp(op, "sb")) apply_op(SB, a, b);
	else if (!strcmp(op, "ss")) apply_op(SS, a, b);
	else if (!strcmp(op, "pa")) apply_op(PA, a, b);
	else if (!strcmp(op, "pb")) apply_op(PB, a, b);
	else if (!strcmp(op, "ra")) apply_op(RA, a, b);
	else if (!strcmp(op, "rb")) apply_op(RB, a, b);
	else if (!strcmp(op, "rr")) apply_op(RR, a, b);
	else if (!strcmp(op, "rra")) apply_op(RRA, a, b);
	else if (!strcmp(op, "rrb")) apply_op(RRB, a, b);
	else if (!strcmp(op, "rrr")) apply_op(RRR, a, b);
	else
		return (0);
	return (1);
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

int	main(int argc, char **argv)
{
	char	**args;
	int		count, *arr;
	size_t	i;
	t_stack	a, b;
	char	op[4];
	int		ret;

	if (argc < 2)
		return (0);
	args = (argc == 2) ? ft_split(argv[1], ' ') : &argv[1];
	for (count = 0; args[count]; count++)
		;
	if (!(arr = malloc(sizeof(int) * count)))
		return (ft_write("Error1\n"), EXIT_FAILURE);
	for (i = 0; i < (size_t)count; i++)
		if (parse(args[i], arr, i))
			return (ft_write("Error2\n"), EXIT_FAILURE);
	a.arr = arr; a.size = count;
	b.arr = malloc(sizeof(int) * count); b.size = 0;
	if (!b.arr)
		return (ft_write("Error3\n"), EXIT_FAILURE);
	while ((ret = read_op(op)) > 0 && apply_str(op, &a, &b))
		;
	if (ret < 0 || (ret > 0 && !apply_str(op, &a, &b)))
		return (ft_write("Error4\n"), EXIT_FAILURE);
	ft_write((is_sorted(&a) && b.size == 0) ? "OK\n" : "KO\n");
	return (0);
}
