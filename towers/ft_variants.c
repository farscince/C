/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 19:32:55 by tvernita          #+#    #+#             */
/*   Updated: 2020/08/30 19:40:13 by tvernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			next_perm(char *a, int n)
{
	int		i;
	int		k;
	int		t;

	k = n - 2;
	while ((a[k] > a[k + 1]) && (k >= 0))
		if (--k < 0)
			break ;
	if (k == -1)
		return (0);
	t = n - 1;
	while ((a[k] > a[t]) && (t >= k + 1))
		t--;
	swap(&a[k], &a[t]);
	i = k + 1;
	while (i <= (n + k) / 2)
	{
		t = n + k - i;
		swap(&a[i], &a[t]);
		i++;
	}
	return (i);
}

char		**ft_variants(int rang)
{
	int		i;
	char	*a;
	char	**arr;
	int		j;

	j = 0;
	a = (char *)malloc((rang + 1) * sizeof(char));
	arr = get_mem_for_char_arr(rang + 1, ft_factorial(rang));
	i = -1;
	while (++i < rang)
		a[i] = '0' + i + 1;
	a[i] = 0;
	arr[j] = ft_strcpy(arr[j], a);
	while (next_perm(a, rang))
	{
		j++;
		arr[j] = ft_strcpy(arr[j], a);
	}
	ft_showmatrix(arr, rang, ft_factorial(rang));
	free(a);
	return (arr);
}
