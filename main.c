#include "header.h"

int ft_atoi(char *str, int *i) {
	int i = 0;
	int res = 0;

	return res;
}

int parse(char **argv, int *arr, int i) {
	int num;

	num = ft_atoi(argv[i + 1], &i);
	if(i < 0)
		return (EXIT_FAILURE);

	(void)arr;

	return (EXIT_SUCCESS);
}

int main(int argc, char **argv) {
	int *arr;
	int i;

	if (argc < 2)
		return (ft_write(argv[0]), EXIT_FAILURE);
	i = 0;
	arr = malloc(sizeof(int) * (argc - 1));
	if (!arr)
		return (ft_write("Error\n"), EXIT_FAILURE);
	printf("size: %d", argc);
	while (argv[i++])
		if(parse(argv, arr, i))
			return(ft_write("Error\n"), free(arr), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}