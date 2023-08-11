#include "cub3d.h"

void	ft_error(t_map *map)
{
    int	i;

    i = 0;

    while(map->map_file[i])
    {
        free(map->map_file[i]);
        i++;
    }
    free(map);
    printf("Error");
    exit(0);
}
