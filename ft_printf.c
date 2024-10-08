/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:22:41 by acastrov          #+#    #+#             */
/*   Updated: 2024/10/08 21:22:45 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	ft_switcher(char specifier, va_list args);

int	ft_putchar_printf(char c)
{
	return (write(1, &c, 1));
}
int	ft_printf(char const *format, ...)
{
	va_list	args; // We declare arg variable
	int	format_i; // Counter for chars of format
	int	switch_i; // Counter for chars resulting of using subft adns specifiers

	if (!format)
		return (0);
	va_start(args, format); // We specified that args will be after format
	format_i = 0;
	switch_i = 0;
	while (format[format_i] != '\0') // We iterate through the string
	{
		if(format[format_i] != '%') // While not an specifier, we write as usual
			format_i += ft_putchar_printf(format[format_i]); // In the switch we call the modified versions (they all need to return an int for char printed) with the arg definition, for example, putstring(args, char*). We nned to send a fail message if theres the wrong type
		if (format[format_i] == '%') // In case we found a %, we have to call our switcher
		{
			format_i++; // We need tocheck how to iterate thorugh the string without increasing i
			switch_i += ft_switcher(format[format_i], args); // Check if i iterates after operation, also check for null
		}
	}
	va_end(args);
	return (format_i + switch_i);
}
int	ft_switcher(char specifier, va_list args) // Switch to x ft accoring to its specifier
{
	int	switch_i;

	switch_i = 0;
	if (specifier == '%') // If we find other %, we write it
		return(write(1, "%", 1));
	if (specifier == 'c') // If specifier it's c, we pass the argument of the list as a char
		switch_i = ft_putchar_printf(va_arg(args, int));
	return (switch_i);
}

int	main(void)
{
	ft_printf("This is a string%c", "A");
	return (0);
}
