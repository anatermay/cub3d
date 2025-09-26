/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 22:11:10 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/09/26 22:13:51 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct textures_struct
{
	mlx_texture_t	*floor_tex;
	mlx_texture_t	*wall_tex;
	mlx_texture_t	*player_tex;
	mlx_image_t		*floor_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*player_img;
}					t_testing_img;
