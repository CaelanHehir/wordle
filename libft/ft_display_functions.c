/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chehir <chehir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:01:32 by chehir            #+#    #+#             */
/*   Updated: 2025/11/17 15:59:35 by chehir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(long n)
{
	int	size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	ft_display_int(va_list arg)
{
	int	value;

	value = va_arg(arg, int);
	ft_putnbr_fd(value, 1);
	return (ft_num_len(value));
}

int	ft_display_unsigned(va_list arg)
{
	unsigned int	value;

	value = (unsigned int)va_arg(arg, unsigned int);
	ft_putnbr_fd(value, 1);
	return (ft_num_len(value));
}

int	ft_display_char(va_list arg)
{
	char	value;

	value = va_arg(arg, int);
	ft_putchar_fd(value, 1);
	return (1);
}

int	ft_display_string(va_list arg)
{
	char	*value;

	value = va_arg(arg, char *);
	if (!value)
		return (ft_putstr_fd("(null)", 1));
	return (ft_putstr_fd(value, 1));
}
