#include "cub3d.h"

int	get_line_size(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_file[i])
		i++;
	return (i);
}

char	*file_extraction(t_map *map)
{
	char	*first_line;
	char	*last_line;
	int		size;
	char	*map_new;

	map->map_line_size = get_line_size(map) - 1;
	first_line = ft_strnstr(map->every_line, map->map_file[5],
			ft_strlen(map->every_line));
	first_line += ft_strlen(map->map_file[5]);
	last_line = ft_strnstr(first_line, map->map_file[map->map_line_size],
			ft_strlen(first_line));
	size = last_line - first_line
		+ ft_strlen(map->map_file[map->map_line_size]);
	map_new = malloc(sizeof(char) * size + 1);
	ft_strlcpy(map_new, first_line, size);
	map_new[size] = '\0';
	return (map_new);
}
