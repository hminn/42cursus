#include "ft_recursive_factorial.c"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int		main(void)
{
	int	a = -3;
	printf("%d\n", a);
	printf("%d\n", ft_recursive_factorial(a));
	return (0);
}
