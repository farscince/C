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

typedef struct 		s_list
{
	struct s_list	*next;
	struct s_list	*down;
	char			**var_list;
	char			*data;
	int				id;
	int				size;
}					t_list;

typedef struct		s_var
{
	struct s_var	*down;
	char			*var;
}					t_variety;


void		ft_putstr(char *str);
void		ft_showmatrix(char **arr, int x, int y);
bool		check_views(int v1, int v2, char *arr);
char		**ft_variants(char **arr);
t_list		*create_struct(char **views_arr);
int			is_valid_map(t_list **p, char **res_arr);
char		**get_mem_for_char_arr(int x, int y);
void		free_mem_char_arr(char **arr, int y);

#endif
