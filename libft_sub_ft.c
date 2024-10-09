/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_sub_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:33:00 by acastrov          #+#    #+#             */
/*   Updated: 2024/10/09 19:20:00 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft_printf.h"

int	ft_putchar_printf(char c)
{
	return ((int)write(1, &c, 1));
}

int	ft_putstr_printf(char *s)
{
	if (*s)
		return ((int)write(1, s, ft_strlen(s)));
	return (0);
}

int	ft_putnbr_printf(int n)
{
	int	d;
	int	i;

	if (n == -2147483648)
	{
		return ((int)write(1, "-2147483648", 11));
	}
	i = 0;
	if (n < 0)
	{
		i += (int)write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		i += ft_putnbr_printf(n / 10);
	}
	d = (n % 10) + '0';
	i += (int)write(1, &d, 1);
	return (i);
}

int	ft_putuint_printf(unsigned int n)
{
	unsigned int	d;
	unsigned int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_putnbr_printf(n / 10);
	}
	d = (n % 10) + '0';
	i += (unsigned int)write(1, &d, 1);
	return (i);
}

