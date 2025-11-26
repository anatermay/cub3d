/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14_valid_characters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:52:59 by aternero          #+#    #+#             */
/*   Updated: 2025/09/28 10:55:58 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

int	valid_characters(char **map)
{
	int	yndex;
	int	index;

	yndex = -1;
	while (map[++yndex])
	{
		index = -1;
		while (map[yndex][++index])
		{
			if (is_space(map[yndex][index]) == FALSE
				&& map[yndex][index] != '0' && map[yndex][index] != '1'
				&& is_position(map[yndex][index]) == FALSE)
				return (print_error(EMCHR));
		}
	}
	return (TRUE);
}
