/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:29:12 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/11/13 18:29:25 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ex_utils.h"

static void	get_imgs(t_game *game, t_ex_utils *ex_utils)
{
	ex_utils->imgs.no.tex = mlx_load_png(game->north->tex->tex);
	ex_utils->imgs.so.tex = mlx_load_png(game->south->tex->tex);
	ex_utils->imgs.we.tex = mlx_load_png(game->west->tex->tex);
	ex_utils->imgs.ea.tex = mlx_load_png(game->east->tex->tex);
	ex_utils->imgs.no.img = mlx_texture_to_image(ex_utils->mlx,
			ex_utils->imgs.no.tex);
	ex_utils->imgs.so.img = mlx_texture_to_image(ex_utils->mlx,
			ex_utils->imgs.so.tex);
	ex_utils->imgs.we.img = mlx_texture_to_image(ex_utils->mlx,
			ex_utils->imgs.we.tex);
	ex_utils->imgs.ea.img = mlx_texture_to_image(ex_utils->mlx,
			ex_utils->imgs.ea.tex);
}

static void	build_bg(t_game *game, t_ex_utils *ex_utils)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	a;

	a = OPACITY;
	ex_utils->bg = mlx_new_image(ex_utils->mlx, WIDTH, HEIGHT);
	r = game->ceil->red;
	g = game->ceil->green;
	b = game->ceil->blue;
	ex_utils->c_color = (r << 24 | g << 16 | b << 8 | a);
	r = game->floor->red;
	g = game->floor->green;
	b = game->floor->blue;
	ex_utils->f_color = (r << 24 | g << 16 | b << 8 | a);
	mlx_image_to_window(ex_utils->mlx, ex_utils->bg, 0, 0);
}

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
	if (!ex_utils)
	{
		return ;
	}
	ex_utils->map = game->map->map;
	ex_utils->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	get_imgs(game, ex_utils);
	build_bg(game, ex_utils);
	paint_bg(ex_utils);
	init_player(game, ex_utils);
	init_camera(ex_utils);
	rayc_loop(ex_utils);
	mlx_loop_hook(ex_utils->mlx, mov_loop, ex_utils);
	mlx_loop(ex_utils->mlx);
	free_images(ex_utils);
	mlx_terminate(ex_utils->mlx);
	free(ex_utils);
}
