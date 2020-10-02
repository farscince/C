/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_views.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgurn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 15:06:10 by pgurn             #+#    #+#             */
/*   Updated: 2020/09/01 12:20:29 by yeschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft.h"

bool		check_views(char v1, char v2, char *array, int rang)
{
	int i;
	int k;
	int k_rev;
	int max;
	int max_rev;

	i = 0;
	k = 1;
	k_rev = 1;
	max = array[0];
	max_rev = array[rang - 1];
	while (i++ < rang)
	{
		if (array[i] > max)
		{
			max = array[i];
			k++;
		}
		if (array[rang - 1 - i] > max_rev)
		{
			max_rev = array[rang - 1 - i];
			k_rev++;
		}
	}
	return (((k == (v1 - '0')) && (k_rev == (v2 - '0'))) ? True : False);
}
