#include <stdlib.h>
#include "ft.h"

char		**get_mem_for_char_arr(int x, int y)
{
	char	**arr;
	int		i;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * y);
	while (i < y)
	{
		arr[i] = (char *)malloc(sizeof(char) * x);
		i++;
	}
	return (arr);
}

void		free_mem_char_arr(char **arr, int y)
{
	int		i;

	i = 0;
	while (i < y)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
