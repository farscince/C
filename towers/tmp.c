#include <stdlib.h>
#include <stdio.h>
#include "ft.h"

// typedef struct		s_list
// {
// 	struct s_list	*next;
// 	int				id;
// } 					node;



// node		*create_node(int data)
// {
// 	node *p;
	
// 	p = (node *)malloc(sizeof(node));
// 	p->id = data;
// 	p->next = NULL;
// 	return (p);
// }

t_list		*create_upper_node(int id)
{
	t_list *p;
	printf("upper node creating...\n");
	p = (t_list *)malloc(sizeof(t_list));
	p->id = id;
	p->is_row = id < N ? False : True;
	p->next = NULL;
	p->down = NULL;
	p->size = 0;
	return (p);
}

t_variety	*create_lower_node(char *data)
{
	t_variety *p;
	// printf("lower node creating...\n");
	p = (t_variety *)malloc(sizeof(t_variety));
	p->down = NULL;
	p->var = data;
	return (p);
}

// void		push(node **p, int id)
// {
// 	printf("add to front...\n");
// 	node	*copy_p;

// 	copy_p = create_node(id);
// 	copy_p->next = (*p); // <=> (*copy_p).next = *p
// 	*p = copy_p;
// }

void		push_up(t_list **p, int id)
{
	printf("add to front...\n");
	t_list	*copy_p;

	copy_p = create_upper_node(id);
	copy_p->next = (*p); // <=> (*copy_p).next = *p
	*p = copy_p;
}

void			push_down(t_list **p, char *data, int id)
{
	// printf("add node down with data %s...\n", data);
	t_variety	*low_node;
	low_node = create_lower_node(data);
	low_node->down = (*p)->down; // <=> (*copy_p).next = *p
	low_node->id = id;
	(*p)->down = low_node;
}

void			scan_struct(t_variety *head)
{
	t_variety	*tmp;
	
	tmp = head;
	while (tmp)
	{
		printf("%d %s\n", tmp->id, tmp->var);
		tmp = tmp->down;
	}
}


t_variety		*shift_node(t_list **p, t_variety *del_node)
{
	// int			i;
	t_variety	*prev;
	// t_variety	*tmp;

	// i = 0;
	prev = (*p)->down;
	if (prev->id == del_node->id)
	{
		(*p)->down = del_node->down;
		free(del_node);
		scan_struct((*p)->down);
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
	// scan_struct((*p)->down);
	
	return (prev->down);
}


int					main(void)
{
	t_list	*rp;
	t_list	*cp;
	t_variety	*r_anchor;
	t_variety	*c_anchor;
	bool		is_matched;

	cp = create_upper_node(1);
	rp = create_upper_node(2);
	push_down(&cp, "aaa", 0);
	push_down(&cp, "bbb", 1);
	push_down(&cp, "ccc", 2);
	push_down(&cp, "ddd", 3);

	push_down(&rp, "aa", 0);
	push_down(&rp, "bb", 2);
	push_down(&rp, "cc", 4);
	push_down(&rp, "dd", 5);
	// printf("del %d, %s\n", cp->down->down->id, cp->down->down->var);
	c_anchor = cp->down;
	r_anchor = rp->down;
	scan_struct(c_anchor);
	scan_struct(r_anchor);
	while (c_anchor)
	{
		is_matched = False;
		while (r_anchor)
		{
			printf("c_id = %d, r_id = %d\n", c_anchor->id, r_anchor->id);
			if (r_anchor->id == c_anchor->id)
				is_matched = True;
			r_anchor = r_anchor->down;
		}
		if (is_matched == False)
		{
			printf("del %d %s\n", c_anchor->id, c_anchor->var);
			c_anchor = shift_node(&cp, c_anchor);
			// printf(c_anchor->id);
			// scan_struct(c_anchor);
		}
		else
			c_anchor = c_anchor->down;
		r_anchor = rp->down;
	}
	printf("totaly:\n");
	scan_struct(cp->down);
	scan_struct(rp->down);
	// arr[0].id = 1;
	// arr[1].id = 2;
	// arr[2].id = 3;
	// arr[3].id = 4;
	// p = &arr[0];
	// arr[0].next = &arr[1];
	// arr[1].next = &arr[2];
	// arr[2].next = &arr[3];
	// arr[3].next = NULL;
	// push(&p, 1);
	// push(&p, 2);
	// push(&p, "to_front2");
	// push(&p, "to_front3");
	while (cp->down)
	{
		printf("%d\n", cp->down->id);
		cp->down = cp->down->down;
	}
}