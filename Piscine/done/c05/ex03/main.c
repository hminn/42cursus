#include "ft_recursive_power.c"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int		main(void)
{
	int a = -2;
	int power = 4;

	printf("%d의%d제곱은 : %d\n", a, power, ft_recursive_power(a, power));
	return (0);
}
