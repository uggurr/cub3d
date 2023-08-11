#include "cub3d.h"

void	name_check(char **identifier)
{
	int		i;
	int		j;
	char	**name;

	i = 0;
	while (i < 6 && identifier[i])
	{
		name = ft_split(identifier[i], ' ');
		j = i + 1;
		while (identifier[j] && identifier[i])
		{
			if (ft_strncmp(name[0], identifier[j], ft_strlen(name[0])) == 0)
			{
				printf("'%s' Type Identifiers Cannot Have The Same Name!\n", identifier[j]);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	identifier_check(char **map_file, t_ident *ident)
{
	int	i;

	i = -1;
	ident->full_identifier = malloc(sizeof(char *) * 7);
	while (++i < 6)
	{
		if ((ft_strncmp(map_file[i], "NO", ft_strlen("NO")) == 0) || (ft_strncmp(map_file[i], "SO", ft_strlen("SO")) == 0)
			|| (ft_strncmp(map_file[i], "WE", ft_strlen("WE")) == 0) || (ft_strncmp(map_file[i], "EA", ft_strlen("EA")) == 0)
			|| (ft_strncmp(map_file[i], "F", ft_strlen("F")) == 0) || (ft_strncmp(map_file[i], "C", ft_strlen("C")) == 0))
		{
			ident->full_identifier[i] = ft_strdup(map_file[i]);
		}
		else
		{
			printf("'%s' Line Is Wrong! Check the identifier name or path\n", map_file[i]);
			exit(0);
		}
	}
	ident->full_identifier[i] = NULL;
	name_check(ident->full_identifier);
}
