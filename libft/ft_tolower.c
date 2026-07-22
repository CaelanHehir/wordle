/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shawn <shawn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:42:02 by chehir            #+#    #+#             */
/*   Updated: 2025/11/11 16:01:23 by shawn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ((c >= 65 && c <= 90))
		c += 32;
	return (c);
}

/* #include <stdio.h>

int	main(int argc, char *argv[])
{
	char	c;

	if (!(argc > 1))
		return (0);
	c = argv[1][0];
	printf("Input: %c\nOutput: %c\n", c, ft_tolower(c));
} */
