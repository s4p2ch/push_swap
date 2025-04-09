#include "header.h"

void	print_stacks(t_stack *sa, t_stack *sb)
{
	printf("\ta   ");
	for (size_t j = 0; j < sa->size; j++)
		printf("%d ", sa->arr[j]);
	printf("\t\tb   ");
	for (size_t j = 0; j < sb->size; j++)
		printf("%d ", sb->arr[j]);
	printf("\n");
}

void	print_op(t_op op)
{
	const char	*op_str[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
			"rra", "rrb", "rrr"};

	printf("%s\t", op_str[op]);
}

void apply_on_stack(t_op op, t_stack stack)
{
    return (
        (op == SA || op == SB || op == SS)
    )
}

void	apply_op(t_op op, t_data *s)
{
	if (op == SA || op == SB || op == SS)
	{
		if (s->a->size >= 2 && (op == SA || op == SS))
			swap(s->a->arr);
		if (s->b->size >= 2 && (op == SB || op == SS))
			swap(s->b->arr);
	}
	else if (op == PA && s->b->size > 0)
		push(s->a, pop(s->b, 1), 1);
	else if (op == PB && s->a->size > 0)
		push(s->b, pop(s->a, 1), 1);
	else if (op == RA || op == RR)
	{
		if (s->a->size > 1 && (op == RA || op == RR))
			push(s->a, pop(s->a, 1), -1);
		if (s->b->size > 1 && (op == RB || op == RR))
			push(s->b, pop(s->b, 1), -1);
	}
	else if (op == RB && s->b->size > 1)
		push(s->b, pop(s->b, 1), -1);
	else if (op == RRA || op == RRR)
	{
		if (s->a->size > 1 && (op == RRA || op == RRR))
			push(s->a, pop(s->a, -1), 1);
		if (s->b->size > 1 && (op == RRB || op == RRR))
			push(s->b, pop(s->b, -1), 1);
	}
	else if (op == RRB && s->b->size > 1)
		push(s->b, pop(s->b, -1), 1);
	print_op(op);
}
