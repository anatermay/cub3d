/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:56:52 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/11/15 16:05:09 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_utils.h"

static int	get_imgs(t_ex_utils *ex_utils)
{
	ex_utils->imgs.no.img = mlx_texture_to_image(ex_utils->mlx,
			ex_utils->imgs.no.tex);
	if (!ex_utils->imgs.no.img)
		return (5);
	ex_utils->imgs.so.img = mlx_texture_to_image(ex_utils->mlx,
			ex_utils->imgs.so.tex);
	if (!ex_utils->imgs.so.img)
		return (6);
	ex_utils->imgs.we.img = mlx_texture_to_image(ex_utils->mlx,
			ex_utils->imgs.we.tex);
	if (!ex_utils->imgs.we.img)
		return (7);
	ex_utils->imgs.ea.img = mlx_texture_to_image(ex_utils->mlx,
			ex_utils->imgs.ea.tex);
	if (!ex_utils->imgs.ea.img)
		return (8);
	return (0);
}

static int	get_texs(t_game *game, t_ex_utils *ex_utils)
{
	ex_utils->imgs.no.tex = mlx_load_png(game->north->tex->tex);
	if (!ex_utils->imgs.no.tex)
		return (1);
	ex_utils->imgs.so.tex = mlx_load_png(game->south->tex->tex);
	if (!ex_utils->imgs.so.tex)
		return (2);
	ex_utils->imgs.we.tex = mlx_load_png(game->west->tex->tex);
	if (!ex_utils->imgs.we.tex)
		return (3);
	ex_utils->imgs.ea.tex = mlx_load_png(game->east->tex->tex);
	if (!ex_utils->imgs.ea.tex)
		return (4);
	return (0);
}

int	load_imgs(t_game *game, t_ex_utils *ex_utils)
{
	int	err_lvl;

	err_lvl = get_texs(game, ex_utils);
	if (!err_lvl)
		err_lvl = get_imgs(ex_utils);
	return (err_lvl);
}
