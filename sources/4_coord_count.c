/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_coord_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:13:51 by aternero          #+#    #+#             */
/*   Updated: 2025/08/28 12:35:00 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static void	add_coord_count(t_game *game, char *id)
{
	if (ft_strncmp(id, NORTH, 2) == 0)
		game->north->events++;
	if (ft_strncmp(id, SOUTH, 2) == 0)
		game->south->events++;
	if (ft_strncmp(id, WEST, 2) == 0)
		game->west->events++;
	if (ft_strncmp(id, EAST, 2) == 0)
		game->east->events++;
}

void	coord_count(t_game *game, char *id)
{
	t_file	*file;
	char	i;
	char	d;
	int		index;

	file = game->file;
	i = id[0];
	d = id[1];
	while (file)
	{
		index = -1;
		while (file->line[++index])
		{
			if (file->line[index] == i
				&& (file->line[index + 1] && file->line[index + 1] == d))
				add_coord_count(game, id);
		}
		file = file->next;
	}
}
