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

int			is_valid_str(char *str)
{
	int		i;

	i = 0;
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
	return (1);
}

char		**split_views(int x, int y, char *str)
{
	char	**arr;
	int		i;

	i = 0;
	arr = get_mem_for_char_arr(x, y);
	while (str[i])
	{
		if (i % 2 == 0)
		{
			(i < N * 2) ? arr[i / 2][0] = str[i] : 0;
			(N * 2 <= i && i < N * 4) ? arr[i / 2 - N][1] = str[i] : 0;
			(N * 4 <= i && i < N * 6) ? arr[i / 2 - N][0] = str[i] : 0;
			(N * 6 <= i) ? arr[i / 2 - N * 2][1] = str[i] : 0;
		}
		i++;
	}
	return (arr);
}

int			clear_struct(t_list **p)
{
	t_list	*cp;

	cp = *p;
	if (cp->next == NULL)
	{
		if (cp->is_row)
			printf("%s\n", cp->down->var);
		while (cp->size)
			pop_node(p);
		free(p);
		*p = NULL;
		return (-1);
	}
	if (cp->next->next == NULL)
	{
		if (cp->next->is_row)
			printf("%s\n", cp->next->down->var);
		while (cp->next->size)
			pop_node(&(cp->next));
		free(cp->next);
		cp->next = NULL;
		return (-1);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	char	**views_arr;
	t_list	*p;
	int		i;

	if (argc == 2 && (is_valid_str(argv[1]) == 1))
	{
		views_arr = split_views(2, N * 2, argv[1]);
		ft_showmatrix(views_arr, 2, 8);
		p = create_struct(views_arr);
		if (check_struct_depths(&p) < 0)
		{
			ft_putstr("Error");
			return (-1);
		}
		if (is_valid_map(&p))
		{
			i = N * 2;
			while (--i >= 0)
				struct_foreach(&p, &clear_struct);
			return (0);
		}
	}
	ft_putstr("Error");
}
