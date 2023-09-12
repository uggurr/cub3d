#include "cub3d.h"

char	*get_all_map(char *str)
{
	char	*map;
	char	*get_line;
	int		i;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		printf("file not found");
		close(fd);
		exit(0);
	}
	map = NULL;
	get_line = NULL;
	i = -1;
	while (get_line != NULL || ++i == 0)
	{
		get_line = get_next_line(fd);
		if (get_line != NULL)
			map = ft_gnl_strjoin(map, get_line);
		free(get_line);
	}
	return (map);
}

void	create_mapfile(char **av, t_map *map)
{
	map->every_line = get_all_map(av[1]);
	if (map->every_line == NULL)
		error_map(map);
	map->map_file = ft_split(map->every_line, '\n');
	map->just_map = file_extraction(map);
	map->just_map = ft_strtrim(map->just_map, "\n");
	newline_check(map);
}

int	main(int ag, char **av)
{
	t_map	*map;
	t_ident	*ident;

	if (ag == 2 && cub_check(av[1]))
	{
		map = malloc(sizeof(t_map));
		ident = malloc(sizeof(t_ident));
		create_mapfile(av, map);
		identifier_check(map->map_file, ident);
		get_identifier_path(ident);
		//Silinecek
		//printf("%c", map->every_line[94]);
		//int i = 0;
		printf("%s", map->just_map);
		//int i = 6;
		//while (map->map_file[i] != NULL)
		//{
		//	printf("%s\n", map->map_file[i]);
		//	i++;
		//}
	}
	else
	{
		printf("Something is wrong!\n");
		printf("Multiple arguments cannot be entered or the file path is incorrect\n");
	}
}
