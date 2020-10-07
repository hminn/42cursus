#include "ft_is_prime.c"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int		main(void)
{
	int i = 0;

	while (i != -100)
	{
		printf("소수 여부가 궁금한 정수를 입력하세요 (종료:-100) : ");
		scanf("%d", &i);
		printf("%d는 소수인가요? (yes = 1, no = 0) : %d\n", i, ft_is_prime(i));
	}
	return (0);
}
