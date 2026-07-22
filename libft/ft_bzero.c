/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chehir <chehir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:34:40 by chehir            #+#    #+#             */
/*   Updated: 2025/11/07 20:39:38 by chehir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*cast;

	cast = s;
	while (n--)
		*cast++ = '\0';
}

/* #include <stdio.h>

 int	main()
{
	char *str = "Hello";
	printf("%s\n", str);
	ft_bzero(&str, 5);
	printf("%s\n", str);
} */
