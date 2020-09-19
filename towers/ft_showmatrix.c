/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_showmatrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvernita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 17:20:01 by tvernita          #+#    #+#             */
/*   Updated: 2020/08/30 17:21:47 by tvernita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_showmatrix(char **arr, int x, int y)
{
	int i;
	int j;

	printf("show matrix %dx%d\n", x, y);
	i = 0;
	j = 0;
	while (j < y)
	{
		while (i < x)
		{
			ft_putchar(arr[j][i]);
			ft_putchar(' ');
			i++;
		}
		i = 0;
		ft_putchar('\n');
		j++;
	}
}
