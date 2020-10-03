#include "ft.h"

t_variety		*del_node(t_list **p, t_variety *del_node)
{
	t_variety	*prev;

	prev = (*p)->down;
	if (prev->id == del_node->id)
	{
		(*p)->down = del_node->down;
		free(del_node);
		(*p)->size--;
		return ((*p)->down);
	}
	while (prev)
	{
		if (prev->down->id == del_node->id)
			break ;
		prev = prev->down;
	}
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

/*
** put the following string after 'pc = (is_in == False) ?' to show
** all deleted vars:
** if (is_in == False)
** printf("del: %s in %d (is raw %d)\n", pc->var, (*c)->id, (*c)->is_row);
*/

int				ft_check_line_crosses(t_list **c, t_list **r)
{
	t_variety	*pr;
	t_variety	*pc;
	bool		is_in;
	int			counter;

	pc = (*c)->down;
	pr = (*r)->down;
	counter = 0;
	while (pc)
	{
		is_in = False;
		while (pr)
		{
			(pr->var[(*c)->id] == pc->var[(*r)->id]) ? is_in = True : 0;
			pr = pr->down;
		}
		pc = (is_in == False) ? del_node(c, pc) : pc->down;
		(is_in == False) ? counter++ : 0;
		pr = (*r)->down;
	}
	return (counter);
}

/*
**struct_foreach(p, &scan_struct);
*/

int				ft_filt_struct_self(t_list **p)
{
	int			counter;
	t_list		*cp;
	t_list		*rp;

	counter = 0;
	cp = *p;
	rp = *p;
	while (rp)
	{
		if (rp->is_row)
			while (cp)
			{
				if (!cp->is_row)
				{
					counter += ft_check_line_crosses(&cp, &rp);
					counter += ft_check_line_crosses(&rp, &cp);
				}
				cp = cp->next;
			}
		cp = *p;
		rp = rp->next;
	}
	return (counter);
}

bool			is_valid_map(t_list **p)
{
	t_list		*cp;
	int			is_changed;
	int			max_depth;

	is_changed = 1;
	while (is_changed - ft_filt_struct_self(p))
		is_changed = ft_filt_struct_self(p);
	max_depth = check_struct_depths(p);
	if (max_depth > 1)
	{
		cp = *p;
		while (cp)
		{
			if (cp->size == max_depth)
			{
				while (cp->size != 1)
					pop_node(&cp);
				is_valid_map(p);
				break ;
			}
			cp = cp->next;
		}
	}
	return (max_depth < 0) ? False : True;
}
