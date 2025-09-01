/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_space.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 14:16:11 by aternero          #+#    #+#             */
/*   Updated: 2025/09/01 18:20:49 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

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
