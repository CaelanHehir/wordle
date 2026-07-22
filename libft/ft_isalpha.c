/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chehir <chehir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:42:02 by chehir            #+#    #+#             */
/*   Updated: 2025/11/07 18:14:58 by chehir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (c);
	return (0);
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	c;

	if (!(argc > 1))
		return (0);
	c = argv[1][0];
	printf("Input: %c\nOutput: %d", c, ft_isalpha(c));
}*/
