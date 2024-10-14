/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:32:20 by acastrov          #+#    #+#             */
/*   Updated: 2024/10/14 20:36:34 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H


#include "libft/libft.h"
#include <stdarg.h>
#include <stdint.h>

// Reference to main ft_printf
int	ft_printf(char const *format, ...);

// Modified libft functions to return int, libft_sub_ft.c
int	ft_putstr_printf(char *s);
int	ft_putnbr_printf(int n);
int	ft_putuint_printf(unsigned int n);

// FT that uses hex
int	ft_hex(unsigned int n, char specifier);
int	ft_ptr(uintptr_t ptr, int flag);

#endif
