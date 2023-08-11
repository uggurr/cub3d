#include "cub3d.h"

void	path_check(t_ident *ident)
{
	int	fd;
	int	fd2;
	int	fd3;
	int	fd4;

	fd = open(ident->no, O_RDONLY);
	fd2 = open(ident->so, O_RDONLY);
	fd3 = open(ident->we, O_RDONLY);
	fd4 = open(ident->ea, O_RDONLY);

	if (fd == -1 || fd2 == -1 || fd3 == -1 || fd4 == -1)
	{
		printf("ERROR! The specified file path in the map could not be found.\n");
		exit(0);
	}

}

void	get_identifier_path(t_ident *ident)
{
	int		i;
	char	**arg;

	i = 0;
	while (ident->full_identifier[i])
	{
		arg = ft_split(ident->full_identifier[i], ' ');
		if ((ft_strncmp(arg[0], "NO", ft_strlen("NO")) == 0))
			ident->no = arg[1];
		else if ((ft_strncmp(arg[0], "SO", ft_strlen("SO")) == 0))
			ident->so = arg[1];
		else if ((ft_strncmp(arg[0], "WE", ft_strlen("WE")) == 0))
			ident->we = arg[1];
		else if ((ft_strncmp(arg[0], "EA", ft_strlen("EA")) == 0))
			ident->ea = arg[1];
		else if ((ft_strncmp(arg[0], "F", ft_strlen("F")) == 0))
			ident->f = arg[1];
		else if ((ft_strncmp(arg[0], "C", ft_strlen("C")) == 0))
			ident->c = arg[1];
		i++;
	}
	path_check(ident);
}
