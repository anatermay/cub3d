/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:29:12 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/10/19 01:39:01 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ex_utils.h"

void	key_controller(struct mlx_key_data key_data, void *param)
{
	t_ex_utils	*game;

	game = param;
	if (key_data.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	if (key_data.key == MLX_KEY_D && key_data.action == MLX_RELEASE)
		game->mini_tex.pj.img->instances[0].x += 64;
	if (key_data.key == MLX_KEY_A && key_data.action == MLX_RELEASE)
		game->mini_tex.pj.img->instances[0].x -= 64;
	if (key_data.key == MLX_KEY_W && key_data.action == MLX_RELEASE)
		game->mini_tex.pj.img->instances[0].y -= 64;
	if (key_data.key == MLX_KEY_S && key_data.action == MLX_RELEASE)
		game->mini_tex.pj.img->instances[0].y += 64;
}

void	start_game(t_game *game)
{
	t_ex_utils	*ex_utils;

	ex_utils = malloc(sizeof(t_ex_utils));
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	ex_utils->mlx = game->mlx;
	get_images(game, ex_utils);
	paint_bg(game, ex_utils);
	display_minimap(game, ex_utils);
	mlx_key_hook(game->mlx, key_controller, ex_utils);
	mlx_loop(game->mlx);
	// if (game->collected == game->collects_total && game->exit)
	// 	ft_printf("You won!\n");
	// free_images(game);
	// mlx_terminate(game->mlx);
}
