/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:11:04 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/10/18 19:12:00 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ex_utils.h"

void	get_images(t_game *game, t_ex_utils *ex_utils)
{
	ex_utils->mini_tex.wall.tex = "./imgs/minimap/mini_wall.png";
	ex_utils->mini_tex.pj.tex = "./imgs/minimap/mini_pj.png";
	game->north->tex->text = mlx_load_png(game->north->tex->tex);
	game->south->tex->text = mlx_load_png(game->south->tex->tex);
	game->west->tex->text = mlx_load_png(game->west->tex->tex);
	game->east->tex->text = mlx_load_png(game->east->tex->tex);
	ex_utils->mini_tex.wall.text = mlx_load_png(ex_utils->mini_tex.wall.tex);
	ex_utils->mini_tex.pj.text = mlx_load_png(ex_utils->mini_tex.pj.tex);
	game->north->tex->img = mlx_texture_to_image(game->mlx,
		game->north->tex->text);
	game->south->tex->img = mlx_texture_to_image(game->mlx,
		game->south->tex->text);
	game->west->tex->img = mlx_texture_to_image(game->mlx,
		game->west->tex->text);
	game->east->tex->img = mlx_texture_to_image(game->mlx,
		game->east->tex->text);
	ex_utils->mini_tex.wall.img = mlx_texture_to_image(game->mlx,
		ex_utils->mini_tex.wall.text);
	ex_utils->mini_tex.pj.img = mlx_texture_to_image(game->mlx,
		ex_utils->mini_tex.pj.text);
}

void	display_minimap(t_game *game, t_ex_utils *ex_utils)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < game->map->dim.y)
	{
		j = 0;
		while (j < game->map->dim.x)
		{
			c = game->map->map[i][j];
			if (c == '1')
				mlx_image_to_window(game->mlx, ex_utils->mini_tex.wall.img,\
									j * 64, i * 64);
			if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
				mlx_image_to_window(game->mlx, ex_utils->mini_tex.pj.img,\
									j * 64, i * 64);
			j++;
		}
		i++;
	}
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
	mlx_image_to_window(game->mlx, ex_utils->bg, 0, 0);
}
