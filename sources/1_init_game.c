/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:38:44 by aternero          #+#    #+#             */
/*   Updated: 2025/09/01 18:39:08 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static void	*free_init_game(t_game *game, char **file, char *argv, int frees)
{
	if (!game && !file && !argv)
		return (NULL);
	if ((frees == 0 || frees == 1 || frees == 3) && game)
		free(game);
	if ((frees == 1 || frees == 2 || frees == 3) && file)
		array_free(file);
	if (argv)
		free(argv);
	return (NULL);
}

static void	init_coords_2(t_game *game, char *id)
{
	if (ft_strncmp(id, NORTH, 2) == 0)
	{
		game->north->id = NAC;
		game->north->id_name = id;
	}
	if (ft_strncmp(id, SOUTH, 2) == 0)
	{
		game->south->id = SAC;
		game->south->id_name = id;
	}
	if (ft_strncmp(id, WEST, 2) == 0)
	{
		game->west->id = WAC;
		game->west->id_name = id;
	}
	if (ft_strncmp(id, EAST, 2) == 0)
	{
		game->east->id = EAC;
		game->east->id_name = id;
	}
	coord_count(game, id);
}

static int	init_coords(t_game *game)
{
	game->north = (t_coord *)malloc(sizeof(t_coord));
	if (!game->north)
	{
		print_error(EMALLOC);
		return (FALSE);
	}
	game->south = (t_coord *)malloc(sizeof(t_coord));
	if (!game->south)
	{
		print_error(EMALLOC);
		return (FALSE);
	}
	game->east = (t_coord *)malloc(sizeof(t_coord));
	if (!game->east)
	{
		print_error(EMALLOC);
		return (FALSE);
	}
	game->west = (t_coord *)malloc(sizeof(t_coord));
	if (!game->west)
	{
		print_error(EMALLOC);
		return (FALSE);
	}
	return (TRUE);
}

static int	init_game_continue(t_game *game, char *argv)
{
	game->path = argv;
	if (init_coords(game) == FALSE)
	{
		free_init_game(game, NULL, argv, 0);
		return (FALSE);
	}
	init_coords_2(game, NORTH);
	init_coords_2(game, SOUTH);
	init_coords_2(game, EAST);
	init_coords_2(game, WEST);
	game->floor = (t_vert *)malloc(sizeof(t_vert));
	if (!game->floor)
	{
		free_init_game(game, NULL, argv, 0);
		return (print_error(EMALLOC));
	}
	game->floor->id = FLOOR;
	game->ceil = (t_vert *)malloc(sizeof(t_vert));
	if (!game->ceil)
	{
		free_init_game(game, NULL, argv, 0);
		return (print_error(EMALLOC));
	}
	game->ceil->id = CEILING;
	return (TRUE);
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
		return (free_init_game(game, file, argv, 0));
	game->file = init_file(file, argv);
	if (!game->file)
		return (free_init_game(game, file, argv, 1));
	if (init_game_continue(game, argv) == FALSE)
		return (free_init_game(game, file, argv, 1));
	free_init_game(game, file, argv, 2);
	return (game);
}
