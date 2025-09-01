/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_gnl_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:15:05 by aternero          #+#    #+#             */
/*   Updated: 2025/09/01 18:43:41 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

char	**file_content(char **file, int fd)
{
	char	*new;
	int		index;

	new = get_next_line(fd);
	index = 0;
	while (new)
	{
		file[index++] = ft_strdup(new);
		free(new);
		new = get_next_line(fd);
	}
	file[index] = NULL;
	close(fd);
	return (file);
}

int	file_dimensions(int fd)
{
	char	*new;
	int		count;

	new = get_next_line(fd);
	count = 0;
	while (new)
	{
		count++;
		free(new);
		new = get_next_line(fd);
	}
	close (fd);
	return (count);
}
