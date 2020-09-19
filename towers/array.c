#include <stdlib.h>
#include <stdio.h>
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

// int			main(void)
// {
// 	char	**arr;

// 	arr = get_mem_for_char_arr(2, 2);
// 	free_mem_char_arr(arr, 2);
// 	printf("%c %c\n", arr[0][0], arr[0][1]);
// 	printf("%c %c\n", arr[1][0], arr[1][1]);
// }