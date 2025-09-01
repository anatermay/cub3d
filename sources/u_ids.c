/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_ids.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:18:32 by aternero          #+#    #+#             */
/*   Updated: 2025/08/28 13:21:52 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

int	

int	is_vert(char *str)
{
	int	index;

	index = 0;
	while (is_space(str[index]))
		index++;
	while (str[index])
	{
		if (str[index] == 'F' && is_space(str[index + 1]) == TRUE)
			return (TRUE);
		else if (str[index] == 'C' && is_space(str[index + 1]) == TRUE)
			return (TRUE);
		index++;
	}
	return (FALSE);
}

int	is_coord(char *str)
{
	int	index;

	index = -1;
	while (str[++index])
	{
		if (str[index] == 'N' && str[index + 1] == '0')
			return (TRUE);
		else if (str[index] == 'S' && str[index + 1] == '0')
			return (TRUE);
		else if (str[index] == 'E' && str[index + 1] == '0')
			return (TRUE);
		else if (str[index] == 'W' && str[index + 1] == '0')
			return (TRUE);
		else if (str[index] == 'F' && is_space(str[index + 1]) == TRUE)
			return (TRUE);
		else if (str[index] == 'C' && is_space(str[index + 1]) == TRUE)
			return (TRUE);
	}
	return (FALSE);
}
