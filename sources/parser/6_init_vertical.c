/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_init_vertical.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:55:01 by aternero          #+#    #+#             */
/*   Updated: 2025/09/23 19:19:09 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static void	*this_file_free(t_vert *vert, char *argv)
{
	if (vert)
		free(vert);
	(void)argv;
	return (NULL);
}

static void	vert_count(t_game *game, t_vert *vert, char id)
{
	t_file	*file;
	int		index;

	file = game->file;
	while (file)
	{
		index = -1;
		while (file->line[++index])
		{
			if (file->line[index] == id)
				vert->events++;
		}
		file = file->next;
	}
}

t_vert	*init_vertical(t_game *game, char id, char *argv)
{
	t_vert	*vert;

	vert = (t_vert *)malloc(sizeof(t_vert));
	if (!vert)
	{
		print_error(EMALLOC);
		return (this_file_free(vert, argv));
	}
	vert->id = id;
	vert->red = -1;
	vert->green = -1;
	vert->blue = -1;
	vert_count(game, vert, id);
	return (vert);
}
