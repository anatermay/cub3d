/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_process_vertical.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:16:41 by aternero          #+#    #+#             */
/*   Updated: 2025/09/10 20:18:31 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

/* static char	*number_str(char *line)
{
	char	*str;
	int		index[2];

	index[0] = 0;
	while (is_space(line[index[0]]) == TRUE)
		index[0]++;
	index[1] = index[0];
	while (ft_isdigit(line[index[0]]) == TRUE)
		index[0]++;
	str = (char *)malloc(sizeof(char) * (index[0] - index[1] + 1));
	if (!str)
	{
		print_error(EMALLOC);
		return (NULL);
	}
	index[0] = index[1];
	index[1] = 0;
	while (ft_isdigit(line[index[0]]) == TRUE)
		str[index[1]++] = line[index[0]++];
	str[index[1]] = '\0';
	return (str);
}

static int	process_line(char *line)
{
	char	*str;
	int		index;

	str = number_str(line);
	if (!str)
		return (FALSE);
	index = 0;
	while (is_space(line[index]) == TRUE)
		index++;
	while (ft_isdigit(line[index]) == TRUE)
		index++;
	if (line[index] != ',' && line[index] != '\0')
	{
		free(str);
		print_error(ECLR);
		return (FALSE);
	}
	index = ft_atoi(str);
	free(str);
	return (index);
} */

static int	fill_color_values(t_vert *vert, char **line)
{
	char	**color_parts;
	int		value[3];

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
	
	value[0] = ft_atoi(color_parts[0]);
	value[1] = ft_atoi(color_parts[1]);
	value[2] = ft_atoi(color_parts[2]);
	array_free(color_parts);
	
	if (value[0] < 0 || value[0] > 255 ||
		value[1] < 0 || value[1] > 255 ||
		value[2] < 0 || value[2] > 255)
		return (print_error(ECOLINV));
		
	vert->red = value[0];
	vert->green = value[1];
	vert->blue = value[2];
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
