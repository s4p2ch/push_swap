#include "header.h"

int is_sorted(t_stack *a) {
    int     i;

    while(i < a->size - 1)
        if (a->arr[i] > a->arr[i + 1])
            return 0;
        else
            i++;
    return 1;
}

void swap(int arr[])
{
    int temp;

    temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;
}

void ft_memmove(int *dest, const int *src, size_t size) {
    while (size--)
        *dest++ = *src++;
}

// void push(t_stack *stack, int num, char shift)
// {

// }

// decrements size first, so we dont need to use (size - 1)
// to reach the last element.
// with shift > 0 returns FIRST element
// with shift < 0 returns LAST element
int pop(t_stack *stack, char shift)
{
    int res;
    int *i;

    stack -> size--;
    if (shift > 0)
    {
        res = stack -> arr[0];
        ft_memmove(stack -> arr, (stack -> arr) + 1, stack -> size);
    }
    else
        res = stack -> arr[stack -> size];
    return res;
}

void apply_op(t_op op, t_stack *a_stack, t_stack *b_stack)
{
    if (op == SA || op == SS)
        swap(a_stack->arr);
    if (op == SB || op == SS)
        swap(b_stack->arr);
    // if (op == PA)
    //     push(a_stack, pop(b_stack));
    if (op == PA)
        pop(a_stack -> arr, 1);
}

void sort_stack(int *stack, int size)
{
    t_stack     a;
    t_stack     b;
    t_op        sequence[MAX_OPS];

    a.arr = stack;
    a.size = size;
    b.arr = malloc(sizeof(int) * size);
    b.size = 0;
    printf("size:%d\n", size);
    (void)sequence;
    // brute_force(&a, &b, 0, &sequence);
//    while(instr_counter != MAX_INSTR)
 //       if()
    apply(PA, &a);
	for (int j = 0; j < size; j++)
        printf("%d ", a.arr[j]);
    free(b.arr);
}

void brute_force(t_stack *a, t_stack *b, size_t depth, t_op *seq) {
    t_op    op;
    int     i;
    if (depth >= MAX_OPS) return;
    if (!(b -> size) && is_sorted(a)) {
        print_seq(seq, depth);
    }

    for (op = SA; op <= RRR; op++) {
        // if (valid_op(seq, depth, op)) {
            t_stack a_copy = *a, b_copy = *b;
            apply_op(&a_copy, &b_copy, op);
            seq[depth] = op;
            brute_force(&a_copy, &b_copy, depth + 1, seq);
        // }
    }
}
