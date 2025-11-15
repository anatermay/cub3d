/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_process_vertical.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:16:41 by aternero          #+#    #+#             */
/*   Updated: 2025/11/13 20:41:00 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static int	check_color(char *str)
{
	int	index;
	int	nbr;

	index = -1;
	while (str[++index])
	{
		if (is_space(str[index]) == FALSE
			&& ft_isdigit(str[index]) == FALSE)
		{
			print_error(ECLR);
			return (-1);
		}
	}
	nbr = ft_atoi(str);
	if (nbr < 0 || nbr > 255)
	{
		print_error(ECLR);
		return (-1);
	}
	return (nbr);
}

static int	fill_color_values(t_vert *vert, char **line)
{
	char	**color_parts;

	if (vert->red != -1 || vert->green != -1 || vert->blue != -1)
		return (print_error(ECOLDUP));
	color_parts = ft_split(line[1], ',');
	if (!color_parts)
		return (print_error(EMALLOC));
	if (array_length(color_parts) != 3)
	{
		array_free(color_parts);
		return (print_error(ECOLMISSING));
	}
	vert->red = check_color(color_parts[0]);
	vert->green = check_color(color_parts[1]);
	vert->blue = check_color(color_parts[2]);
	if (vert->red == -1 || vert->green == -1 || vert->blue == -1)
		return (FALSE);
	array_free(color_parts);
	return (TRUE);
}

int	process_vertical(t_game *game, char **line)
{
	int	index;

	index = 0;
	while (is_space(line[0][index]) == TRUE)
		index++;
	if (is_vert(line[0]) == F_NBR)
		return (fill_color_values(game->floor, line));
	else if (is_vert(line[0]) == C_NBR)
		return (fill_color_values(game->ceil, line));
	else
		return (print_error(EINVALIDID));
	return (TRUE);
}
