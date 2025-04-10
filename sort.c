#include "header.h"

void	print_stacks(t_stack *sa, t_stack *sb);

void	do_micro_sort(t_data *ss, t_op swap, t_op rotate, t_op revrotate)
{
	t_stack	*s;
	int		(*cmp)(int, int);

	if (swap == SA)
		s = ss->a;
	else
		s = ss->b;
	if ((s->size == 2) && (s->arr[0] > s->arr[1]))
		apply_op(swap, ss);
	else if (s->size == 3)
	{
		if (s->arr[0] > s->arr[1] && s->arr[0] > s->arr[2])
		{
			apply_op(rotate, ss);
			if (s->arr[0] > s->arr[1])
				apply_op(swap, ss);
		}
		else if (s->arr[0] > s->arr[1])
			apply_op(swap, ss);
		else if (s->arr[1] > s->arr[2])
		{
			apply_op(revrotate, ss);
			if (s->arr[0] > s->arr[1])
				apply_op(swap, ss);
		}
	}
}

void	micro_sort(t_data *ss, char stack)
{
	if (stack == 'a')
		do_micro_sort(ss, SA, RA, RRA);
	else
		do_micro_sort(ss, SB, RB, RRB);
}

// idx - index of elem with minimum ops to push
//       to the correct position in b stack
void	mega_sort(t_data *ss)
{
	size_t	idx;
	size_t	min_idx;
	t_op	ops[MAX_OPS];

	apply_op(PB, ss);
	apply_op(PB, ss);
	apply_op(PB, ss);
	micro_sort(ss, 'b');
	while (ss->a->size > 0)
	{
		idx = 0;
		min_idx = 0;
		while (idx < ss->a->size)
		{
			if (op_count(idx) < op_count(min_idx))
				min_idx = idx;
			idx++;
		}
		idx = 0;
		while (idx < op_count(min_idx))
			apply_op(ops[idx], ss);
	}
}

void	sort_stack(int *stack, size_t ssize)
{
	t_data	stacks;

	stacks.a = malloc(sizeof(t_stack));
	stacks.a->arr = stack;
	stacks.a->size = ssize;
	stacks.b = malloc(sizeof(t_stack));
	stacks.b->arr = malloc(sizeof(int) * ssize);
	stacks.b->size = 0;
	if (is_sorted(stacks.a))
	{
		free(stacks.b->arr);
		return ;
	}
	normalize(stacks.a->arr, stacks.a->size);
	if (ssize <= 5)
		micro_sort(&stacks, 'a');
	else
		mega_sort(&stacks);
	print_stacks(stacks.a, stacks.b);
	free(stacks.b->arr);
}
