/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:22:41 by acastrov          #+#    #+#             */
/*   Updated: 2024/10/14 20:30:19 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_checker(char const *format);
static int	ft_switcher(char specifier, va_list args);
// Replicates the behavior of printf
int	ft_printf(char const *format, ...)
{
	int		i; // Counter for chars of format
	va_list	args; // We declare arg variable

	if (ft_checker(format) == 0) // If format it's null of invalid specifier, we return error
		return (-1);
	va_start(args, format); // We specified that args will be after format
	i = 0;
	while (*format) // We iterate through the string
	{
		if (*format != '%') // While not an specifier, we write as usual
		{
			i += write(1, format, 1); // In the switch we call the modified versions (they all need to return an int for char printed) with the arg definition, for example, putstring(args, char*). We need to send a fail message if theres the wrong type
			format++;
		}
		if (*format == '%') // In case we found a %, we have to call our switcher
		{
			format++;
			if (!*format)
				break ;
			i += ft_switcher(*format, args); // We add the result of the ft called by switch
			format++;
		}
	}
	va_end(args);
	return (i);
}
// Checks if there's format or if there's a invalid specifier
static int	ft_checker(char const *format)
{
	char	*set;

	if (!format) // First, we check for format
		return(0);
	set = "cspdiuxX%"; // We set our specifier set
	while (*format)
	{
		while (*format && *format != '%') // We move through the string
			format++;
		if (*format == '%') // If we find a %, we check for the next character
		{
			format++;
			if (!*format || ft_strchr(set, *format) == NULL )// If there's not a valid specifier, we print a warning and return 0
				{
					write(2, "error: invalid or incomplete format specifier", 47);
					return (0);
				}
			format++; // If the specifier is ok, me move the pointer and search again
		}
	}
	return (1);
}
// Switch ft according to specifier
static int	ft_switcher(char specifier, va_list args) // Switch to x ft accoring to its specifier
{
	int	switch_i; // We add the number of char printed from the sub_ft
	int	ch; // A int variable to cast args for %c print

	switch_i = 0;
	if (specifier == '%') // If we find other %, we write it
		return ((int)write(1, "%", 1));
	else if (specifier == 'c') // Print just one char, done casting a char from args int
		{
		ch = va_arg(args, int);
		switch_i = write(1, &ch, 1);
		}
	else if (specifier == 's') // We print a string
		switch_i = ft_putstr_printf(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i') // We threat both %d and %i as normal integers
		switch_i = ft_putnbr_printf(va_arg(args, int));
	else if (specifier == 'u') // Unsigned int
		switch_i = ft_putuint_printf(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X') // Hex numbers, note the specifier
		switch_i = ft_hex(va_arg(args, int), specifier);
	else if (specifier == 'p') // Pointer value. Note the flag value for the first call of ft_ptr to avoid repeating 0x
		switch_i += ft_ptr(va_arg(args, uintptr_t), 1);
	return (switch_i);
}
