#include "ft.h"


t_list		*create_node(char **arr, int id)
{
	t_list *p;
	printf("node creating...\n");
	p = (t_list *)malloc(sizeof(t_list));
	p->var_list = arr;
	p->id = id;
	p->next = NULL;
	return (p);
}

void		push(t_list **p, char **arr, int id)
{
	printf("add to front...\n");
	t_list	*copy_p;

	copy_p = create_node(arr, id);
	copy_p->next = (*p); // <=> (*copy_p).next = *p
	*p = copy_p;
}

void		shift(t_list **head, char **arr, int id)
{
	t_list	*new_node;
	t_list	*tmp;

	new_node = create_node(arr, id);
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

int			length_of(t_list *head)
{
	printf("size of...\n");
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

t_list		*create_struct(char **views_arr)
{
	t_list	*p;
	t_list	*cp;
	int		i;
	char	**arr;

	p = NULL;
	printf("struct creating...\n");
	ft_showmatrix(views_arr, 2, 8);
	i = 0;
	while(i < N * 2)
	{
		// arr = get_mem_for_char_arr(N, FACT);
		// fill_arr(arr, generator(N))
		push(&p, arr, i);
		i++;
	}
	cp = p;
	//printf("size = %d\n", length_of(cp));
	while (cp)
	{
		// printf("check %d\n", *cp);
		printf("%d\n", cp->id);
		cp = cp->next;
	}
	printf("...get here\n");
	return (p);
}


// t_list		*create_node(char *data)
// {
// 	t_list *p;
	
// 	p = (t_list *)malloc(sizeof(t_list));
// 	p->data = data;
// 	p->next = 0;
// 	return (p);
// }

// void		push(t_list **p, char *data)
// {
// 	t_list	*copy_p;

// 	copy_p = create_node(data);
// 	copy_p->next = (*p); // <=> (*copy_p).next = *p
// 	*p = copy_p;
// }

// t_list		*create_struct(char **views_arr)
// {
// 	views_arr = views_arr;

// 	t_list	*p;
// 	t_list	arr[2];
	
// 	push(&p, "to_front1");
// 	push(&p, "to_front2");
// 	push(&p, "to_front3");
// 	while (p)
// 	{
// 		printf("%s\n", p->data);
// 		p = p->next;
// 	}
// 	return (p);
	
// }