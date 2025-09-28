/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_process_coordinates.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:12:25 by aternero          #+#    #+#             */
/*   Updated: 2025/09/28 10:58:53 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static int	process_tex(t_coord *coord, char *line)
{
	int	index;

	if (coord->tex)
		return (print_error(EID));
	index = 0;
	while (is_space(line[index]) == TRUE)
		index++;
	if (ft_strncmp(line + index, "./", 2) != 0)
		return (print_error(ETEX));
	else if (ft_strncmp(line + index, "./", 2) == 0 && !line[index + 2])
		return (print_error(ETEXINV));
	coord->tex = (t_texture *)malloc(sizeof(t_texture));
	if (!coord->tex)
		return (print_error(EMALLOC));
	coord->tex->tex = space_strtrim(line);
	if (!coord->tex->tex)
	{
		free(coord->tex);
		coord->tex = NULL;
		return (print_error(EMALLOC));
	}
	return (TRUE);
}

int	process_coordinates(t_game *game, char **line)
{
	int	index;

	index = 0;
	while (is_space(line[0][index]) == TRUE)
		index++;
	if (is_coord(line[0]) == N_NBR)
		return (process_tex(game->north, line[1]));
	else if (is_coord(line[0]) == S_NBR)
		return (process_tex(game->south, line[1]));
	else if (is_coord(line[0]) == E_NBR)
		return (process_tex(game->east, line[1]));
	else if (is_coord(line[0]) == W_NBR)
		return (process_tex(game->west, line[1]));
	else
		return (print_error(EINVALIDID));
}
