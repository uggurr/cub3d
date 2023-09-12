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

void routue_check(t_map *map)
{
	int i;

	i = 0;
	while(map->just_map[i])
	{
		if (map->just_map[i] == '\n')
		{
				printf("i:%d\n", i);
				printf("sd:%d\n", map->just_map[i]);
				printf("fı:%d\n", map->just_map[i - 1]);
				printf("fg:%d\n", map->just_map[i + 1]);
			if (map->just_map[i - 1] != 49 && (map->just_map[i + 1] != 49 || map->just_map[i + 1] != 9))
			{
				printf("i:%d\n", i);

				printf("eroorrrrr\n");
				exit(0);
			}
		}
		i++;
	}

}

void newline_check(t_map *map)
{
	int i;

	i = 0;
	while(map->just_map[i])
	{
		if (map->just_map[i] == '\n' && map->just_map[i + 1] == '\n')
		{
			printf("The map content cannot be separated by newline!\n");
			exit(0);
		}
		i++;
	}
	routue_check(map);
}
