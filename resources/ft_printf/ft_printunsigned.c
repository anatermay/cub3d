/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:07:41 by aternero          #+#    #+#             */
/*   Updated: 2025/09/21 14:33:38 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_continueun(unsigned int nb)
{
	int	value;

	value = 0;
	if (nb >= 10)
		value = value + ft_continueun(nb / 10);
	nb = nb % 10 + '0';
	write(1, &nb, 1);
	value = value + 1;
	return (value);
}

int	ft_printunsigned(unsigned int nb)
{
	int		value;

	value = 0;
	if (nb == 2147483648)
	{
		write(1, "2147483648", 10);
		value = value + 10;
	}
	else
		value = value + ft_continueun(nb);
	return (value);
}
