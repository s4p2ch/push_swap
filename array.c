# include "header.h"

int	is_sorted(t_stack *a)
{
	size_t	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->arr[i] > a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}


void swap(int arr[])
{
    int temp;

    temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;
}

// if dest is on the left of src in memory
// it will copy arr from the end
static void ft_memmove(int *dest, const int *src, size_t size) {
    if (dest < src)
        while (size--)
            *dest++ = *src++;
    else
        while (size--)
            *(dest + size) = *(src + size);

}

// shift > 0 adds num to the beggining
// shift < 0 adds num to the ending
void push(t_stack *stack, int num, char shift)
{
    if (shift < 0)
        stack -> arr[stack -> size] = num;
    else
    {
        ft_memmove((stack -> arr) + 1, stack -> arr, stack -> size);
        stack -> arr[0] = num;
    }
    stack -> size++;
}

// decrements size first, so we dont need to use (size - 1)
// to reach the last element.
// with shift > 0 returns FIRST element
// with shift < 0 returns LAST element
int pop(t_stack *stack, char shift)
{
    int res;

    stack -> size--;
    if (shift > 0)
    {
        res = stack -> arr[0];
        ft_memmove(stack -> arr, (stack -> arr) + 1, stack -> size);
    }
    else
        res = stack -> arr[stack -> size];
    return res;
}


// Function to normalize the stack (convert to indices)
void normalize(int *stack, size_t size)
{
    int *sorted = malloc(sizeof(int) * size);
    int *normalized = malloc(sizeof(int) * size);
    
    // Copy the original stack
    for (size_t i = 0; i < size; i++)
        sorted[i] = stack[i];
    
    // Sort the copy
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (sorted[j] > sorted[j + 1])
            {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }
    
    // Create normalized array
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (stack[i] == sorted[j])
            {
                normalized[i] = j;
                break;
            }
        }
    }
    
    // Copy normalized values back to original stack
    for (size_t i = 0; i < size; i++)
        stack[i] = normalized[i];
    
    free(sorted);
    free(normalized);
}
