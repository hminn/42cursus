#include "ft_putstr_non_printable.c"
#include <stdio.h>
int		main(void)
{
	char	a[10] = {30, 32, 65, 66, -1, -10, 58, 67, 69, 0};
	ft_putstr_non_printable(a);
	return (0);
}
