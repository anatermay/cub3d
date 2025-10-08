/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   17_textures_loading.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:59:35 by aternero          #+#    #+#             */
/*   Updated: 2025/10/08 20:12:35 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/cub3d.h"

static int	loading_texture_textures(t_coord *coord)
{
	int	length;

	if (!coord->tex)
	{
		coord->tex = (t_texture *)malloc(sizeof(t_texture));
		if (!coord->tex)
			return (print_error(EMALLOC));
	}
	if (!coord->tex->tex)
	{
		coord->tex->tex = ft_strdup(coord->id_name);
		if (!coord->tex->tex)
			return (print_error(EMALLOC));
	}
	length = ft_strlen(coord->tex->tex);
	if (length < 5)
		return (print_error("Texture path too short"));
	length--;
	if (coord->tex->tex[length] != 'g'
		|| coord->tex->tex[length - 1] != 'n'
		|| coord->tex->tex[length - 2] != 'p'
		|| coord->tex->tex[length - 3] != '.')
		return (print_error("Texture is not a PNG."));
	coord->tex->text = mlx_load_png(coord->tex->tex);
	if (!coord->tex->text)
		return (print_error("Failed to load texture"));
	return (TRUE);
}

void	load_image(t_game *game)
{
	if (loading_texture_textures(game->north) == FALSE
		|| loading_texture_textures(game->south) == FALSE
		|| loading_texture_textures(game->west) == FALSE
		|| loading_texture_textures(game->east) == FALSE)
	{
		free_game(game);
		exit(FALSE);
	}
}
