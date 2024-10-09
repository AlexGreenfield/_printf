/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:22:41 by acastrov          #+#    #+#             */
/*   Updated: 2024/10/09 18:18:46 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include <stdio.h> // REMOVE

static int	ft_switcher(char specifier, va_list args);

int	ft_printf(char const *format, ...)
{
	va_list	args; // We declare arg variable
	int	i; // Counter for chars of format

	if (!format)
		return (0);
	va_start(args, format); // We specified that args will be after format
	i = 0;
	while (*format) // We iterate through the string
	{
		if(*format != '%') // While not an specifier, we write as usual
		{
			i += ft_putchar_printf(*format); // In the switch we call the modified versions (they all need to return an int for char printed) with the arg definition, for example, putstring(args, char*). We nned to send a fail message if theres the wrong type
			format++;
		}
		if (*format == '%') // In case we found a %, we have to call our switcher
		{
			format++;
			if(!*format)
				break;
			i += ft_switcher(*format, args); // We add the result of the ft called by switch
			format++;
		}
	}
	va_end(args);
	return (i);
}
static int	ft_switcher(char specifier, va_list args) // Switch to x ft accoring to its specifier
{
	int	switch_i;

	switch_i = 0;
	if (specifier == '%') // If we find other %, we write it
		return(write(1, "%", 1));
	else if (specifier == 'c') // If specifier it's c, we pass the argument of the list as a char (int ASCII Value)
		switch_i = ft_putchar_printf(va_arg(args, int));
	else if (specifier == 's')
		switch_i = ft_putstr_printf(va_arg(args, char *)); // Call to pustr_printf
	else if (specifier == 'd')
		switch_i = ft_putnbr_printf(va_arg(args, int));
	return (switch_i);
}

int	main(void)
{
	printf("\nMy numero de caracteres es %d", ft_printf("This is a char: %c\nan string: %s\na int: %d\na %% symbol\nand a break%", 'a', "testing string", 3891281));
	return (0);
}
