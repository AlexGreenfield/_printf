/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:32:20 by acastrov          #+#    #+#             */
/*   Updated: 2024/10/09 18:01:49 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H


#include "libft/libft.h"
#include <stdarg.h>

// Modified libft functions to return int
int	ft_putchar_printf(char c);
int	ft_putstr_printf(char *s);
int	ft_putnbr_printf(int n);

#endif
