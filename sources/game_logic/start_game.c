/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:29:12 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/10/18 12:11:53 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_images(t_game *game)
{
	game->north->tex->text = mlx_load_png(game->north->tex->tex);
	game->south->tex->text = mlx_load_png(game->south->tex->tex);
	game->west->tex->text = mlx_load_png(game->west->tex->tex);
	game->east->tex->text = mlx_load_png(game->east->tex->tex);
	game->north->tex->img = mlx_texture_to_image(game->mlx,
		game->north->tex->text);
	game->south->tex->img = mlx_texture_to_image(game->mlx,
		game->south->tex->text);
	game->west->tex->img = mlx_texture_to_image(game->mlx,
		game->west->tex->text);
	game->east->tex->img = mlx_texture_to_image(game->mlx,
		game->east->tex->text);
}

static void	display_image(t_game *game, int i, int j)
{
	char	c;

	c = game->map->map[i][j];
	if (c == '1')
		mlx_image_to_window(game->mlx, game->north->tex->img, j * 64, i * 64);
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		mlx_image_to_window(game->mlx, game->south->tex->img, j * 64, i * 64);
}

static void	display_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->dim.y)
	{
		j = 0;
		while (j < game->map->dim.x)
		{
			mlx_image_to_window(game->mlx, game->west->tex->img, j * 64, i * 64);
			display_image(game, i, j);
			j++;
		}
		i++;
	}
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init(game->map->dim.x * 64, game->map->dim.y * 64,
                "cub3D", true);
	get_images(game);
	display_map(game);
	// mlx_key_hook(game->mlx, key_controller, data_game);
	mlx_loop(game->mlx);
	// if (game->collected == game->collects_total && game->exit)
	// 	ft_printf("You won!\n");
	// free_images(game);
	// mlx_terminate(game->mlx);
}
