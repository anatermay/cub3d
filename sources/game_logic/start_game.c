/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:29:12 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/09/26 22:40:18 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "testing.h"

static void	get_images(t_game *game, t_testing_img *assets)
{
	assets->wall_tex = mlx_load_png("textures/wall_wall.png");
	assets->floor_tex = mlx_load_png("textures/floor_wall.png");
	assets->player_tex = mlx_load_png("textures/player_wall.png");
	assets->wall_img = mlx_texture_to_image(game->mlx, assets->wall_tex);
	assets->floor_img = mlx_texture_to_image(game->mlx, assets->floor_tex);
	assets->player_img = mlx_texture_to_image(game->mlx, assets->player_tex);
}

static void	display_image(t_game *game, t_testing_img *assets, int i, int j)
{
	char	c;

	c = game->map->map[i][j];
	if (c == '1')
		mlx_image_to_window(game->mlx,
			assets->wall_img, j * 64, i * 64);
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		mlx_image_to_window(game->mlx,
			assets->player_img, j * 64, i * 64);
}

static void	display_map(t_game *game, t_testing_img *assets)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->dim.y)
	{
		j = 0;
		while (j < game->map->dim.x)
		{
			mlx_image_to_window(game->mlx, assets->floor_tex, j * 64, i * 64);
			display_image(game, assets, i, j);
			j++;
		}
		i++;
	}
}

void	start_game(t_game *game)
{
	t_testing_img	*assets;

	game->mlx = mlx_init(game->map->dim.x * 64, game->map->dim.y * 64,
                "cub3D", true);
	get_images(game, assets);
	display_map(game, assets);
	// mlx_key_hook(game->mlx, key_controller, data_game);
	// mlx_loop(game->mlx);
	// if (game->collected == game->collects_total && game->exit)
	// 	ft_printf("You won!\n");
	// free_images(game);
	// mlx_terminate(game->mlx);
}
