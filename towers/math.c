#include <stdio.h>
#include "ft.h"

int			ft_factorial(int n)
{
	if (n == 0)
		return (1);
	return (n * ft_factorial(n - 1));
}