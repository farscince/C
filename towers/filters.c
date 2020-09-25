#include "ft.h"

int			check_struct_depths(t_list **p)
{
	t_list	*cp;
	int		max_depth;

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

void			scan_deep_struct(t_variety *head)
{
	t_variety	*tmp;
	
	tmp = head;
	while (tmp)
	{
		printf("%d %s\n", tmp->id, tmp->var);
		tmp = tmp->down;
	}
}

void			scan_struct(t_list *head)
{
	t_list	*tmp;
	char	*name;

	tmp = head;
	while (tmp)
	{
		name = tmp->is_row? "row" : "col";
		printf("%s_%d size: %d\n", name, tmp->id, tmp->size);
		scan_deep_struct(tmp->down);
		printf("==============\n\n");
		tmp = tmp->next;
	}
}

t_variety		*shift_node(t_list **p, t_variety *del_node)
{
	t_variety	*prev;

	prev = (*p)->down;
	if (prev->id == del_node->id)
	{
		(*p)->down = del_node->down;
		free(del_node);
		scan_deep_struct((*p)->down);
		(*p)->size--;
		return ((*p)->down);
	}
    while (prev)
	{
		if (prev->down->id == del_node->id)
		{
			printf("%d -> %s ____ %d %s\n", prev->id, prev->var, del_node->id, del_node->var);
			printf("%s\n", prev->var);
			break;
		}
        prev = prev->down;
    }
	printf("del %s\n", del_node->var);
	prev->down = del_node->down;
	free(del_node);
	(*p)->size--;
	return (prev->down);
}

void			pop_node(t_list **p)
{
	t_variety	*tmp;

	tmp = (*p)->down;
	if (tmp != NULL)
	{
		(*p)->down = tmp->down;
		free(tmp);
		(*p)->size--;
	}
}


int				ft_check_line_crosses(t_list **col, t_list **row)
{
	t_variety	*r_anchor;
	t_variety	*c_anchor;
	bool		is_matched;
	int			counter;

	printf("cross lines c = %d, r = %d\n", (*col)->id, (*row)->id);
	c_anchor = (*col)->down;
	r_anchor = (*row)->down;
	counter = 0;
	printf("%c %c %c %c\n", c_anchor->var[0], c_anchor->var[1], c_anchor->var[2], c_anchor->var[3]);
	while (c_anchor)
	{
		is_matched = False;
		while (r_anchor)
		{
			// printf("compare: %d and %d\n", (*col)->id, (*row)->id);
			// printf("symbs: %c and %c\n", c_anchor->var[(*row)->id - N], r_anchor->var[(*col)->id]);
			if (r_anchor->var[(*col)->id] == c_anchor->var[(*row)->id])
			{
				is_matched = True;
			}
			r_anchor = r_anchor->down;
		}
		if (is_matched == False)
		{
			printf("exclude line: %s\n", c_anchor->var);
			c_anchor = shift_node(col, c_anchor);
			counter++;
		}
		else
			c_anchor = c_anchor->down;
		r_anchor = (*row)->down;
		// ft_check_line_crosses(row, col);
	}
	return (counter);// + ft_check_line_crosses(row, col));
	// r_anchor = r_anchor->down;
	// c_anchor = c_anchor->down;

}

void			struct_foreach(t_list **head, int (*f)(t_list **))
{
	t_list		*tmp;
	int			stop_flag;
	// printf("iterator\n");
	tmp = *head;
	stop_flag = 0;
	while (tmp)
	{
		stop_flag = (*f)(&tmp);
		if (stop_flag < 0)
			return ;
		tmp = tmp->next;
	}
	// printf("iterator1111\n");
}


int				ft_filt_struct_self(t_list **p)
{
	int			counter;
	t_list		*cp;
	t_list		*rp;

	counter = 0;
	cp = *p;
	rp = *p;
	scan_struct(*p);
	while (rp)
	{
		if (rp->is_row)
			while (cp)
			{
				// printf("check %d\n", *cp);
				if (!cp->is_row)
				{
					counter += ft_check_line_crosses(&cp, &rp);
					counter += ft_check_line_crosses(&rp, &cp);
				}
					// ft_check_line_crosses(&rp, &cp);
				cp = cp->next;
			}
		cp = *p;
		rp = rp->next;
	}
	scan_struct(*p);
	printf("\n\nround finished. Changes: %d\n\n\n", counter);
	return (0);
}

bool		is_valid_map(t_list **p)
{
	t_list	*cp;
	int		is_changed;
	int		max_depth;

	is_changed = 1;
	if (check_struct_depths(p) < 0)
		return (False);
	cp = *p;
	while (is_changed - ft_filt_struct_self(p))
		is_changed = ft_filt_struct_self(p);
	max_depth = check_struct_depths(p);
	if (max_depth < 0)
	{
		printf("0-size node detected...\n");
		return (False);
	}
	else if (max_depth == 1)
		return (True);
	else if (max_depth > 1)
	{
		cp = *p;
		while (cp)
		{
			if (cp->size == max_depth)
			{
				while(cp->size != 1)
				{
					pop_node(&cp);
					printf("size is %d\n", cp->size);
				}
				is_valid_map(p);
				break ;
			}
			cp = cp->next;
		}
	}
}