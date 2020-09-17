#include <stdio.h>
#include "libft.h"
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

char	func(unsigned int i, char c)
{
	if (i % 2 == 0)
		c = 48;
	return (c);
}

int		main(void)
{
	char a[10] = {"abcde"};
	char b[10] = {"LoveYa"};
	char c[10] = {"LoveYou"};
	char d[20] = {"I Love You"};
	char e[20] = {"I Hate me"};
	char *f = "ABC12ABC332BA";
	char *g = " efg";
	int	*h;
	char *i = " 	+-123";
	char *j;
	char *k = "2BC1A";
	int	value = '*';

	printf("-----------ft_strlen------------\n");
	printf("%s의 길이는 ft_strlen : %ld\n", a, ft_strlen(a));
	printf("-----------ft_memset------------\n");
	printf("ft_memset 이전 : %s\n", a);
	ft_memset(a, value, 8);
	printf("ft_memset 이후 : %s\n", a);
	printf("-----------ft_memcmp----------\n");
	printf("%s 와 %s 의 ft_memcmp(%d) 결과는 %d\n", b, c, 6, ft_memcmp(b, c, 6));
	printf("-----------ft_memcpy----------\n");
	printf("%s 에 %s 를 ft_memcpy(%d)한 결과는 ", d, e, 4);
	ft_memcpy(d + 2, e + 2, 4);
	printf("%s이다.\n", d);
	printf("-----------ft_strnstr----------\n");
	printf("%s와 %s의 ft_strnstr(%d)한 결과는 : %s\n ", f, g, 10, ft_strnstr(f,g,10));
	printf("-----------ft_calloc----------\n");
	// h = (int *)malloc(3 * sizeof(int));
	h = (int *)ft_calloc(3, sizeof(int));
	printf("h[0] : %d\nh[1] : %d\nh[2] : %d \n", h[0], h[1], h[2]);
	free(h);
	printf("-----------ft_atoi----------\n");
	printf("%s 의 ft_atoi 결과는 : %d\n", i, ft_atoi(i));
	printf("-----------ft_substr----------\n");
	j = ft_substr(f,0,ft_strlen(f));
	printf("%s 의 ft_substr(%d)의 결과는 : %s\n", f, 0, j);
	free(j);
	printf("-----------ft_strjoin----------\n");
	j = ft_strjoin(f, g);
	printf("%s 와 %s 의 ft_strjoin의 결과는 : %s$\n", f, g, j);
	free(j);
	printf("-----------ft_strtrim----------\n");
	j = ft_strtrim(f, k);
	printf("%s 와 %s 의 ft_strtrim의 결과는 : %s$\n", f, k, j);
	free(j);
	printf("-----------ft_itoa----------\n");
	int	num = 0;
	j = ft_itoa(num);
	printf("%d 의 ft_itoa의 결과는 : %s\n", num, j);
	free(j);
	printf("-----------ft_split----------\n");
	char *z = "abc d efgeh";
	char y = ' ';
	char **n;
	n = ft_split(z, y);
	printf("%s의 ft_split(%c)의 결과는 : %s, %s, %s, %s\n", z, y, n[0], n[1], n[2], n[3]);
	// printf("%s의 ft_split(%c)의 결과는 : %s\n", z, y, n[0]);
	free(n[0]);
	free(n[1]);
	free(n[2]);
	free(n);
	printf("-----------ft_strmapi----------\n");
	char *m = "abcdefg";
	printf("%s의 ft_strmapi의 결과는 :", m);
	m = ft_strmapi(m, &func);
	printf("%s\n", m);
	free(m);
	printf("-----------ft_put_fd 함수----------\n");
	int fd;
	fd = open("text.txt", O_RDWR);
	ft_putchar_fd('c', fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("Hello World",fd);
	ft_putchar_fd('\n', fd);
	ft_putendl_fd("Hi My Name is", fd);
	ft_putnbr_fd(123456, fd);
	close(fd);
	printf("\200 : %d\n", '\200');
	// printf("\0 : %c\n", '\0');
}
