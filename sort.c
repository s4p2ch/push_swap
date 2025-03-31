#include "header.h"

void apply_op(t_op op, t_stack *a_stack, t_stack *b_stack)
{
    if (op == SA || op == SB || op == SS)
    {
        if (a_stack -> size && (op == SA || op == SS))
            swap(a_stack->arr);
        if (op == SB || op == SS)
            swap(b_stack->arr);
    }
    else if (op == PA)
        push(a_stack, pop(b_stack, 1), 1);
    else if (op == PB)
        push(b_stack, pop(a_stack, 1), 1);
    if (op == RA || op == RR)
        push(a_stack, pop(a_stack, 1), -1);
    if (op == RB || op == RR)
        push(b_stack, pop(b_stack, 1), -1);

    if (op == RRA || op == RRR)
        push(a_stack, pop(a_stack, -1), 1);
    if (op == RRB || op == RRR)
        push(b_stack, pop(b_stack, -1), 1);
}

void print_stacks(t_stack *sa, t_stack *sb)
{
    printf("\nA\n");
	for (size_t j = 0; j <  sa -> size; j++)
        printf("%d ", sa -> arr[j]);
    printf("\nB\n");
    
	for (size_t j = 0; j <  sb -> size; j++)
        printf("%d ", sb -> arr[j]);
}


void sort_stack(int *stack, size_t ssize)
{
    t_stack     a;
    t_stack     b;
    t_op        sequence[MAX_OPS] = {0};

    a.arr = stack;
    a.size = ssize;
    b.arr = malloc(sizeof(int) * ssize);
    b.size = 0;
    printf("ssize:%ld\n", ssize);
    // brute_force(&a, &b, 0, sequence, ssize);


    print_stacks(&a, &b);

    free(b.arr);
}