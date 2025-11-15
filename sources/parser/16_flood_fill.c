/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:06:26 by aternero          #+#    #+#             */
/*   Updated: 2025/11/13 20:15:21 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

/* static int	valid_surroundings(char c)
{
	if (c == '1' || c == '0' || is_position(c) == TRUE)
		return (TRUE);
	return (print_error(EWALLS));
} */

static int	fill_check(char **map, t_dim dim, t_dim init)
{
	if (!map)
		return (TRUE);
	if (init.x < 0 || init.y < 0 || init.y >= dim.y
		|| init.x >= (int)ft_strlen(map[init.y])
		|| is_space(map[init.y][init.x]) == TRUE)
		return (print_error(EWALLS));
	if (map[init.y][init.x] == '1' || map[init.y][init.x] == 'D')
		return (TRUE);
	if (map[init.y][init.x] == '0' || is_position(map[init.y][init.x]) == TRUE)
	{
		map[init.y][init.x] = 'D';
		if (fill_check(map, dim, (t_dim){init.x - 1, init.y}) == FALSE
			|| fill_check(map, dim, (t_dim){init.x + 1, init.y}) == FALSE
			|| fill_check(map, dim, (t_dim){init.x, init.y - 1}) == FALSE
			|| fill_check(map, dim, (t_dim){init.x, init.y + 1}) == FALSE)
			return (FALSE);
	}
	return (TRUE);
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
			{
				if (fill_check(map, dim, index) == FALSE)
					return (FALSE);
			}
		}
	}
	array_free(map);
	return (TRUE);
}
