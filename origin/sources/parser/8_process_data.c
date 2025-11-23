/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_process_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:18:51 by aternero          #+#    #+#             */
/*   Updated: 2025/09/23 19:23:35 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static int	this_file(char **splited, char *error_msg)
{
	array_free(splited);
	if (error_msg)
		print_error(error_msg);
	return (FALSE);
}

static int	coord_data_process(t_game *game, char **splited)
{
	if (splited[0][0] == 'F' || splited[0][0] == 'C')
	{
		if (!ft_strchr(splited[1], ','))
			return (this_file(splited, ECOLFORMAT));
		if (process_vertical(game, splited) == FALSE)
			return (this_file(splited, NULL));
	}
	else
	{
		if (process_coordinates(game, splited) == FALSE)
			return (this_file(splited, NULL));
	}
	return (TRUE);
}

int	process_data(t_game *game, char *line)
{
	char	**splited;

	splited = u_split(line);
	if (!splited)
		return (print_error(EMALLOC));
	if (array_length(splited) == 2)
	{
		if (coord_data_process(game, splited) == FALSE)
			return (FALSE);
	}
	else if (array_length(splited) > 2)
	{
		if ((splited[0][0] == 'F' || splited[0][0] == 'C')
			&& array_length(splited) >= 3)
			return (this_file(splited, ECOLFORMAT));
		else
			return (this_file(splited, EID));
	}
	else
		return (this_file(splited, EID));
	array_free(splited);
	return (TRUE);
}
