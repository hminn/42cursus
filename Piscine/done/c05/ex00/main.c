#include "ft_iterative_factorial.c"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int		main(void)
{
	int a = 1;
	printf("%d => %d \n", a, ft_iterative_factorial(a));
	return (0);
}
