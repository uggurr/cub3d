#include "cub3d.h"

int	cub_check(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (str[len] != 'b' || str[len - 1] != 'u' || str[len - 2] != 'c'
		|| str[len - 3] != '.')
		return (0);
	return (1);
}

void	error_map(t_map *map)
{
	free(map);
	printf("No map\n");
	printf("Error");
	exit(0);
}
