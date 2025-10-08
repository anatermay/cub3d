/* *****************************static int	fill_check(char **map, t_dim dim, t_dim init)
{
	if (map)
	{
		if (init.x < 0 || init.y < 0 || init.y >= dim.y
			|| (int)ft_strlen(map[init.y]) <= init.x)
			return (print_error(EWALLS));
		if (is_space(map[init.y][init.x]) == TRUE)
			return (print_error(EWALLS));
		if (map[init.y][init.x] == '1')
			return (TRUE);
		if (map[init.y][init.x] == 'D')
			return (TRUE);
		if (map[init.y][init.x] == '0' || is_position(map[init.y][init.x]) == TRUE)
		{
			map[init.y][init.x] = 'D';
			if (fill_check(map, dim, (t_dim){init.x - 1, init.y}) == FALSE
				|| fill_check(map, dim, (t_dim){init.x + 1, init.y}) == FALSE
				|| fill_check(map, dim, (t_dim){init.x, init.y - 1}) == FALSE
				|| fill_check(map, dim, (t_dim){init.x, init.y + 1}) == FALSE)
				return (print_error(EWALLS));
		}
	}
	return (TRUE);
}************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   17_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:42:36 by aternero          #+#    #+#             */
/*   Updated: 2025/10/08 19:49:07 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static int	valid_surroundings(char c)
{
	if (c == '1')
		return (TRUE);
	else if (is_space(c) == TRUE)
		return (print_error(EWALLS));
	else if (c == '0' || is_position(c))
		return (TRUE);
	else if (c != '0' && c != '1' && is_space(c) == FALSE
		&& is_position(c) == FALSE)
		return (print_error(EWALLS));
	return (print_error(EWALLS));
}

static int	fill_check(char **map, t_dim dim, t_dim init)
{
	if (map)
	{
		if (init.x < 0 || init.y < 0 || init.y >= dim.y
			|| (int)ft_strlen(map[init.y]) <= init.x
			|| is_space(map[init.y][init.x]) == TRUE
			|| map[init.y][init.x] == '1')
			return (TRUE);
		if (map[init.y][init.x] == '0' || is_position(map[init.y][init.x]) == TRUE)
		{
			if (valid_surroundings(map[dim.y + 1][dim.x]) == FALSE
			|| valid_surroundings(map[dim.y - 1][dim.x]) == FALSE
			|| valid_surroundings(map[dim.y][dim.x + 1]) == FALSE
			|| valid_surroundings(map[dim.y][dim.x - 1]) == FALSE)
				return (print_error("line 60: HI"));
			map[init.y][init.x] = 'D';
		}
		if (fill_check(map, dim, (t_dim){init.x - 1, init.y}) == FALSE
			|| fill_check(map, dim, (t_dim){init.x + 1, init.y}) == FALSE
			|| fill_check(map, dim, (t_dim){init.x, init.y - 1}) == FALSE
			|| fill_check(map, dim, (t_dim){init.x, init.y + 1}) == FALSE)
			return (print_error("line 73: HI"));
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
