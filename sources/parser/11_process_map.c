/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_process_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:45:04 by aternero          #+#    #+#             */
/*   Updated: 2025/11/13 20:15:37 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static t_dim	calculate_player_position(char **map)
{
	t_dim	dim;
	t_dim	index;

	index.y = -1;
	while (map[++index.y])
	{
		index.x = -1;
		while (map[index.y][++index.x])
		{
			if (is_position(map[index.y][index.x]))
			{
				dim.x = index.x;
				dim.y = index.y;
				return (dim);
			}
		}
	}
	dim.y = -1;
	dim.x = -1;
	return (dim);
}

static t_dim	calculate_map_dim(char **map)
{
	t_dim	dim;
	t_dim	temp;

	dim.x = 0;
	dim.y = 0;
	temp.y = -1;
	while (map[++temp.y])
	{
		temp.x = ft_strlen(map[temp.y]);
		if (dim.x < temp.x)
			dim.x = temp.x;
	}
	dim.y = temp.y;
	return (dim);
}

static t_map	*init_map(t_game *game)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		print_error(EMALLOC);
		return (free_game(game));
	}
	map->map = NULL;
	map->dim.x = 0;
	map->dim.y = 0;
	map->player.x = 0;
	map->player.y = 0;
	return (map);
}

int	process_map(t_game *game, t_file *start)
{
	if (!start)
		return (print_error(ENOMAP));
	game->map = init_map(game);
	game->map->map = extract_map(start);
	if (!game->map->map)
		return (FALSE);
	game->map->dim = calculate_map_dim(game->map->map);
	if (map_check(game) == FALSE)
		return (FALSE);
	game->map->player = calculate_player_position(game->map->map);
	if (game->map->player.y == -1 || game->map->player.x == -1)
		return (print_error(EPPO));
	return (TRUE);
}
