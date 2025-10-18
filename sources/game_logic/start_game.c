/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:29:12 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/10/18 13:37:31 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ex_utils.h"

static void	get_images(t_game *game, t_ex_utils *ex_utils)
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

static void	display_image(t_game *game, t_ex_utils *ex_utils, int i, int j)
{
	char	c;

	c = game->map->map[i][j];
	if (c == '1')
		mlx_image_to_window(game->mlx, ex_utils->mini_tex.wall.img, j * 64,\
							i * 64);
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		mlx_image_to_window(game->mlx, ex_utils->mini_tex.pj.img, j * 64,\
							i * 64);
}

static void	display_map(t_game *game, t_ex_utils *ex_utils)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->dim.y)
	{
		j = 0;
		while (j < game->map->dim.x)
		{
			display_image(game, ex_utils, i, j);
			j++;
		}
		i++;
	}
}

void	start_game(t_game *game)
{
	t_ex_utils	*ex_utils;

	ex_utils = malloc(sizeof(t_ex_utils));
	game->mlx = mlx_init(1920, 1080, "cub3D", true);
	get_images(game, ex_utils);
	display_map(game, ex_utils);
	// mlx_key_hook(game->mlx, key_controller, data_game);
	mlx_loop(game->mlx);
	// if (game->collected == game->collects_total && game->exit)
	// 	ft_printf("You won!\n");
	// free_images(game);
	// mlx_terminate(game->mlx);
}
