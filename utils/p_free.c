#include "../cub3d.h"

void	free_map_structure(t_map *map)
{
	if (map->path)
		free(path);
	if (map->map)
		array_free(map);
	if (map.dim)
		free(map->dim);
	if (map.north.texture)
		free_compass_structure(map.north);
	if (map.south.texture)
		free_compass_structure(map.south);
	if (map.east.texture)
		free_compass_structure(map.east);
	if (map.weast.texture)
		free_compass_structure(map.weast);
	if (map.floor)
		free_vertical_structure(map.floor);
	if (map.ceiling)
		free_vertical_structure(map.ceiling);
	free(map);
}

void	free_structures(t_game *game)
{
	if (!game)
		return;
	if (game->map)
		free_map_structure(game->map);
	if (game->player)
		free_player_structure(game->player);
	if (game)
		free(game);
}

void	array_free(char **array)
{
	int	index;

	if (!(*array))
		return ;
	index = 0;
	while (array[index])
	{
		free(array[index]);
		array[index] == NULL;
		index++;
	}
	free(array);
}
