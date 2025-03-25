#include "header.h"

int is_sorted(t_stack *a) {
    int     i;

    while(i < a->size - 1)
        if (a->arr[i] > a->arr[i + 1])
            return 0;
        else
            i++;
    return 1;
}

int swap(int arr[])
{
    int temp;

    temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;
    return 1;
}

int apply(t_op instr, t_stack stack)
{
    if (instr == SA)
        return(stack.size > 2 && swap(stack.arr));
    return 0;
}

void sort_stack(int *stack, int size)
{
    t_stack     a;
    t_stack     b;
    int         instr_counter;

    instr_counter = 0;
    a.arr = stack;
    a.size = size;
    b.arr = malloc(sizeof(int) * size);
    b.size = 0;
    printf("size:%d\n", size);
    (void)b;
    (void)instr_counter;
//    while(instr_counter != MAX_INSTR)
 //       if()
    apply(SA, a);
	for (int j = 0; j < size; j++)
        printf("%d ", a.arr[j]);
    free(b.arr);
}
