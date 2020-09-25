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

char	**ft_add_variants(char **arr)
{
	arr[0] = "4123";
	arr[1] = "4132";
	arr[2] = "4213";
	arr[3] = "4231";
	arr[4] = "4312";
	arr[5] = "4321";
	arr[6] = "1423";
	arr[7] = "1432";
	return (arr);
}

char	**ft_variants(int rang)
{
	char **arr;
	arr = get_mem_for_char_arr(rang, ft_factorial(rang));
	arr = ft_add_variants(arr);
	arr[8] = "1243";
	arr[9] = "1234";
	arr[10] = "1342";
	arr[11] = "1324";
	arr[12] = "2413";
	arr[13] = "2431";
	arr[14] = "2143";
	arr[15] = "2134";
	arr[16] = "2341";
	arr[17] = "2314";
	arr[18] = "3412";
	arr[19] = "3421";
	arr[20] = "3142";
	arr[21] = "3124";
	arr[22] = "3241";
	arr[23] = "3214";
	return (arr);
}
