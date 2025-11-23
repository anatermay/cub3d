/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_gnl_to_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:06:20 by aternero          #+#    #+#             */
/*   Updated: 2025/09/23 18:49:51 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static char	**this_file_frees(char **file, int frees)
{
	if (frees == 0)
		free(file);
	else
	{
		print_error(EEMPTYFILE);
		if (file)
			array_free(file);
	}
	return (NULL);
}

static char	**file_content(char **file, int fd)
{
	char	*new;
	int		index;

	new = get_next_line(fd);
	index = 0;
	while (new)
	{
		file[index] = ft_strdup(new);
		if (!file[index])
		{
			close(fd);
			return (NULL);
		}
		index++;
		free(new);
		new = get_next_line(fd);
	}
	file[index] = NULL;
	close(fd);
	return (file);
}

static int	file_dimensions(int fd)
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

static int	open_fd(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd <= 0)
		return (print_error(EOPEN));
	return (fd);
}

char	**map_file_content(char *str)
{
	char	**file;
	int		fd;

	fd = open_fd(str);
	if (fd == FALSE)
		return (NULL);
	file = (char **)malloc((file_dimensions(fd) + 1) * sizeof(char *));
	if (!file)
	{
		print_error(EMALLOC);
		return (NULL);
	}
	fd = open_fd(str);
	if (fd == FALSE)
		return (this_file_frees(file, 0));
	file = file_content(file, fd);
	if (!file || !file[0])
		return (this_file_frees(file, 1));
	return (file);
}
