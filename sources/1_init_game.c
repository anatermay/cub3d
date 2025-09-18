/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:38:44 by aternero          #+#    #+#             */
/*   Updated: 2025/09/17 16:18:25 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static void	*this_file_free(t_game *game, char **file, int frees)
{
	if (file)
	{
		if (game && frees == TRUE)
			free_game(game);
		array_free(file);
	}
	return (NULL);
}

static int	init_game_continue(t_game *game, char *argv)
{
	game->path = argv;
	if (init_coords(game) == FALSE)
		return (FALSE);
	game->floor = init_vertical(game, FLOOR, argv);
	if (!game->floor)
		return (FALSE);
	game->ceil = init_vertical(game, CEILING, argv);
	if (!game->ceil)
		return (FALSE);
	return (TRUE);
}

t_game	*init_game(char *argv)
{
	t_game	*game;
	char	**file;

	file = map_file_content(argv);
	if (!file)
		return (NULL);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		print_error(EMALLOC);
		return (this_file_free(NULL, file, FALSE));
	}
	game->path = argv;
	game->file = NULL;
	game->file = init_file(file, argv);
	if (!game->file)
		return (this_file_free(game, file, TRUE));
	if (init_game_continue(game, argv) == FALSE)
		return (this_file_free(game, file, TRUE));
	game->map = NULL;
	this_file_free(NULL, file, FALSE);
	return (game);
}
