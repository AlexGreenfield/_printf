/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:03:15 by acastrov          #+#    #+#             */
/*   Updated: 2024/10/09 19:29:46 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	ft_hex_lower(int n)
{
	unsigned int	nb;
	unsigned int	d;
	int				i;
	char		*hex_base;

	hex_base = "0123456789abcdef";
	i = 0;
	if (!n)
		return (0);
	if (n < 0)
	{
		i += (int)write(1, "-", 1);
		n = -n;
	}
	nb = n;
	if (nb >= 16)
		i += ft_hex_lower(nb / 16);
	d = nb % 16;
	i += (int)write(1, &hex_base[d], 1);
	return(i);
}
int	ft_hex_upper(int n)
{
	unsigned int	nb;
	unsigned int	d;
	int				i;
	char		*hex_base;

	hex_base = "0123456789ABCDEF";
	i = 0;
	if (!n)
		return (0);
	if (n < 0)
	{
		i += (int)write(1, "-", 1);
		n = -n;
	}
	nb = n;
	if (nb >= 16)
		i += ft_hex_lower(nb / 16);
	d = nb % 16;
	i += (int)write(1, &hex_base[d], 1);
	return(i);
}