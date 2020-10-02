#include "ft.h"

t_list			*create_upper_node(int id)
{
	t_list		*p;

	p = (t_list *)malloc(sizeof(t_list));
	p->id = id < N ? id : id - N;
	p->is_row = id < N ? False : True;
	p->next = NULL;
	p->down = NULL;
	p->size = 0;
	return (p);
}

t_variety		*create_lower_node(char *data)
{
	t_variety	*p;

	p = (t_variety *)malloc(sizeof(t_variety));
	p->down = NULL;
	p->var = data;
	return (p);
}

void			push_up(t_list **p, int id)
{
	t_list		*copy_p;

	copy_p = create_upper_node(id);
	copy_p->next = (*p);
	*p = copy_p;
}

void			push_down(t_list **p, char *data, int id)
{
	t_variety	*low_node;

	printf("data %s\n", data);
	low_node = create_lower_node(data);
	low_node->down = (*p)->down;
	low_node->id = id;
	(*p)->down = low_node;
}

t_list			*create_struct(char **views_arr, char **arr, int rang)
{
	t_list		*p;
	t_list		*cp;
	int			i;
	int			j;

	p = NULL;
	i = -1;
	while (++i < rang * 2)
		push_up(&p, i);
	i = rang * 2;
	j = -1;
	cp = p;
	while (--i >= 0)
	{
		while (++j < ft_factorial(rang))
			if (check_views(views_arr[i][0], views_arr[i][1], arr[j], rang))
				push_down(&cp, arr[j], cp->size++);
		cp = cp->next;
		j = -1;
	}
	return (p);
}
