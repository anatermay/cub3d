/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16_validation_walls.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 18:48:47 by aternero          #+#    #+#             */
/*   Updated: 2025/09/23 19:18:47 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static int	recheck_walls(char **map)
{
	t_dim	dim;

	dim.y = -1;
	while (map[++dim.y])
	{
		if (first_row(map, dim.y) == TRUE || last_row(map, dim.y) == TRUE)
		{
			if (valid_special_row(map[dim.y]) == FALSE)
				return (print_error(EWALLS));
		}
		else
		{
			dim.x = -1;
			while (map[dim.y][++dim.x])
			{
				if (map[dim.y][dim.x] != '1'
					&& (first_column(map[dim.y], dim.x) == TRUE
						|| last_column(map[dim.y], dim.x) == TRUE))
					return (print_error(EWALLS));
			}
		}
	}
	return (TRUE);
}

static int	valid_char(char c)
{
	if (c != '0' && c != '1' && is_space(c) == FALSE
		&& is_position(c) == FALSE)
		return (print_error(EMCHR));
	return (TRUE);
}

static int	valid_surroundings(char c)
{
	if (c == '1' || c == '0' || is_position(c))
		return (TRUE);
	else if (is_space(c) == TRUE || valid_char(c) == FALSE)
		return (print_error(EWALLS));
	return (print_error(EWALLS));
}

static int	check_walls(char **map, t_dim dim)
{
	if (!map[dim.y + 1][dim.x] || !map[dim.y - 1][dim.x]
		|| !map[dim.y][dim.x + 1] || !map[dim.y][dim.x - 1])
		return (print_error(EWALLS));
	if (valid_surroundings(map[dim.y + 1][dim.x]) == FALSE
		|| valid_surroundings(map[dim.y - 1][dim.x]) == FALSE
		|| valid_surroundings(map[dim.y][dim.x + 1]) == FALSE
		|| valid_surroundings(map[dim.y][dim.x - 1]) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	validation_walls(char **map)
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
			{
				if (check_walls(map, dim) == FALSE)
					return (FALSE);
			}
			else if (valid_char(map[dim.y][dim.x]) == FALSE)
				return (FALSE);
		}
	}
	if (recheck_walls(map) == FALSE)
		return (FALSE);
	return (TRUE);
}
