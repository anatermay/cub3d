/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:56:52 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/11/15 13:09:54 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_utils.h"

static int  get_imgs(t_ex_utils *ex_utils)
{
    ex_utils->imgs.NO.img = mlx_texture_to_image(ex_utils->mlx,
		ex_utils->imgs.NO.tex);
    if (!ex_utils->imgs.NO.img)
		return (5);
	ex_utils->imgs.SO.img = mlx_texture_to_image(ex_utils->mlx,
		ex_utils->imgs.SO.tex);
    if (!ex_utils->imgs.SO.img)
		return (6);
	ex_utils->imgs.WE.img = mlx_texture_to_image(ex_utils->mlx,
		ex_utils->imgs.WE.tex);
    if (!ex_utils->imgs.WE.img)
		return (7);
	ex_utils->imgs.EA.img = mlx_texture_to_image(ex_utils->mlx,
		ex_utils->imgs.EA.tex);
    if (!ex_utils->imgs.EA.img)
		return (8);
    return (0);
}

static int	get_texs(t_game *game, t_ex_utils *ex_utils)
{
	ex_utils->imgs.NO.tex = mlx_load_png(game->north->tex->tex);
	if (!ex_utils->imgs.NO.tex)
		return (1);
	ex_utils->imgs.SO.tex = mlx_load_png(game->south->tex->tex);
	if (!ex_utils->imgs.SO.tex)
		return (2);
	ex_utils->imgs.WE.tex = mlx_load_png(game->west->tex->tex);
	if (!ex_utils->imgs.WE.tex)
		return (3);
	ex_utils->imgs.EA.tex = mlx_load_png(game->east->tex->tex);
	if (!ex_utils->imgs.EA.tex)
		return (4);
	return (0);
}

int load_imgs(t_game *game, t_ex_utils *ex_utils)
{
    int err_lvl;

    err_lvl = get_texs(game, ex_utils);
    if (!err_lvl)
        err_lvl = get_imgs(ex_utils);
    return (err_lvl);
}
