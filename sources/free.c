/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:43:30 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/11/11 11:40:53 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_utils.h"

void	free_images(t_ex_utils *ex_utils)
{
	mlx_delete_texture(ex_utils->imgs.NO.tex);
	mlx_delete_texture(ex_utils->imgs.SO.tex);
	mlx_delete_texture(ex_utils->imgs.WE.tex);
	mlx_delete_texture(ex_utils->imgs.EA.tex);
	mlx_delete_image(ex_utils->mlx, ex_utils->imgs.NO.img);
	mlx_delete_image(ex_utils->mlx, ex_utils->imgs.SO.img);
	mlx_delete_image(ex_utils->mlx, ex_utils->imgs.WE.img);
	mlx_delete_image(ex_utils->mlx, ex_utils->imgs.EA.img);
}
