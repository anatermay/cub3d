/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15_single_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:35:08 by aternero          #+#    #+#             */
/*   Updated: 2025/09/17 19:16:46 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static int	check_player_position(char **map, int yndex, int index)
{
	if (is_space(map[yndex + 1][index]) == TRUE
		|| is_space(map[yndex - 1][index]) == TRUE
		|| is_space(map[yndex][index + 1]) == TRUE
		|| is_space(map[yndex][index - 1]) == TRUE)
		return (FALSE);
	return (TRUE);
}

static int	count_players(char **map, char c)
{
	int	players;
	int	index;
	int	yndex;

	yndex = -1;
	players = 0;
	while (map[++yndex])
	{
		index = -1;
		while (map[yndex][++index])
		{
			if (map[yndex][index] == c)
			{
				if (check_player_position(map, yndex, index) == FALSE)
					return (print_error(EMPPOS));
				players++;
			}
		}
	}
	return (players);
}

int	single_player(char **map)
{
	int	players;

	players = 0;
	players += count_players(map, 'N');
	players += count_players(map, 'S');
	players += count_players(map, 'W');
	players += count_players(map, 'E');
	if (players != 1)
		return (print_error(EPP));
	return (TRUE);
}
