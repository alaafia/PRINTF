#include <stdio.h>
#include "ft_printf.h"

#define TEST "|%-44d|",10000

int		main()
{
	int c;

	ft_printf("|%d|\n", ft_printf(TEST));
	printf("|%d|\n", printf(TEST));

}