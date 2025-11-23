/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_lines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:22:33 by aternero          #+#    #+#             */
/*   Updated: 2025/09/23 19:24:35 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

int	valid_special_row(char *map)
{
	int	index;

	index = -1;
	while (map[++index])
	{
		if (map[index] != '1')
			return (FALSE);
	}
	return (TRUE);
}

int	first_row(char **map, int index)
{
	int	y;

	y = 0;
	while (map[y] && is_space_array(map[y]) == TRUE)
		y++;
	if (index == y)
		return (TRUE);
	return (FALSE);
}

int	first_column(char *map, int index)
{
	int	y;

	y = 0;
	while (map[y] && is_space(map[y]) == TRUE)
		y++;
	if (index == y)
		return (TRUE);
	return (FALSE);
}

int	last_row(char **map, int yndex)
{
	int	index;

	index = -1;
	while (map[++index])
	{
		if (!map[index + 1])
			break ;
	}
	while (is_space_array(map[index]) == TRUE)
		index--;
	if (index == yndex)
		return (TRUE);
	return (FALSE);
}

int	last_column(char *map, int yndex)
{
	int	index;

	index = -1;
	while (map[++index])
	{
		if (!map[index + 1])
			break ;
	}
	while (is_space(map[index]) == TRUE)
		index--;
	if (index == yndex)
		return (TRUE);
	return (FALSE);
}
