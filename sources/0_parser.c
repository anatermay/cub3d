/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:16:03 by aternero          #+#    #+#             */
/*   Updated: 2025/08/28 11:16:15 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

int	cub_extension(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	if (index <= 4)
		return (print_error(ECUB));
	index--;
	if (str[index] == 'b' && str[index - 1] == 'u'
		&& str[index - 2] == 'c' && str[index - 3] == '.')
		return (TRUE);
	return (print_error(ECUB));
}
