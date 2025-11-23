/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_memfree1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:58:15 by aternero          #+#    #+#             */
/*   Updated: 2025/09/17 18:08:55 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

void	*free_map(t_map *map)
{
	if (!map)
		return (NULL);
	if (map->map)
		array_free(map->map);
	free (map);
	map = NULL;
	return (NULL);
}
