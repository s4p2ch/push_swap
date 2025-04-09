#include "header.h"

void	micro_sort(t_data *s)
{
	if (s->a->size == 2)
	{
		if (s->a->arr[0] > s->a->arr[1])
			apply_op(SA, s);
	}
	else if (s->a->size == 3)
	{
		if (s->a->arr[0] > s->a->arr[1] && s->a->arr[0] > s->a->arr[2])
		{
			apply_op(RA, s);
			if (s->a->arr[0] > s->a->arr[1])
				apply_op(SA, s);
		}
		else if (s->a->arr[0] > s->a->arr[1])
		{
			apply_op(SA, s);
		}
		else if (s->a->arr[1] > s->a->arr[2])
		{
			apply_op(RRA, s);
			if (s->a->arr[0] > s->a->arr[1])
				apply_op(SA, s);
		}
	}
}

void	mega_sort(t_data *s)
{
	apply_op(PB, s);
	apply_op(PB, s);
	apply_op(PB, s);
	// micro_sort(s -> b, 0);
}

void	sort_stack(int *stack, size_t ssize)
{
	t_data	stacks;

	stacks.a->arr = stack;
	stacks.b->arr = malloc(sizeof(int) * ssize);
	stacks.b->size = 0;
	// printf("ssize:%ld\n", ssize);
	// Check if already sorted
	if (is_sorted(stacks.a))
	{
		free(stacks.b->arr);
		return ;
	}
	normalize(stacks.a->arr, stacks.a->size);
	if (ssize <= 5)
		micro_sort(&stacks);
	else
		mega_sort(&stacks);
	free(stacks.b->arr);
}
