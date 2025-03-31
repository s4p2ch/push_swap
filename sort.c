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


// we dont check if 'depth - 1' is negative
// as all instructs after 'depth && ...'
// with depth == 0 WONT be exacuted
int valid_op(t_op op, t_op *seq, size_t depth, size_t asize, size_t bsize, size_t ssize)
{
    return (
        (op == SA && asize > 1 \
                  && !(depth && (seq[depth - 1] == SA || seq[depth - 1] == SS))) || \
        (op == SB && bsize > 1 \
                  && !(depth && (seq[depth - 1] == SB || seq[depth - 1] == SS))) || \
        (op == SS && valid_op(SA, seq, depth, asize, bsize, ssize) \
                  && valid_op(SB, seq, depth, asize, bsize, ssize)) || \
        (op == PA && bsize > 0 && !(depth && seq[depth - 1] == PB)) || \
        (op == PB && asize > 0 && !(depth && seq[depth - 1] == PA)) || \
        (op == RA && asize > 1 \
                  && (depth < ssize || frequency(seq + depth - ssize, ssize, RA) < (int)ssize) \
                  && !(depth && seq[depth - 1] == RRA)) || \
        (op == RB && bsize > 1 \
                  && (depth < ssize || frequency(seq + depth - ssize, ssize, RB) < (int)ssize) \
                  && !(depth && seq[depth - 1] == RRB)) || \
        (op == RR && valid_op(RA, seq, depth, asize, bsize, ssize) \
                  && valid_op(RB, seq, depth, asize, bsize, ssize) \
                  && frequency(seq + depth - ssize, ssize, RR) < (int)ssize \
                  && !(depth && seq[depth - 1] == RRR ))|| \
        (op == RRA && asize > 1 \
                   && (depth < ssize || frequency(seq + depth - ssize, ssize, RRA) < (int)ssize) \
                   && !(depth && seq[depth - 1] == RA)) || \
        (op == RRB && bsize > 1 \
                   && (depth < ssize || frequency(seq + depth - ssize, ssize, RRB) < (int)ssize) \
                   && !(depth && seq[depth - 1] == RB)) || \
        (op == RRR && valid_op(RA, seq, depth, asize, bsize, ssize) \
                   && valid_op(RB, seq, depth, asize, bsize, ssize) \
                   && frequency(seq + depth - ssize, ssize, RRR) < (int)ssize \
                   && !(depth && seq[depth - 1] == RR))
    );
}
void	ft_memcpy(void *dst, const void *src, size_t size)
{
	while (size--)
		*(char *)dst++ = *(char *)src++;
}


void brute_force(t_stack *a, t_stack *b, size_t depth, t_op *seq, size_t ssize, t_op *best_seq, size_t *best_level) {
    t_op    op;
    if (depth >= MAX_OPS) return;
    if (!(b -> size) && is_sorted(a)) {
		if(depth < *best_level) {
			*best_level = depth;
			ft_memcpy(best_seq, seq, sizeof(t_op) * depth);
		}
        if (depth < 10) {printf("\n !!find seq:\n");
        print_seq(seq, depth);
        }
        return;
    }

    for (op = SA; op <= RRR; op++) {
        if (valid_op(op, seq, depth, a -> size, b -> size, ssize)) {
            t_stack a_copy = *a, b_copy = *b;
            apply_op(op, &a_copy, &b_copy);
            seq[depth] = op;
            brute_force(&a_copy, &b_copy, depth + 1, seq, ssize, best_seq, best_level);
        }
    }
}


void sort_stack(int *stack, size_t ssize)
{
    t_stack     a;
    t_stack     b;
    t_op        sequence[MAX_OPS] = {0};
	t_op        best_seq[MAX_OPS] = {0};
	size_t      best_level = MAX_OPS;

    a.arr = stack;
    a.size = ssize;
    b.arr = malloc(sizeof(int) * ssize);
    b.size = 0;
    printf("ssize:%ld\n", ssize);

    brute_force(&a, &b, 0, sequence, ssize, best_seq, &best_level);
    print_seq(best_seq, best_level);


    print_stacks(&a, &b);

    free(b.arr);
}