#include <stdlib.h>
#include <stdio.h>

typedef struct		s_list
{
	struct s_list	*next;
	int				id;
} 					node;


node		*create_node(int data)
{
	node *p;
	
	p = (node *)malloc(sizeof(node));
	p->id = data;
	p->next = NULL;
	return (p);
}

void		push(node **p, int id)
{
	printf("add to front...\n");
	node	*copy_p;

	copy_p = create_node(id);
	copy_p->next = (*p); // <=> (*copy_p).next = *p
	*p = copy_p;
}

int					main(void)
{
	node	*p;
	// node	arr[4];
	p = NULL;
	// arr[0].id = 1;
	// arr[1].id = 2;
	// arr[2].id = 3;
	// arr[3].id = 4;
	// p = &arr[0];
	// arr[0].next = &arr[1];
	// arr[1].next = &arr[2];
	// arr[2].next = &arr[3];
	// arr[3].next = NULL;
	push(&p, 1);
	push(&p, 2);
	// push(&p, "to_front2");
	// push(&p, "to_front3");
	while (p)
	{
		printf("%d\n", (*p).id);
		p = p->next;
	}
}