/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shawn <shawn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:23:11 by chehir            #+#    #+#             */
/*   Updated: 2025/11/11 19:40:40 by shawn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	ln;
	char		num;

	ln = n;
	if (ln < 0)
	{
		ln *= -1;
		ft_putchar_fd('-', fd);
	}
	if (ln >= 10)
		ft_putnbr_fd((ln / 10), fd);
	num = ln % 10 + '0';
	ft_putchar_fd(num, fd);
}

/* int	main()
{
	ft_putnbr_fd(123456, 1);
} */
