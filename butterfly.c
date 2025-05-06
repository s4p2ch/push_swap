#include "header.h"

// Find the position of the highest value in stack
static int find_max_pos(t_stack *b)
{
    int max_pos = 0;
    for (size_t i = 1; i < b->size; i++)
    {
        if (b->arr[i] > b->arr[max_pos])
            max_pos = i;
    }
    return max_pos;
}

void butterfly_sort(t_stack *a, t_stack *b)
{
    size_t size = a->size;
	double chunk_percent = 20.0 - (size - 100) * (15.0 / 400.0); // 597 5144
	   size_t chunk_size = (size / 100) * chunk_percent; // avg: 596 \ 5149
    // size_t chunk_size = (size / 100) * 20; // avg: 633 \ 5322
    // size_t chunk_size = 20 + (size / 100) * 5; // avg: 628 \ 5319
    size_t next = 0; // next smallest value we expect

    while (a->size)
        if ((size_t)a->arr[0] <= next)
        {
            apply_op(PB, a, b);
            apply_op(RB, a, b);
            next++;
        }
        else if ((size_t)a->arr[0] <= next + chunk_size)
        {
            apply_op(PB, a, b);
            next++;
        }
        else
            apply_op(RA, a, b);


    while (b->size)
    {
        int max_pos = find_max_pos(b);

        if (max_pos <= (int)(b->size / 2))
            while (max_pos--)
                apply_op(RB, a, b);
        else
        {
            max_pos = b->size - max_pos;
            while (max_pos--)
                apply_op(RRB, a, b);
        }
        apply_op(PA, a, b);
    }
}
