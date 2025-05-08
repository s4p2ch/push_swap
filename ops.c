#include "header.h"

void print_stacks(t_stack *sa, t_stack *sb)
{
    printf("\ta   ");
    for (size_t j = 0; j < sa->size; j++)
        printf("%d ", sa->arr[j]);
    printf("\t\tb   ");
    
    for (size_t j = 0; j < sb->size; j++)
        printf("%d ", sb->arr[j]);
    printf("\n");
}

void print_op(t_op op)
{
    const char *op_str[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
    printf("%s\n", op_str[op]);
}

void apply_op(t_op op, t_stack *a_stack, t_stack *b_stack)
{
    // print_stacks(a_stack, b_stack);

    if (op == SA || op == SB || op == SS)
    {
        if (a_stack->size >= 2 && (op == SA || op == SS))
            swap(a_stack->arr);
        if (b_stack->size >= 2 && (op == SB || op == SS))
            swap(b_stack->arr);
    }
    else if (op == PA && b_stack->size > 0)
        push(a_stack, pop(b_stack, 1), 1);
    else if (op == PB && a_stack->size > 0)
        push(b_stack, pop(a_stack, 1), 1);
    else if (op == RA || op == RR)
    {
        if (a_stack->size > 1 && (op == RA || op == RR))
            push(a_stack, pop(a_stack, 1), -1);
        if (b_stack->size > 1 && (op == RB || op == RR))
            push(b_stack, pop(b_stack, 1), -1);
    }
    else if (op == RB && b_stack->size > 1)
        push(b_stack, pop(b_stack, 1), -1);
    else if (op == RRA || op == RRR)
    {
        if (a_stack->size > 1 && (op == RRA || op == RRR))
            push(a_stack, pop(a_stack, -1), 1);
        if (b_stack->size > 1 && (op == RRB || op == RRR))
            push(b_stack, pop(b_stack, -1), 1);
    }
    else if (op == RRB && b_stack->size > 1)
        push(b_stack, pop(b_stack, -1), 1);
    
    print_op(op);
}
