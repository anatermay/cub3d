/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 14:16:11 by aternero          #+#    #+#             */
/*   Updated: 2025/09/17 16:20:48 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

char	*space_strtrim(char *str)
{
	int		start;
	int		end;
	char	*trimmed;

	if (!str)
		return (NULL);
	start = 0;
	while (is_space(str[start]) == TRUE)
		start++;
	end = ft_strlen(str) - 1;
	while (end > start && is_space(str[end]) == TRUE)
		end--;
	trimmed = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!trimmed)
	{
		print_error(EMALLOC);
		return (NULL);
	}
	ft_strlcpy(trimmed, str + start, end - start + 2);
	return (trimmed);
}

int	is_space_array(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (FALSE);
	while (str[++index])
	{
		if (is_space(str[index]) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (TRUE);
	return (FALSE);
}
