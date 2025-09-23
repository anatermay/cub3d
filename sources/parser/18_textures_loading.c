/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   18_textures_loading.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:59:35 by aternero          #+#    #+#             */
/*   Updated: 2025/09/23 19:24:08 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

void	load_image(t_game *game)
{
	game->north->tex->text = mlx_load_png(game->north->tex->tex);
	game->south->tex->text = mlx_load_png(game->south->tex->tex);
	game->west->tex->text = mlx_load_png(game->west->tex->tex);
	game->east->tex->text = mlx_load_png(game->east->tex->tex);
	if (!game->north->tex->text || !game->south->tex->text
		|| !game->west->tex->text || !game->east->tex->text)
	{
		print_error("Some PNG didn't load");
		free_game(game);
		exit(FALSE);
	}
}

void	texture_to_image(t_game *game)
{
	game->north->tex->img = mlx_texture_to_image(game->mlx,
			game->north->tex->text);
	game->south->tex->img = mlx_texture_to_image(game->mlx,
			game->south->tex->text);
	game->west->tex->img = mlx_texture_to_image(game->mlx,
			game->west->tex->text);
	game->east->tex->img = mlx_texture_to_image(game->mlx,
			game->east->tex->text);
	if (!game->north->tex->img || !game->south->tex->img
		|| !game->west->tex->img || !game->east->tex->img)
	{
		print_error("Some texture to image conversion failed");
		free_game(game);
		exit(FALSE);
	}
}
