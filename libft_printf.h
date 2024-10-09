/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:32:20 by acastrov          #+#    #+#             */
/*   Updated: 2024/10/09 19:51:19 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H


#include "libft/libft.h"
#include <stdarg.h>

// Modified libft functions to return int, libft_sub_ft.c
int	ft_putchar_printf(char c);
int	ft_putstr_printf(char *s);
int	ft_putnbr_printf(int n);
int	ft_putuint_printf(unsigned int n);

// Hex ft
int	ft_hex(int n, char specifier);

#endif
