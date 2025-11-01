/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:11:04 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/11/01 19:00:26 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ex_utils.h"

void	paint_bg(t_ex_utils *ex_utils)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(ex_utils->bg, x, y++, ex_utils->c_color);
			else
				mlx_put_pixel(ex_utils->bg, x, y++, ex_utils->f_color);
		}
		x++;
	}
}

void	draw_wall(t_ex_utils *ex_utils, t_rayc *rayc, int x)
{
	uint32_t	color;
	int			y;

	color = 0x00FF00FF;
	rayc->draw_start = -rayc->wall_h / 2 + HEIGHT / 2;
	if (rayc->draw_start < 0)
		rayc->draw_start = 0;
	rayc->draw_end = rayc->wall_h / 2 + HEIGHT / 2;
	if (rayc->draw_end >= HEIGHT)
		rayc->draw_end = HEIGHT - 1;
	if (rayc->side.y)
		color = 0xFF0000FF;
	y = rayc->draw_start - 1;
	while (++y < rayc->draw_end)
		mlx_put_pixel(ex_utils->bg, x, y, color);
}
