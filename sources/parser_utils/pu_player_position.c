/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_player_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:06:16 by aternero          #+#    #+#             */
/*   Updated: 2025/09/17 19:12:08 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

t_dim	player_position(t_game *game, char **map)
{
	t_dim	dims;

	dims.y = -1;
	while (map[++dims.y])
	{
		dims.x = -1;
		while (map[dims.y][++dims.x])
		{
			if (is_position(map[dims.y][dims.x]) == TRUE)
			{
				game->map->player.x = dims.x;
				game->map->player.y = dims.y;
				break ;
			}
		}
	}
	return (dims);
}
