/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:03:15 by acastrov          #+#    #+#             */
/*   Updated: 2024/10/09 21:21:59 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	ft_hex(int n, char specifier)
{
	unsigned int	nb;
	unsigned int	d;
	int				i;
	char		*hex_base;

	if (specifier == 'x')
		hex_base = "0123456789abcdef";
	else
		hex_base = "0123456789ABCDEF";
	i = 0;
	if (n < 0)
	{
		i += (int)write(1, "-", 1);
		n = -n;
	}
	nb = n;
	if (nb >= 16)
		i += ft_hex(nb / 16, specifier);
	d = nb % 16;
	i += (int)write(1, &hex_base[d], 1);
	return(i);
}

int	ft_ptr(void *ptr)
{
	uintptr_t		n;
	unsigned int	d;
	int				i;
	char			*hex_base;

	if (!ptr)
		return (0);
	n = (uintptr_t)ptr;
	i = 0;
	hex_base = "0123456789abcdef";
	i += (int)write(1, "0x", 2);
	while (n >= 16)
	{
		d = n % 16;
		i += (int)write(1, &hex_base[d], 1);
		n = n / 16;
	}
	d = n % 16;
	i += (int)write(1, &hex_base[d], 1);
	return(i);
}
