/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:03:15 by acastrov          #+#    #+#             */
/*   Updated: 2024/10/10 19:32:08 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
// We can acomodate this two ft in sub_ft file and remove libft
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

int	ft_ptr(uintptr_t ptr)
{
	int		i;
	int		index;
	char	*hex_base;
	char	buffer[16];

	if (!ptr)
		return ((int)write(1, "(nil)", 5));
	i = 0;
	index = 0;
	hex_base = "0123456789abcdef";
	i += (int)write(1, "0x", 2);
	while (ptr > 0)
	{
		buffer[index++] = hex_base[ptr % 16];
		ptr = ptr / 16;
	}
	index--;
	while (index >= 0)
		i += (int)write(1, &buffer[index--], 1);
	return (i);
}
