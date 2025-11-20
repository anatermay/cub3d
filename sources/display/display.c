/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:11:04 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/11/19 14:28:49 by jsanz-bo         ###   ########.fr       */
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

static mlx_texture_t	*get_tex_by_side(t_ex_utils *ex_utils, t_rayc *rayc)
{
	mlx_texture_t	*tex;

	tex = ex_utils->imgs.no.tex;
	if (rayc->side.x && rayc->step.x > 0)
		tex = ex_utils->imgs.ea.tex;
	else if (rayc->side.x && rayc->step.x < 0)
		tex = ex_utils->imgs.we.tex;
	else if (rayc->side.y && rayc->step.y < 0)
		tex = ex_utils->imgs.so.tex;
	return (tex);
}

static void	dr_pixels(t_ex_utils *ex_utils, t_rayc *rayc, t_dr_utils dr_utils)
{
	uint32_t	color;
	double		tex_pos;
	double		step;
	int			ind;
	int			max_pixels;

	step = (double)dr_utils.tex->height / rayc->wall_h;
	tex_pos = (rayc->draw_start - HEIGHT / 2 + rayc->wall_h / 2) * step;
	max_pixels = dr_utils.tex->width * dr_utils.tex->height
		* dr_utils.tex->bytes_per_pixel;
	while (++(dr_utils.y) < rayc->draw_end)
	{
		dr_utils.tex_y = (int)tex_pos & (dr_utils.tex->height - 1);
		tex_pos += step;
		ind = (dr_utils.tex_y * dr_utils.tex->width + dr_utils.tex_x) * 4;
		if (ind < 0)
			ind = 0;
		else if (ind > max_pixels)
			ind = max_pixels - 1;
		color = (dr_utils.tex->pixels[ind] << 24)
			| (dr_utils.tex->pixels[ind + 1] << 16)
			| (dr_utils.tex->pixels[ind + 2] << 8)
			| dr_utils.tex->pixels[ind + 3];
		mlx_put_pixel(ex_utils->bg, dr_utils.x, dr_utils.y, color);
	}
}

void	draw_wall(t_ex_utils *ex_utils, t_rayc *rayc, int x)
{
	t_dr_utils	dr_utils;

	dr_utils.x = x;
	dr_utils.tex = get_tex_by_side(ex_utils, rayc);
	rayc->draw_start = -rayc->wall_h / 2 + HEIGHT / 2;
	if (rayc->draw_start < 0)
		rayc->draw_start = 0;
	rayc->draw_end = rayc->wall_h / 2 + HEIGHT / 2;
	if (rayc->draw_end >= HEIGHT)
		rayc->draw_end = HEIGHT - 1;
	dr_utils.y = rayc->draw_start - 1;
	dr_utils.tex_x = (int)(rayc->wall_x * dr_utils.tex->width);
	if ((rayc->side.x && rayc->dir.x > 0) || (rayc->side.y && rayc->dir.y < 0))
		dr_utils.tex_x = dr_utils.tex->width - dr_utils.tex_x - 1;
	dr_pixels(ex_utils, rayc, dr_utils);
}
