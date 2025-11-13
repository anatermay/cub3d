/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:49:58 by aternero          #+#    #+#             */
/*   Updated: 2025/11/13 18:04:01 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static char	**arraydup(char **map)
{
	char	**ret;
	int		index;

	index = 0;
	while (map[index])
		index++;
	ret = (char **)malloc(sizeof(char *) * (index + 1));
	if (!ret)
		return (NULL);
	index = -1;
	while (map[++index])
		ret[index] = ft_strdup(map[index]);
	ret[index] = NULL;
	return (ret);
}

int	map_check(t_game *game)
{
	char	**ff;

	if (!game || !game->map || !game->map->map)
		return (FALSE);
	if (valid_characters(game->map->map) == FALSE)
		return (FALSE);
	else if (single_player(game->map->map) == FALSE)
		return (FALSE);
	ff = arraydup(game->map->map);
	if (re_recheck(ff, game->map->dim) == FALSE)
		return (FALSE);
	return (TRUE);
}
