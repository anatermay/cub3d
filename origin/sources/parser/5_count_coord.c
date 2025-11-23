/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_count_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:13:51 by aternero          #+#    #+#             */
/*   Updated: 2025/09/03 19:44:24 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

void	coord_count(t_game *game, t_coord *coord, char *id)
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
				coord->events++;
		}
		file = file->next;
	}
}
