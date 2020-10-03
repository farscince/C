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
		if ((i % 2 == 0) && (str[i] < 49 || str[i] > (49 + N)))
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

void		ft_putstr_space(char *str)
{
	int		j;

	j = 0;
	while (str[j])
	{
		write(1, &str[j], 1);
		str[j + 1] ? write(1, " ", 1) : 0;
		j++;
	}
	write(1, "\n", 1);
}

int			clear_struct(t_list **p)
{
	t_list	*cp;

	cp = *p;
	if (cp->next == NULL)
	{
		if (cp->is_row)
			ft_putstr_space(cp->down->var);
		while (cp->size)
			pop_node(p);
		free(p);
		*p = NULL;
		return (-1);
	}
	if (cp->next->next == NULL)
	{
		if (cp->next->is_row)
			ft_putstr_space(cp->next->down->var);
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
	t_list	*p;
	int		i;
	char	**views_arr;
	char	**permutations;
	bool	is_done;

	is_done = False;
	if (argc == 2 && (is_valid_str(argv[1]) == 1))
	{
		views_arr = split_views(2, N * 2, argv[1]);
		permutations = ft_variants(N);
		p = create_struct(views_arr, permutations, N);
		if (is_valid_map(&p))
		{
			i = N * 2;
			while (--i >= 0)
				struct_foreach(&p, &clear_struct);
			is_done = True;
		}
		free_mem_char_arr(views_arr, N * 2);
		free_mem_char_arr(permutations, ft_factorial(N));
	}
	!is_done ? ft_putstr("Error") : 0;
}
