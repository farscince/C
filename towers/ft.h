#ifndef FT_H
# define FT_H
# define N 4
# define FACT 24

#include <stdio.h>
#include <stdlib.h>

typedef enum e_bool
{
	False,
	True
}			bool;

typedef struct		s_var
{
	struct s_var	*down;
	char			*var;
	int				id;
}					t_variety;

typedef struct 		s_list
{
	struct s_list	*next;
	t_variety		*down;
	bool			is_row;
	int				id;
	int				size;
}					t_list;

void		ft_putstr(char *str);
void		ft_showmatrix(char **arr, int x, int y);
char		**ft_variants(int rang);
t_list		*create_struct(char **views_arr);
bool		is_valid_map(t_list **p);
bool		check_views(char v1, char v2, char *array);
char		**get_mem_for_char_arr(int x, int y);
void		free_mem_char_arr(char **arr, int y);
int			ft_factorial(int n);
void		struct_foreach(t_list **head, int (*f)(t_list **));
void		pop_node(t_list **p);
int			length_of(t_list *head);

#endif
