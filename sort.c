#include "header.h"

void micro_sort(t_stack *a, t_stack *b)
{
    if (a->size == 2)
    {
        if (a->arr[0] > a->arr[1])
            apply_op(SA, a, b);
    }
    else if (a->size == 3)
    {
        if (a->arr[0] > a->arr[1] && a->arr[0] > a->arr[2])
        {
            apply_op(RA, a, b);
            if (a->arr[0] > a->arr[1])
                apply_op(SA, a, b);
        }
        else if (a->arr[0] > a->arr[1])
        {
            apply_op(SA, a, b);
        }
        else if (a->arr[1] > a->arr[2])
        {
            apply_op(RRA, a, b);
            if (a->arr[0] > a->arr[1])
                apply_op(SA, a, b);
        }
    }
}

// Helper: find index of the minimum in A
// static size_t find_min_pos(t_stack *a)
// {
//     size_t min_pos = 0;
//     for (size_t i = 1; i < a->size; i++)
//         if (a->arr[i] < a->arr[min_pos])
//             min_pos = i;
//     return min_pos;
// }

// void insertion_sort(t_stack *a, t_stack *b)
// {
//     size_t min_pos;

//     // Phase 1: move all elements from A to B, smallest first
//     while (a->size > 0)
//     {
//         min_pos = find_min_pos(a);

//         // rotate A to bring the minimum to the top
//         if (min_pos <= a->size / 2)
//         {
//             while (min_pos--)
//                 apply_op(RA, a, b);
//         }
//         else
//         {
//             size_t moves = a->size - min_pos;
//             while (moves--)
//                 apply_op(RRA, a, b);
//         }

//         // push the min element to B
//         apply_op(PB, a, b);
//     }

//     // Phase 2: everything’s in B, smallest at bottom; push back to A
//     while (b->size > 0)
//         apply_op(PA, a, b);
// }

void sort_stack(int *stack, size_t ssize)
{
    t_stack a;
    t_stack b;

    a.arr = stack;
    a.size = ssize;
    b.arr = malloc(sizeof(int) * ssize);
    b.size = 0;
    if (is_sorted(&a))
    {
        free(b.arr);
        return;
    }
    normalize(a.arr, a.size);
    if (ssize <= 5)
        micro_sort(&a, &b);
	else
		butterfly_sort(&a, &b);
    free(b.arr);
}
