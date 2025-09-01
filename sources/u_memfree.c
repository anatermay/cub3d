/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_memfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 14:01:01 by aternero          #+#    #+#             */
/*   Updated: 2025/09/01 18:21:18 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

void	free_file(t_file **file)
{
	t_file	*temp;

	if (!file || !(*file))
		return ;
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
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_file(&game->file);
	if (game->north)
		free(game->north);
	if (game->south)
		free(game->south);
	if (game->east)
		free(game->east);
	if (game->west)
		free(game->west);
	if (game->floor)
		free(game->floor);
	if (game->ceil)
		free(game->ceil);
	free(game);
}

void	array_free(char **array)
{
	int	index;

	if (!array)
		return ;
	index = 0;
	while (array[index])
	{
		free(array[index]);
		array[index] = NULL;
		index++;
	}
	free(array);
}
