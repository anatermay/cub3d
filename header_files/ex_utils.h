/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:05:26 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/10/18 13:17:51 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX_UTILS_H
# define EX_UTILS_H

#include "cub3d.h"

typedef struct s_mini_tex
{
    t_texture   wall;
    t_texture   pj;
}   t_mini_tex;

typedef struct s_ex_utils
{
	t_mini_tex  mini_tex;
}	t_ex_utils;

#endif
