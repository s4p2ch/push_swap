#include "header.h"



void sort_small(t_stack *a, t_stack *b)
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

void sort_stack(int *stack, size_t ssize)
{
    t_stack a;
    t_stack b;

    a.arr = stack;
    a.size = ssize;
    b.arr = malloc(sizeof(int) * ssize);
    b.size = 0;
    
    // printf("ssize:%ld\n", ssize);
    
    // Check if already sorted
    if (is_sorted(&a))
    {
        free(b.arr);
        return;
    }
    normalize(a.arr, a.size);
    
    if (ssize <= 5)
        sort_small(&a, &b);
    else
	//  if (ssize <= 100)
    //     insertion_sort(&a, &b);
    // else
	{

        radix_sort(&a, &b);
		// radix_sort(&a, &b);
		// optimize_seq(&seq);
	}
    
    // print_stacks(&a, &b);
    free(b.arr);
}
