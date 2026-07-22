/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_hex_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chehir <chehir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:02:31 by chehir            #+#    #+#             */
/*   Updated: 2025/11/17 15:59:40 by chehir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_fd(long unsigned int nb, int caps, int fd)
{
	char	*set;
	char	c;
	int		count;

	count = 0;
	if (nb >= 16)
		count = ft_puthex_fd((nb / 16), caps, fd);
	if (caps)
		set = "0123456789ABCDEF";
	else
		set = "0123456789abcdef";
	c = set[nb % 16];
	ft_putchar_fd(c, fd);
	return (count + 1);
}

int	ft_display_hex(va_list arg, int caps)
{
	unsigned int	value;

	value = va_arg(arg, unsigned int);
	return (ft_puthex_fd(value, caps, 1));
}

int	ft_display_address(va_list arg)
{
	long unsigned int	value;

	value = va_arg(arg, long unsigned int);
	if (!value)
		return (ft_putstr_fd("(nil)", 1));
	ft_putstr_fd("0x", 1);
	return (ft_puthex_fd(value, 0, 1) + 2);
}
