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

void	apply_op(t_op op, t_data *ss)
{
	if (ss->a->size >= 2 && (op == SA || op == SS))
		swap(ss->a->arr);
	if (ss->b->size >= 2 && (op == SB || op == SS))
		return (swap(ss->b->arr));
	if (op == PA && ss->b->size > 0)
		return (push(ss->a, pop(ss->b, 1), 1));
	if (op == PB && ss->a->size > 0)
		return (push(ss->b, pop(ss->a, 1), 1));
	if (ss->a->size > 1 && (op == RA || op == RR))
		push(ss->a, pop(ss->a, 1), -1);
	if (ss->b->size > 1 && (op == RB || op == RR))
		return (push(ss->b, pop(ss->b, 1), -1));
	if (ss->a->size > 1 && (op == RRA || op == RRR))
		push(ss->a, pop(ss->a, -1), 1);
	if (ss->b->size > 1 && (op == RRB || op == RRR))
		return (push(ss->b, pop(ss->b, -1), 1));
	print_op(op);
}
