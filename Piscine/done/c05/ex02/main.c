#include "ft_iterative_power.c"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int		main(void)
{
	int a = -5;
	int power = 3;


	printf("%d\n", ft_iterative_power(a, power));
	return (0);
}
