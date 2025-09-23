/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_memfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 14:01:01 by aternero          #+#    #+#             */
/*   Updated: 2025/09/23 19:24:45 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

void	*free_vert(t_vert *vert)
{
	if (vert)
	{
		free(vert);
		vert = NULL;
	}
	return (NULL);
}

void	*free_coords(t_coord *coord)
{
	if (coord)
	{
		if (coord->id_name)
			free(coord->id_name);
		if (coord->tex)
		{
			if (coord->tex->tex)
				free(coord->tex->tex);
			free(coord->tex);
		}
		free(coord);
		coord = NULL;
	}
	return (NULL);
}

void	*free_file(t_file **file)
{
	t_file	*temp;

	if (!file || !(*file))
		return (NULL);
	while (*file)
	{
		temp = (*file)->next;
		if ((*file)->line)
			free((*file)->line);
		if ((*file)->path)
			free((*file)->path);
		free(*file);
		*file = temp;
	}
	*file = NULL;
	return (NULL);
}

void	*free_game(t_game *game)
{
	if (!game)
		return (NULL);
	if (game->file)
		free_file(&game->file);
	free_coords(game->north);
	free_coords(game->south);
	free_coords(game->east);
	free_coords(game->west);
	free_vert(game->floor);
	free_vert(game->ceil);
	free_map(game->map);
	free(game);
	game = NULL;
	return (NULL);
}

void	*array_free(char **array)
{
	int	index;

	if (!array)
		return (NULL);
	index = 0;
	while (array[index])
	{
		free(array[index]);
		index++;
	}
	free(array);
	return (NULL);
}
