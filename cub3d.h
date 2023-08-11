#ifndef CUB3D
# define CUB3D
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

typedef struct t_ident
{
	char			**full_identifier;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*f;
	char			*c;
}					t_ident;

typedef struct s_map
{
	char			*every_line;
	char			**map_file;
	t_ident			*identifier;
}				t_map;

int cub_check(char *str);
void	error_map(t_map *map);
void	ft_error(t_map *map);
void	identifier_check(char **map_file, t_ident *ident);
void	get_identifier_path(t_ident *ident);

#endif
