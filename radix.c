#include "header.h"


void optimize_seq(t_op *seq, size_t seq_size) {
    size_t i;
    size_t new_size;
    t_op *p;
    int counter;
    int range;

    i = 0;
    p = seq;
    counter = 0;
    while(i < seq_size)
    {
        if (*p == PA)
        {   // check PBs before current PA
            range = min(counter, seqoccur(PB, -1));
            counter -= range;
            p -= range;
            new_size -= range * 2;

            // check PBs after current PA
            range = min(counter, seqoccur(PB, +1));
            counter -= range;
            p -= range;
            new_size -= range * 2;
        }
        i++;
    }
}

void radix_sort(t_stack *a, t_stack *b)
{
	t_op seq[MAX_OPS];
	size_t seq_size = 0;
    size_t size = a->size;
    int max_bits = 0;
	t_op op;
    size_t max_num = size - 1; 

    while ((max_num >> max_bits) != 0)
        max_bits++;
    
    for (int bit = 0; bit < max_bits; bit++)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (((a->arr[0] >> bit) & 1) == 0)
                op = PB;
            else
                op = RA;
			apply_op(op, a, b);
			seq[seq_size++] = op;
        }
        
        while (b->size > 0)
		{
            apply_op(PA, a, b);
			seq[seq_size++] = PA;
		}
    }
    (void)seq;
	// optimize_seq(seq, seq_size);
	// print_seq(seq, seq_size);
}
