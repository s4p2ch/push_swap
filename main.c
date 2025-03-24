#include "header.h"

int ft_atoi(char *str, int *i) {
	long	res;
	int		sign;

	res = 0;
	sign = 1;

	if (*str == '-') 
	{
		sign = -1;
		str++;
	}
	while(*str)
		if (*str >= '0' && *str <= '9')
			{
				res *= 10;
				res += *str - '0'; 
				str++;
			}
		else 
			return (*i = -1, 0);
	if (res * sign != (int)(res * sign))
		return (*i = -1, 0);
	return (res * sign);
}

int parse(char **argv, int *arr, int i) {
	int num;

	num = ft_atoi(argv[i], &i);
	if(i < 0)
		return (EXIT_FAILURE);
	arr[i - 1] = num;
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv) {
	int *arr;
	int i;

	if (argc < 2)
		return (ft_write(argv[0]), EXIT_FAILURE);
	arr = malloc(sizeof(int) * (argc - 1));
	if (!arr)
		return (ft_write("Error\n"), EXIT_FAILURE);
	printf("size: %d\n", argc);
	i = 0;
	while (argv[++i])
		if(parse(argv, arr, i))
			return(ft_write("Error\n"), free(arr), EXIT_FAILURE);
	for (int j = 0; j < argc; j++)
			printf("%d ", arr[j]);
	return (EXIT_SUCCESS);
}