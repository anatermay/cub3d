/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:43:30 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/11/15 13:46:25 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_utils.h"

void	free_images(t_ex_utils *ex_utils, int err_lvl)
{
	if (err_lvl == 1)
		return ;
	if (err_lvl > 1)
		mlx_delete_texture(ex_utils->imgs.no.tex);
	if (err_lvl > 2)
		mlx_delete_texture(ex_utils->imgs.so.tex);
	if (err_lvl > 3)
		mlx_delete_texture(ex_utils->imgs.we.tex);
	if (err_lvl > 4)
		mlx_delete_texture(ex_utils->imgs.ea.tex);
	if (err_lvl > 5)
		mlx_delete_image(ex_utils->mlx, ex_utils->imgs.no.img);
	if (err_lvl > 6)
		mlx_delete_image(ex_utils->mlx, ex_utils->imgs.so.img);
	if (err_lvl > 7)
		mlx_delete_image(ex_utils->mlx, ex_utils->imgs.we.img);
	if (!err_lvl)
		mlx_delete_image(ex_utils->mlx, ex_utils->imgs.ea.img);
}
