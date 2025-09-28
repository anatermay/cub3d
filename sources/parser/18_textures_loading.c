/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   18_textures_loading.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:59:35 by aternero          #+#    #+#             */
/*   Updated: 2025/09/27 13:25:47 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

static int	loading_texture_textures(t_coord *coord)
{
	if (ft_strncmp(coord->tex->tex, ".png", 4) == 0
		|| ft_strncmp(coord->tex->tex, ".xpm", 4) == 0)
	{
		coord->tex->text = mlx_load_png(coord->tex->tex);
		if (!coord->tex->text)
			return (print_error("Texture didn't load"));
	}
	else
	{
		coord->tex->text = NULL;
		return (print_error("Texture is not a PNG or XPM"));
	}
	return (TRUE);
}

void	load_image(t_game *game)
{
	int	keep;

	keep = TRUE;
	while (keep == TRUE)
	{
		keep = loading_texture_textures(game->north);
		keep = loading_texture_textures(game->south);
		keep = loading_texture_textures(game->west);
		keep = loading_texture_textures(game->east);
		break ;
	}
	if (keep == FALSE)
	{
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
