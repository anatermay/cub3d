/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_process_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:45:04 by aternero          #+#    #+#             */
/*   Updated: 2025/09/10 20:46:33 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static int	process_map(t_game *game, t_file *start)
{
	if (!start)
		return (print_error(ENOMAP));
	game->map->map = extract_map(start);
	if (!game->map->map)
		return (FALSE);
	if (map_check(game) == FALSE)
		return (free_game(game));
	return (TRUE);
}