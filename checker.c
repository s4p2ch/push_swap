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

int check(t_stack *a, t_stack *b)
{
	int		ret;
	char	op[4];

	ret = read_op(op);
	while ( ret > 0 && apply_str(op, a, b))
			ret = read_op(op);
	if (ret < 0 || (ret > 0 && !apply_str(op, a, b)))
		return (0);
	if(is_sorted(a) && b->size == 0)
		ft_write("OK\n");
	else
		ft_write("KO\n");
	return (1);
}

int	main(int argc, char **argv)
{
	char	**args;
	int		*arr;
	size_t count;
	size_t	i;
	t_stack	a, b;

	if (argc < 2)
		return (0);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args =  &argv[1];
	count = 0;
	while (args[count])
		count++;
	if (!(arr = malloc(sizeof(int) * count)))
		return (ft_write("Error1\n"), EXIT_FAILURE);
	for (i = 0; i < count; i++)
		if (parse(args[i], arr, i))
			return (ft_write("Error2\n"), EXIT_FAILURE);
	a.arr = arr;
	a.size = count;
	b.arr = malloc(sizeof(int) * count);
	b.size = 0;
	if (!b.arr)
		return (ft_write("Error3\n"), free(arr), EXIT_FAILURE);
	if(!check(&a, &b))
		return (ft_write("Error4\n"), free(arr), free(b.arr), EXIT_FAILURE);
	return (free(arr), free(b.arr), 0);
}
