/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeschall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 17:00:27 by yeschall          #+#    #+#             */
/*   Updated: 2020/09/01 11:45:51 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void		ft_putstr(char *str);
// void		ft_showmatrix(char **arr, int x, int y);
// int			check_views(int v1, int v2, char *arr);

char		**ft_create_arr(int x, int y)
{
	printf("create arr %dx%d\n", x, y);
	char	**arr;
	int		j;

	j = 0;
	if (y == 1)
	{
		arr = (char **)malloc(sizeof(char *));
	}
	arr = (char **)malloc(y * sizeof(char *));
	while (j < y)
	{
		arr[j] = (char *)malloc(x * sizeof(char));
		j++;
	}
	return (arr);
}

int			is_valid_str(char *str)
{
	printf("validation...\n");
	int 	i;
	int 	j;
	int 	k;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		if ((i % 2 == 1) && str[i] != 32)
			return (-2);
		if ((i % 2 == 0) && (str[i] < 49 || str[i] > 52))
			return (-3);
		i++;
	}
	if (i != (N * 4 * 2 - 1))
		return (-4);	
	// i = 0;
	// k = 0;
	// while(str[i])
	// {
	// 	if (((i < 7) || (i > 15 && i < 23)) && (i % 2 == 0))
	// 	{
	// 		k = str[i] + str[i + 8];
	// 		if (k < '3' || k > ('1' + N))
	// 			return (0);
	// 	}
	// 	i++;
	// }
	return (1);
}

// int			ft_count_list(char **generator, int v1, int v2, int *p)
// {
// 	int		j;
// 	int		counter;;

// 	counter = 0;
// 	j = 0;
// 	while (j < 24)
// 	{
// 		if (check_views(v1, v2, generator[j]) == 1)
// 		{
// 			p = &j;
// 			counter++;
// 		}
// 		j++;
// 	}
// 	return (counter);
// }

char		**split_views(int x, int y, char *str)
{
	printf("split views...\n");
	char	**arr;
	int		i;
	int		j;

	i = 0;
	arr = ft_create_arr(x, y);
	while (str[i])
	{
		if (i % 2 == 0)
		{
			// printf("i = %d str[i] = %c\n", i, str[i]);
			// if (i < N * 2)
			// {

			// 	printf("1arr[%d][0] = %c\n", i/2, str[i]);
			// 	arr[i / 2][0] = str[i];
			(i < N * 2)? arr[i / 2][0] = str[i] : 0;
			// }
			// if (N * 2 <= i && i < N * 4)
			// {
			// 	printf("2arr[%d][1] = %c\n", i/2 - N, str[i]);
			// 	arr[i / 2 - N][1] = str[i];
			// }
			(N * 2 <= i && i < N * 4) ? arr[i / 2 - N][1] = str[i] : 0;
			// if (N * 4 <= i && i < N * 6)
				// printf("3arr[%d][0] = %c\n", i/2 - N, str[i]);
			(N * 4 <= i && i < N * 6) ? arr[i / 2 - N][0] = str[i] : 0;
			// if (N * 6 <= i) 
			// 	printf("4arr[%d][1] = %c\n", i/2 - N*2, str[i]);
			(N * 6 <= i) ? arr[i / 2 - N * 2][1] = str[i] : 0;
		}
		i++;
	}
	return (arr);
}

int			main(int argc, char **argv)
{
	char 	**res_arr;
	char	**views_arr;

	t_list	*p;
	int		result;

	res_arr = NULL;
	if (argc == 2)
	{
		printf("argc == 2\n");
		if (is_valid_str(argv[1]) == 1)
		{
			printf(" str is valid\n");
			views_arr = split_views(2, N * 2,argv[1]);
			ft_showmatrix(views_arr, 2, 8);
			p = create_struct(views_arr);
			if (is_valid_map(&p, res_arr))
			{
				ft_showmatrix(res_arr, N, N);
				//clear_malloc(p, res_arr, views_arr);
				return (0);
			}
		}
	}
	ft_putstr("Error");
	return (0);
}
