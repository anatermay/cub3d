/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:43:30 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/11/13 18:30:39 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_utils.h"

void	free_images(t_ex_utils *ex_utils)
{
	mlx_delete_texture(ex_utils->imgs.no.tex);
	mlx_delete_texture(ex_utils->imgs.so.tex);
	mlx_delete_texture(ex_utils->imgs.we.tex);
	mlx_delete_texture(ex_utils->imgs.ea.tex);
	mlx_delete_image(ex_utils->mlx, ex_utils->imgs.no.img);
	mlx_delete_image(ex_utils->mlx, ex_utils->imgs.so.img);
	mlx_delete_image(ex_utils->mlx, ex_utils->imgs.we.img);
	mlx_delete_image(ex_utils->mlx, ex_utils->imgs.ea.img);
}
