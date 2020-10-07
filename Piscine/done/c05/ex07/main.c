#include "ft_find_next_prime.c"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int		main(void)
{
	int nb;

	printf("정수를 입력하세요 : ");
	scanf("%d",&nb);
	printf("%d 보다 크거나 같은 다음 소수는 %d 이다 \n", nb, ft_find_next_prime(nb));
	return (0);
}
