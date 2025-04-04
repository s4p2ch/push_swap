#include "header.h"

void radix_sort(t_stack *a, t_stack *b)
{
	t_op seq[MAX_OPS];
	size_t seq_size = 0;
    size_t size = a->size;
    int max_bits = 0;
	t_op op;
    size_t max_num = size - 1;  // After normalization, max number is size-1

    // Calculate number of bits needed
    while ((max_num >> max_bits) != 0)
        max_bits++;
    
    // Perform radix sort
    for (int bit = 0; bit < max_bits; bit++)
    {
        for (size_t i = 0; i < size; i++)
        {
            // If bit is 0, push to B
            if (((a->arr[0] >> bit) & 1) == 0)
                op = PB;
            else
                op = RA;
			apply_op(op, a, b);
			seq[seq_size++] = op;
        }
        
        // Push everything back to A
        while (b->size > 0)
		{
            apply_op(PA, a, b);
			seq[seq_size++] = PA;
		}
    }
	optimize_seq(seq, seq_size);
	print_seq(seq, seq_size);
}
