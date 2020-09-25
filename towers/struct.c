#include "ft.h"

t_list		*create_upper_node(int id)
{
	t_list *p;
	printf("upper node creating...\n");
	p = (t_list *)malloc(sizeof(t_list));
	p->id = id < N ? id : id - N;
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

void		shift(t_list **head, char **arr, int id)
{
	t_list	*new_node;
	t_list	*tmp;

	new_node = create_upper_node(id);
	if (*head == NULL)
		*head = new_node;
	else
	{
		tmp = *head;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}
int				depth_of(t_variety *head)
{
	// printf("depth of node...\n");
	t_variety	*tmp;
	int			i;

	tmp = head;
	i = 0;
	while(tmp != NULL)
	{
		i++;
		tmp = tmp->down;
	}
	return (i);
}

int			length_of(t_list *head)
{
	printf("size of rows...\n");
	t_list *tmp;
	int		i;

	tmp = head;
	i = 0;
	while(tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void		fill_arr(char **arr, char **generator)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < FACT)
	{
		while (i < N)
			arr[j][i] = generator[j][i++];
		i = 0;
		j++;
		
	}
	ft_showmatrix(arr, N, FACT);
	free_mem_char_arr(generator, FACT);
}

t_list		*create_up_struct(int rang)
{
	t_list	*p;
	t_list	*cp;
	int		i;
	char	**arr;

	p = NULL;
	printf("upper struct creating...\n");
	i = -1;
	while(++i < N * 2)
	{
		push_up(&p, i);	
	}
	cp = p;
	printf("size = %d\n", length_of(cp));
	while (cp)
	{
		// printf("check %d\n", *cp);
		printf("%d\n", cp->id);
		cp = cp->next;
	}
	printf("...get here\n");
	return (p);

}

t_list		*create_struct(char **views_arr)
{
	t_list	*p;
	t_list	*cp;
	int		i;
	char	**arr;
	int		j;

	p = create_up_struct(N);
	printf("struct creating...\n");
	ft_showmatrix(views_arr, 2, 8);
	i = N * 2;
	j = -1;
	cp = p;
	arr = ft_variants(N);
	ft_showmatrix(arr, N, ft_factorial(N));
	while(--i >= 0)
	{
		printf("NODE = %d\n", i);
		printf("checked by v1= %c v2= %c\n", views_arr[i][0], views_arr[i][1]);
		while (++j < ft_factorial(N))
		{
			if (check_views(views_arr[i][0], views_arr[i][1], arr[j]))
			{
				printf("%s\n", arr[j]);
			
				push_down(&cp, arr[j], cp->size);
				cp->size++;
			}
		}
		printf("depth = %d\n", depth_of(cp->down));	
		printf("size = %d\n", cp->size);	
		cp = cp->next;
		j = -1;
		printf("==============\n\n");
	}
	
	cp = p;
	//printf("size = %d\n", length_of(cp));
	while (cp)
	{
		// printf("check %d\n", *cp);
		printf("%d\n", cp->id);
		cp = cp->next;
	}
	free_mem_char_arr(arr, ft_factorial(N));
	printf("...check\n");
	return (p);
}
