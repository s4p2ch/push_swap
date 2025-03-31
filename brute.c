#include "header.h"

// counts the occurences of providen op
// in the seq from THE END
//
// level is the current elem,
// so we decrement it to get the last elem
int op_in_seq(t_op *seq, size_t level, t_op op)
{
    int res;

    if (!level)
        return 0;
    level--;
    res = 0;
    while(seq[level] == op)
    {
        res++;
        level--;
    }
    return (res);
}

int valid_op(t_op op, t_op *seq, size_t depth, size_t asize, size_t bsize, size_t ssize)
{
    t_op last_op;

    last_op = SIZE;
    if (depth)
        last_op = seq[depth - 1];
    return (
        (op == SA && asize > 1 && last_op != SA && last_op != SS) || \
        (op == SB && bsize > 1 && last_op != SB && last_op != SS) || \
        (op == SS && valid_op(SA, seq, depth, asize, bsize, ssize) \
                  && valid_op(SB, seq, depth, asize, bsize, ssize)) || \
        (op == PA && bsize > 0 && last_op != PB) || \
        (op == PB && asize > 0 && last_op != PA) || \
        (op == RA && asize > 1 && last_op != RRA \
                  && (depth < ssize || frequency(seq + depth - ssize, ssize, RA) < (int)ssize)) || \
        (op == RB && bsize > 1 && last_op != RRB \
                  && (depth < ssize || frequency(seq + depth - ssize, ssize, RB) < (int)ssize)) || \
        (op == RR && valid_op(RA, seq, depth, asize, bsize, ssize) \
                  && valid_op(RB, seq, depth, asize, bsize, ssize) \
                  && op_in_seq(seq, depth, RR) < (int)ssize \
                  && last_op != RRR) || \
        (op == RRA && asize > 1 && last_op != RA \
                   && (depth < ssize || op_in_seq(seq, depth, RRA) < (int)ssize < (int)ssize)) || \
        (op == RRB && bsize > 1 && last_op != RB \
                   && (depth < ssize || op_in_seq(seq, depth, RRB) < (int)ssize < (int)ssize)) || \
        (op == RRR && valid_op(RRA, seq, depth, asize, bsize, ssize) \
                   && valid_op(RRB, seq, depth, asize, bsize, ssize) \
                   && op_in_seq(seq, depth, RRR) < (int)ssize \
                   && last_op != RR)
    );
}

int brute_force(t_stack *a, t_stack *b, size_t depth, t_op *seq, size_t ssize) {
    t_op    op;
    if (depth >= MAX_OPS) return 0;
    if (!(b -> size) && is_sorted(a)) {
        printf("sas\n");
        print_seq(seq, depth);
        return 1;
    }

    for (op = SA; op <= RRR; op++) {
        // if (valid_op(op, seq, depth, a -> size, b -> size, ssize)) {
            t_stack a_copy = *a, b_copy = *b;
            apply_op(op, &a_copy, &b_copy);
            seq[depth] = op;
            if(brute_force(&a_copy, &b_copy, depth + 1, seq, ssize))
                return 1;
        // }
    }
    return 0;
}
