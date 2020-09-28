#include "ft.h"

int				scan_struct(t_list **head)
{
	t_variety	*tmp;
	char		*name;

	name = (*head)->is_row ? "row" : "col";
	printf("%s_%d size: %d\n", name, (*head)->id, (*head)->size);
	tmp = (*head)->down;
	while (tmp)
	{
		printf("%d %s\n", tmp->id, tmp->var);
		tmp = tmp->down;
	}
	printf("==============\n\n");
	return (1);
}

void			struct_foreach(t_list **head, int (*f)(t_list **))
{
	t_list		*tmp;
	int			stop_flag;

	tmp = *head;
	stop_flag = 0;
	while (tmp)
	{
		stop_flag = (*f)(&tmp);
		if (stop_flag < 0)
			return ;
		tmp = tmp->next;
	}
}

int				check_struct_depths(t_list **p)
{
	t_list		*cp;
	int			max_depth;

	max_depth = 1;
	cp = *p;
	while (cp)
	{
		if (cp->size == 0)
			return (-1);
		if (cp->size > max_depth)
			max_depth = cp->size;
		cp = cp->next;
	}
	printf("max is: %d\n", max_depth);
	return (max_depth);
}

int				depth_of(t_variety *head)
{
	t_variety	*tmp;
	int			i;

	tmp = head;
	i = 0;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->down;
	}
	return (i);
}

int				length_of(t_list *head)
{
	t_list		*tmp;
	int			i;

	tmp = head;
	i = 0;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
