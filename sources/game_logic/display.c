/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:11:04 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/10/21 22:36:14 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ex_utils.h"

void	get_images(t_game *game)
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

static void	build_bg(t_game *game, t_ex_utils *ex_utils)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	a;

	a = OPACITY;
	ex_utils->bg = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	r = game->ceil->red;
	g = game->ceil->green;
	b = game->ceil->blue;
	ex_utils->c_color = (r << 24 | g << 16 | b << 8 | a);
	r = game->floor->red;
	g = game->floor->green;
	b = game->floor->blue;
	ex_utils->f_color = (r << 24 | g << 16 | b << 8 | a);
}

void	paint_bg(t_game* game, t_ex_utils *ex_utils)
{
	int	x;
	int	y;

	build_bg(game, ex_utils);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(ex_utils->bg, x, y++, ex_utils->c_color);
			else
				mlx_put_pixel(ex_utils->bg, x, y++, ex_utils->f_color);
		}
		x++;
	}
}

void	draw_wall(t_ex_utils *ex_utils, t_rayc *rayc, int x)
{
	uint32_t	color;
	int			y;

	color = 0x00FF00FF;
	rayc->draw_start = -rayc->wall_h / 2 + HEIGHT / 2;
	if (rayc->draw_start < 0)
		rayc->draw_start = 0;
	rayc->draw_end = rayc->wall_h / 2 + HEIGHT / 2;
	if (rayc->draw_end >= HEIGHT)
		rayc->draw_end = HEIGHT - 1;
	if (rayc->side.y)
		color = 0xFF0000FF;
	y = rayc->draw_start - 1;
	while (++y < rayc->draw_end)
		mlx_put_pixel(ex_utils->bg, x, y, color);
}
