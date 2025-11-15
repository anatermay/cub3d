/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_sorting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:27:13 by aternero          #+#    #+#             */
/*   Updated: 2025/11/13 18:03:24 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static int	is_map_line(char *line)
{
	int	index;
	int	is_map;
	int	chars;

	index = -1;
	chars = 0;
	is_map = 0;
	while (line[++index])
	{
		if (is_space(line[index]) == FALSE)
		{
			if (line[index] == '0' || line[index] == '1'
				|| is_position(line[index]) == TRUE)
				is_map++;
			chars++;
		}
	}
	if (is_map == chars && chars > 0)
		return (TRUE);
	return (FALSE);
}

int	sorting(t_game *game)
{
	t_file	*temp;
	int		lines;

	lines = 6;
	temp = game->file;
	while (temp && lines > 0)
	{
		if (temp->space == FALSE)
		{
			if (is_map_line(temp->line) == TRUE)
				return (print_error("File starts with a map line"));
			if (process_data(game, temp->line) == FALSE)
				return (FALSE);
			lines--;
		}
		temp = temp->next;
	}
	if (lines > 0 || !game->north->tex || !game->south->tex
		|| !game->east->tex || !game->west->tex || game->floor->red == -1
		|| game->ceil->red == -1)
		return (print_error(EMISSINGELEM));
	if (process_map(game, temp) == FALSE)
		return (FALSE);
	return (TRUE);
}
