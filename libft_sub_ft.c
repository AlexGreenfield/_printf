/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_sub_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:33:00 by acastrov          #+#    #+#             */
/*   Updated: 2024/10/09 17:30:57 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "libft/libft.h"

int	ft_putchar_printf(char c)
{
	return (write(1, &c, 1));
}
int	ft_putstr_printf(char *s)
{
	if (*s)
		return(write(1, s, ft_strlen(s)));
	return (0);
}

