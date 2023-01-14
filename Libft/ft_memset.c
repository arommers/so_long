/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 09:22:49 by arommers      #+#    #+#                 */
/*   Updated: 2022/11/05 10:27:21 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	d;
	size_t			i;

	str = (unsigned char *)b;
	d = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		str[i] = c;
			i++;
	}
	return (b);
}

/*int	main(void)
{
	char	str[] = "jovanka";
	printf("%s\n", ft_memset(str, 'X', 5));
	printf("%s\n", memset(str, 'X', 5));
	return (0);
}*/