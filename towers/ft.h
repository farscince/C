#ifndef FT_H
# define FT_H
# define N 6

#include <unistd.h>
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
int			ft_strlen(char *str);
char		*ft_strcpy(char *dest, char *str);
void		swap(char *x, char *y);
void		ft_showmatrix(char **arr, int x, int y);
char		**ft_variants(int rang);
t_list		*create_struct(char **views_arr, char **arr, int rang);
bool		is_valid_map(t_list **p);
bool		check_views(char v1, char v2, char *array, int rang);
char		**get_mem_for_char_arr(int x, int y);
void		free_mem_char_arr(char **arr, int y);
int			ft_factorial(int n);
void		struct_foreach(t_list **head, int (*f)(t_list **));
void		pop_node(t_list **p);
int			scan_struct(t_list **head);
int			check_struct_depths(t_list **p);

int			length_of(t_list *head);
#endif
