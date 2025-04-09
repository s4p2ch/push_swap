#include "header.h"

size_t optimize_sequence(t_op *seq, size_t seq_size)
{
    size_t optimized_size = 0;
    t_op optimized_seq[MAX_OPS];

    for (size_t i = 0; i < seq_size; i++)
    {
        if (optimized_size > 0 && 
            ((seq[i] == PA && optimized_seq[optimized_size - 1] == PB) || 
             (seq[i] == PB && optimized_seq[optimized_size - 1] == PA)))
        {
            // Remove PA+PB or PB+PA pair by not adding it to optimized_seq
            optimized_size--;
        }
        else
        {
            // Otherwise, add the current operation to the optimized sequence
            optimized_seq[optimized_size++] = seq[i];
        }
    }

    // Copy the optimized sequence back to the original array and return the size
    for (size_t i = 0; i < optimized_size; i++)
    {
        seq[i] = optimized_seq[i];
    }

    return optimized_size;
}

void radix_sort(t_stack *a, t_stack *b)
{
    t_op seq[MAX_OPS];
    size_t seq_size = 0;
    size_t size = a->size;
    int max_bits = 0;
    size_t max_num = size - 1;

    // Calculate number of bits needed
    while ((max_num >> max_bits) != 0)
        max_bits++;

    for (int bit = 0; bit < max_bits; bit++)
    {
        // Standard radix sort implementation
        for (size_t i = 0; i < size; i++)
        {
            if (((a->arr[0] >> bit) & 1) == 0)
            {
                apply_op(PB, a, b);
                seq[seq_size++] = PB;
            }
            else
            {
                apply_op(RA, a, b);
                seq[seq_size++] = RA;
            }
        }
        
        while (b->size > 0)
        {
            apply_op(PA, a, b);
            seq[seq_size++] = PA;
        }
    }

    // Optimize the sequence after generating it
    size_t optimized_size = optimize_sequence(seq, seq_size);
    
    // Print the optimized sequence
    print_seq(seq, optimized_size);
}


// void ft_memmove(void *dest, const void *src, size_t size) {
//     if (dest < src)
//         while (size--)
//             *(int *)dest++ = *(int *)src++;
//     else
//         while (size--)
//             *((int *)dest + size) = *((int *)src + size);

// }