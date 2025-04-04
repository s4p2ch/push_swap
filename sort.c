#include "header.h"

void print_stacks(t_stack *sa, t_stack *sb)
{
    printf("\nA\n");
    for (size_t j = 0; j < sa->size; j++)
        printf("%d ", sa->arr[j]);
    printf("\nB\n");
    
    for (size_t j = 0; j < sb->size; j++)
        printf("%d ", sb->arr[j]);
    printf("\n");
}

// Calculate the cost of moving an element to the top of stack A
// int cost_to_top(size_t pos, size_t size)
// {
//     if (pos <= size / 2)
//         return pos; // Use ra
//     else
//         return size - pos; // Use rra
// }

// // Move element at position pos to the top of stack A
// void move_to_top_a(t_stack *a, t_stack *b, size_t pos)
// {
//     if (pos <= a->size / 2)
//     {
//         // Use ra
//         for (size_t i = 0; i < pos; i++)
//             apply_op(RA, a, b);
//     }
//     else
//     {
//         // Use rra
//         for (size_t i = 0; i < a->size - pos; i++)
//             apply_op(RRA, a, b);
//     }
// }

// // Move element at position pos to the top of stack B
// void move_to_top_b(t_stack *a, t_stack *b, size_t pos)
// {
//     if (pos <= b->size / 2)
//     {
//         // Use rb
//         for (size_t i = 0; i < pos; i++)
//             apply_op(RB, a, b);
//     }
//     else
//     {
//         // Use rrb
//         for (size_t i = 0; i < b->size - pos; i++)
//             apply_op(RRB, a, b);
//     }
// }

// Sort 2 or 3 elements in stack A
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
    
    // Normalize the stack (convert to indices)
    normalize(a.arr, a.size);
    
    // For small stacks, use simple algorithms
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
