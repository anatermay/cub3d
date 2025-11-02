/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:35:46 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/11/02 19:51:48 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_utils.h"

static void	update_frame(t_ex_utils *ex_utils)
{
	paint_bg(ex_utils);
	rayc_loop(ex_utils);
}

static void	handle_input(t_ex_utils *ex, double *m_x, double *m_y, double *rot)
{
	if (mlx_is_key_down(ex->mlx, MLX_KEY_W))
	{
		*m_x += ex->player.dir.x * MOV_SPEED;
		*m_y += ex->player.dir.y * MOV_SPEED;
	}
	if (mlx_is_key_down(ex->mlx, MLX_KEY_S))
	{
		*m_x -= ex->player.dir.x * MOV_SPEED;
		*m_y -= ex->player.dir.y * MOV_SPEED;
	}
	if (mlx_is_key_down(ex->mlx, MLX_KEY_D))
	{
		*m_x -= ex->player.dir.y * MOV_SPEED;
		*m_y += ex->player.dir.x * MOV_SPEED;
	}
	if (mlx_is_key_down(ex->mlx, MLX_KEY_A))
	{
		*m_x += ex->player.dir.y * MOV_SPEED;
		*m_y -= ex->player.dir.x * MOV_SPEED;
	}
	if (mlx_is_key_down(ex->mlx, MLX_KEY_LEFT))
		*rot -= ROT_SPEED;
	if (mlx_is_key_down(ex->mlx, MLX_KEY_RIGHT))
		*rot += ROT_SPEED;
}

static void	apply_mov(t_ex_utils *ex, double m_x, double m_y, double rot)
{
	if (rot)
		rotate(ex, rot);
	if (m_x || m_y)
		move(ex, m_x, m_y);
}

void	mov_loop(void *param)
{
	t_ex_utils	*ex;
	double		m_x;
	double		m_y;
	double		rot;

	ex = param;
	m_x = 0;
	m_y = 0;
	rot = 0;
	handle_input(ex, &m_x, &m_y, &rot);
	if (mlx_is_key_down(ex->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(ex->mlx);
	apply_mov(ex, m_x, m_y, rot);
	update_frame(ex);
}
