#include "header.h"

int is_sorted(t_stack *a) {
    size_t     i;

    i = 0;
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

// if dest is on the left of src
// it will copy arr from the end
void ft_memmove(int *dest, const int *src, size_t size) {
    if (dest < src)
        while (size--)
            *dest++ = *src++;
    else
        while (size--)
            *(dest + size) = *(src + size);

}

// shift > 0 adds num to the beggining
// shift < 0 adds num to the ending
void push(t_stack *stack, int num, char shift)
{
    if (shift < 0)
        stack -> arr[stack -> size] = num;
    else
    {
        ft_memmove((stack -> arr) + 1, stack -> arr, stack -> size);
        stack -> arr[0] = num;
    }
    stack -> size++;
}

// decrements size first, so we dont need to use (size - 1)
// to reach the last element.
// with shift > 0 returns FIRST element
// with shift < 0 returns LAST element
int pop(t_stack *stack, char shift)
{
    int res;

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


// if (op == SA || op == SB || op == SS)
// {
//     if ((op == SA && a_stack -> size > 1) || 
//         (op == SS && a_stack -> size > 1 && b_stack -> size > 1))
//         swap(a_stack->arr);
//     if ((op == SB && b_stack -> size > 1) || 
//         (op == SS && b_stack -> size > 1 && a_stack -> size > 1))
//         swap(b_stack->arr);
// }
// pb pb ss


// we dont check if 'depth - 1' is negative
// as all instructs after 'depth && ...'
// with depth == 0 WONT be exacuted
int valid_op(t_op op, t_op *seq, size_t depth, size_t asize, size_t bsize, size_t ssize)
{
    if (op == SS)
        {
            int res = valid_op(SA, seq, depth, asize, bsize, ssize);
            int ret = valid_op(SB, seq, depth, asize, bsize, ssize);
            printf("\nSA %d || SB %d\nlast:%d\nlevel:%ld\n", res, ret, seq[depth], depth);
            print_seq(seq, depth);
            printf("\n=====\n");
            return res && ret;
        }
    return (
        (op == SA && asize > 1 \
                  && !(depth && (seq[depth - 1] == SA || seq[depth - 1] == SS))) || \
        (op == SB && bsize > 1 \
                  && !(depth && (seq[depth - 1] == SB || seq[depth - 1] == SS))) || \
        (op == SS && valid_op(SA, seq, depth, asize, bsize, ssize) \
                  && valid_op(SB, seq, depth, asize, bsize, ssize)) || \
        (op == PA && bsize > 0 && !(depth && seq[depth] == PB)) || \
        (op == PB && asize > 0 && !(depth && seq[depth] == PA)) || \
        (op == RA && asize > 1 \
                  && (depth < ssize || frequency(seq + depth - ssize, ssize, RA) < (int)ssize) \
                  && !(depth && seq[depth] == RRA)) || \
        (op == RB && bsize > 1 \
                  && (depth < ssize || frequency(seq + depth - ssize, ssize, RB) < (int)ssize) \
                  && !(depth && seq[depth] == RRB)) || \
        (op == RR && valid_op(RA, seq, depth, asize, bsize, ssize) \
                  && valid_op(RB, seq, depth, asize, bsize, ssize) \
                  && frequency(seq + depth - ssize, ssize, RR) < (int)ssize \
                  && !(depth && seq[depth] == RRR ))|| \
        (op == RRA && asize > 1 \
                   && (depth < ssize || frequency(seq + depth - ssize, ssize, RRA) < (int)ssize) \
                   && !(depth && seq[depth] == RA)) || \
        (op == RRB && bsize > 1 \
                   && (depth < ssize || frequency(seq + depth - ssize, ssize, RRB) < (int)ssize) \
                   && !(depth && seq[depth] == RB)) || \
        (op == RRR && valid_op(RA, seq, depth, asize, bsize, ssize) \
                   && valid_op(RB, seq, depth, asize, bsize, ssize) \
                   && frequency(seq + depth - ssize, ssize, RRR) < (int)ssize \
                   && !(depth && seq[depth] == RR))
    );
}

void brute_force(t_stack *a, t_stack *b, size_t depth, t_op *seq, size_t ssize) {
    t_op    op;
    if (depth >= MAX_OPS) return;
    if (!(b -> size) && is_sorted(a)) {
        print_seq(seq, depth);
    }

    for (op = SA; op <= RRR; op++) {
        if (valid_op(op, seq, depth, a -> size, b -> size, ssize)) {
            // t_stack a_copy = *a, b_copy = *b;
            // apply_op(op, &a_copy, &b_copy);
            seq[depth] = op;
            depth++;
            // brute_force(&a_copy, &b_copy, depth + 1, seq);
            printf("\n\nFOR OP: %d\n", op);
        }
    }
    print_seq(seq, depth);
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
    (void)sequence;
    apply_op(PB, &a, &b);
    apply_op(PB, &a, &b);
    apply_op(SS, &a, &b);

    brute_force(&a, &b, 0, sequence, ssize);
//    while(instr_counter != MAX_INSTR)
 //       if()
    print_stacks(&a, &b);

    free(b.arr);
}