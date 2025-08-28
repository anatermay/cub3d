/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:38:44 by aternero          #+#    #+#             */
/*   Updated: 2025/08/28 11:24:08 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static void	free_init_game(t_game *game, char **file, char *argv, int frees)
{
	if (frees == 0)
	{
		free_game(game);
		free(argv);
	}
	if (frees == 1)
	{
		free_game(game);
		array_free(file);
		free(argv);
	}
	if (frees == 2)
	{
		array_free(file);
		free(argv);
	}
}

t_game	*init_game(char *argv)
{
	t_game	*game;
	char	**file;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		print_error(EMALLOC);
		return (NULL);
	}
	game->file = NULL;
	file = map_file_content(argv);
	if (!file)
	{
		free_init_game(game, file, argv, 0);
		return (NULL);
	}
	game->file = init_file(file, argv);
	if (!game->file)
	{
		free_init_game(game, file, argv, 1);
		return (NULL);
	}
	free_init_game(game, file, argv, 2);
	return (game);
}
