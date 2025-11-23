/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:43:30 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/11/23 15:38:46 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_utils.h"

/* static void	free_textures(t_ex_utils *ex_utils)
{
	mlx_delete_texture(ex_utils->imgs.no.tex);
	mlx_delete_texture(ex_utils->imgs.so.tex);
	mlx_delete_texture(ex_utils->imgs.we.tex);
	mlx_delete_texture(ex_utils->imgs.ea.tex);
	mlx_delete_image(ex_utils->mlx, ex_utils->imgs.no.img);
	mlx_delete_image(ex_utils->mlx, ex_utils->imgs.so.img);
	mlx_delete_image(ex_utils->mlx, ex_utils->imgs.we.img);
} */

void	free_images(t_ex_utils *ex_utils, int err_lvl)
{
	if (err_lvl == 1 || !ex_utils || !ex_utils->mlx)
		return ;
	if ((err_lvl > 1 || err_lvl == 0) && ex_utils->imgs.no.tex)
		mlx_delete_texture(ex_utils->imgs.no.tex);
	if ((err_lvl > 2 || err_lvl == 0) && ex_utils->imgs.so.tex)
		mlx_delete_texture(ex_utils->imgs.so.tex);
	if ((err_lvl > 3 || err_lvl == 0) && ex_utils->imgs.we.tex)
		mlx_delete_texture(ex_utils->imgs.we.tex);
	if ((err_lvl > 4 || err_lvl == 0) && ex_utils->imgs.ea.tex)
		mlx_delete_texture(ex_utils->imgs.ea.tex);
	if ((err_lvl > 5 || err_lvl == 0) && ex_utils->imgs.no.img)
		mlx_delete_image(ex_utils->mlx, ex_utils->imgs.no.img);
	if ((err_lvl > 6 || err_lvl == 0) && ex_utils->imgs.so.img)
		mlx_delete_image(ex_utils->mlx, ex_utils->imgs.so.img);
	if ((err_lvl > 7 || err_lvl == 0) && ex_utils->imgs.we.img)
		mlx_delete_image(ex_utils->mlx, ex_utils->imgs.we.img);
	if ((err_lvl > 8 || err_lvl == 0) && ex_utils->imgs.ea.img)
		mlx_delete_image(ex_utils->mlx, ex_utils->imgs.ea.img);
}
