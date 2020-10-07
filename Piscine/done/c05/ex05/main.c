#include "ft_sqrt.c"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int		main(void)
{
	int a = 2147483647;

	printf("%d의 제곱근은 %d\n", a, ft_sqrt(a));
	printf("%d의 제곱근은 %d\n", 400000000, ft_sqrt(400000000));
	printf("%d의 제곱근은 %d\n", 1000000000, ft_sqrt(a));
	printf("%d의 제곱근은 %d\n", 1177313344, ft_sqrt(1177313344));
	printf("%d의 제곱근은 %d\n", a, ft_sqrt(a));

	return (0);
}
