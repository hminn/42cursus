#include "ft_strcapitalize.c"
#include <stdio.h>
int		main(void)
{
	char a[] = "salut, comment tu vas ? 42mots quaRante-deux; cinquante+et+un";
	printf("%s\n", a);
	printf("%s\n", ft_strcapitalize(a));
	return (0);
}
