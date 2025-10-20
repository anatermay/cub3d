/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:29:12 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/10/21 00:06:28 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ex_utils.h"

// void	key_controller(struct mlx_key_data key_data, void *param)
// {
// 	t_ex_utils	*game;

// 	game = param;
// 	if (key_data.key == MLX_KEY_ESCAPE)
// 		mlx_close_window(game->mlx);
// 	if (key_data.key == MLX_KEY_D && key_data.action == MLX_RELEASE)
// 		game->mini_tex.pj.img->instances[0].x += 64;
// 	if (key_data.key == MLX_KEY_A && key_data.action == MLX_RELEASE)
// 		game->mini_tex.pj.img->instances[0].x -= 64;
// 	if (key_data.key == MLX_KEY_W && key_data.action == MLX_RELEASE)
// 		game->mini_tex.pj.img->instances[0].y -= 64;
// 	if (key_data.key == MLX_KEY_S && key_data.action == MLX_RELEASE)
// 		game->mini_tex.pj.img->instances[0].y += 64;
// }

void	init_player(t_game *game, t_ex_utils *ex_utils)
{
	ex_utils->player.pos.x = game->map->player.x + 0.5;
	ex_utils->player.pos.y = game->map->player.y + 0.5;
	ex_utils->player.dir.x = 0;
	ex_utils->player.dir.y = 0;
	ex_utils->player.ori = game->map->direction->id;
	if (ex_utils->player.ori == 'N')
		ex_utils->player.dir.y = -1;
	else if (ex_utils->player.ori == 'S')
		ex_utils->player.dir.y = 1;
	else if (ex_utils->player.ori == 'E')
		ex_utils->player.dir.x = 1;
	else if (ex_utils->player.ori == 'W')
		ex_utils->player.dir.x = -1;
}

void	init_camera(t_ex_utils *ex_utils)
{
	ex_utils->plane.x = -(ex_utils->player.dir.y) * tan(FOV * M_PI / 360.0);
	ex_utils->plane.y = (ex_utils->player.dir.x) * tan(FOV * M_PI / 360.0);
}

void	start_game(t_game *game)
{
	t_ex_utils	*ex_utils;

	ex_utils = malloc(sizeof(t_ex_utils));
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	ex_utils->mlx = game->mlx;
	get_images(game, ex_utils);
	paint_bg(game, ex_utils);
	init_player(game, ex_utils);
	init_camera(ex_utils);
	rayc_loop(game, ex_utils);
	printf("%c", ex_utils->player.ori);
	//mlx_key_hook(game->mlx, key_controller, ex_utils);
	mlx_loop(game->mlx);
	// if (game->collected == game->collects_total && game->exit)
	// 	ft_printf("You won!\n");
	// free_images(game);
	// mlx_terminate(game->mlx);
}
