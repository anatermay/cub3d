/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   17_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:42:36 by aternero          #+#    #+#             */
/*   Updated: 2025/09/18 20:09:44 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static int	is_all_filled(char **map)
{
	t_dim	dim;

	dim.y = -1;
	while (map[++dim.y])
	{
		dim.x = -1;
		while (map[dim.y][++dim.x])
		{
			if (map[dim.y][dim.x] == '0'
				|| is_position(map[dim.y][dim.x]) == TRUE)
				return (print_error(EWALLS));
		}
	}
	return (FALSE);
}

static char	**fill_check(char **map, t_dim table, t_dim init)
{
	if (init.x < 0 || init.x >= table.x || init.y < 0 || init.y >= table.y
		|| map[init.y][init.x] == '1' || map[init.y][init.x] == 'D')
		return (map);
	if (map[init.y][init.x] == '0' || is_position(map[init.y][init.x]) == TRUE)
		map[init.y][init.x] = 'D';
	map = fill_check(map, table, (t_dim){init.x - 1, init.y});
	map = fill_check(map, table, (t_dim){init.x + 1, init.y});
	map = fill_check(map, table, (t_dim){init.x, init.y - 1});
	map = fill_check(map, table, (t_dim){init.x, init.y + 1});
	return (map);
}

int	re_recheck(char **map, t_dim dim)
{
	t_dim	index;

	index.y = -1;
	while (map[++index.y])
	{
		index.x = -1;
		while (map[index.y][++index.x])
		{
			if (map[index.y][index.x] == '0'
				|| is_position(map[index.y][index.x]) == TRUE)
				map = fill_check(map, dim, index);
		}
	}
	if (is_all_filled(map) == FALSE)
	{
		array_free(map);
		return (print_error(EWALLS));
	}
	array_free(map);
	return (TRUE);
}
