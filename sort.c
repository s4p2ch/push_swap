#include "header.h"

static void micro_sort(t_stack *a, t_stack *b)
{
    if (a->size == 2)
    {
        if (a->arr[0] > a->arr[1])
            apply_op(SA, a, b);
    }
    else if (a->size == 3)
    {
        if (a->arr[0] > a->arr[1] && a->arr[0] > a->arr[2])
        {
            apply_op(RA, a, b);
            if (a->arr[0] > a->arr[1])
                apply_op(SA, a, b);
        }
        else if (a->arr[0] > a->arr[1])
        {
            apply_op(SA, a, b);
        }
        else if (a->arr[1] > a->arr[2])
        {
            apply_op(RRA, a, b);
            if (a->arr[0] > a->arr[1])
                apply_op(SA, a, b);
        }
    }
}

static size_t	find_min_idx(t_stack *a)
{
	size_t	i;
	size_t	idx;
	int		min;

	i = 0;
	idx = 0;
	min = a->arr[0];
	while (i < a->size)
	{
		if (a->arr[i] < min)
		{
			min = a->arr[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}

void	mid_sort(t_stack *a, t_stack *b)
{
	size_t	pos;

	while (a->size > 3)
	{
		pos = find_min_idx(a);
		if (pos <= a->size / 2)
			while (pos--)
				apply_op(RA, a, b);

		else
		{
			pos = a->size - pos;
			while (pos--)
				apply_op(RRA, a, b);

		}
		apply_op(PB, a, b);

	}
	micro_sort(a, b);
	while (b->size)
		apply_op(PA, a, b);

}


void sort_stack(int *stack, size_t ssize)
{
    t_stack a;
    t_stack b;

    a.arr = stack;
    a.size = ssize;
    b.arr = malloc(sizeof(int) * ssize);
    b.size = 0;
    if (is_sorted(&a))
    {
        free(b.arr);
        return;
    }
    normalize(a.arr, a.size);
    if (ssize <= 3)
        micro_sort(&a, &b);
	else if (ssize < 100)
		mid_sort(&a, &b);
	else
		butterfly_sort(&a, &b);
    free(b.arr);
}
