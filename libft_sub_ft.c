/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_sub_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:33:00 by acastrov          #+#    #+#             */
/*   Updated: 2024/10/18 14:47:14 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"
// Writes a given string
int	ft_putstr_printf(char *s)
{
	if (!s) // We check for null string and print warning
		return ((int)write(1, "(null)", 6));
	if (*s) // We print the entire string, managing the output bites via ft_strlen
		return ((int)write(1, s, ft_strlen(s)));
	return (0);
}
// Writes an int
int	ft_putnbr_printf(int n)
{
	int	d;
	int	i;

	if (n == -2147483648) // Hardcoding MIN_INT to avoid negative to positive conflicts
	{
		return ((int)write(1, "-2147483648", 11));
	}
	i = 0;
	if (n < 0)
	{
		i += (int)write(1, "-", 1); // We manage negative numbers and convert them to positive
		n = -n;
	}
	if (n >= 10)
	{
		i += ft_putnbr_printf(n / 10); // Recursive call of putnbr_printf, so we print in the correct order
	}
	d = (n % 10) + '0'; // Conversion of int to char
	i += (int)write(1, &d, 1); // We print the modulus of 10
	return (i);
}
// Writes an unsigned int
int	ft_putuint_printf(unsigned int n) // The same as putnbr, but without negative conversion
{
	unsigned int	d;
	unsigned int	i;

	i = 0;
	if (n >= 10)
		i += ft_putuint_printf(n / 10);
	d = (n % 10) + '0';
	i += (unsigned int)write(1, &d, 1);
	return (i);
}
// Writes a hex decimal number
int	ft_hex(unsigned int n, char specifier) // We print a number in hex decimal in upper or lower casse, according to the specifier
{
	int				i; // Return value
	char			*hex_base; // Chars of hexbase

	if (specifier == 'X') // Only write in upper case if specified
		hex_base = "0123456789ABCDEF";
	else
		hex_base = "0123456789abcdef";
	i = 0;
	if (n >= 16) // Recursive call to ft_hex, with n divided by 16
		i += ft_hex(n / 16, specifier);
	i += (int)write(1, &hex_base[n % 16], 1); // We print the hex_base index position
	return (i);
}
// Writes a pointer address
int	ft_ptr(uintptr_t ptr, int flag)
{
	int		i;
	char	*hex_base;

	if (!ptr)
		return ((int)write(1, "(nil)", 5)); // Warning for null pointer
	i = 0;
	hex_base = "0123456789abcdef";
	if (flag == 1) // As we are going to call ft_ptr on recursive, we have to manage the first 0x. When we call ft_ptr from the switcher, it will print 0x just once thx to 1 flag
		i += (int)write(1, "0x", 2);
	if (ptr > 16)
		i += ft_ptr(ptr / 16, 0); // The recursive call of ft_ptr is with 0 flag, wich avoids repeating the 0x prefix
	i += (int)write(1, &hex_base[ptr % 16], 1); // We print in the hex_base
	return (i);
}
