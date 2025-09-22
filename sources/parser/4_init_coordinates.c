/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_init_coordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:39:45 by aternero          #+#    #+#             */
/*   Updated: 2025/09/10 19:03:44 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static t_coord	*new_coord_node(t_game *game, char *idnm)
{
	t_coord	*coord;

	coord = (t_coord *)malloc(sizeof(t_coord));
	if (!coord)
	{
		print_error(EMALLOC);
		free(idnm);
		return (NULL);
	}
	coord->id = idnm[0];
	coord->id_name = ft_strdup(idnm);
	coord->events = 0;
	coord_count(game, coord, idnm);
	coord->tex = NULL;
	free(idnm);
	return (coord);
}

int	init_coords(t_game *game)
{
	game->north = new_coord_node(game, ft_strdup(NORTH));
	if (!game->north)
		return (FALSE);
	game->south = new_coord_node(game, ft_strdup(SOUTH));
	if (!game->south)
		return (FALSE);
	game->east = new_coord_node(game, ft_strdup(EAST));
	if (!game->east)
		return (FALSE);
	game->west = new_coord_node(game, ft_strdup(WEST));
	if (!game->west)
		return (FALSE);
	return (TRUE);
}
